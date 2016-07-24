/*
 * ws2812b.cpp
 *
 *  Created on: 05 апр. 2014 г.
 *      Author: Kreyl
 */

#include "ws2812b.h"
#include "evt_mask.h"
#include "main.h"

LedWs_t LedWs;

Spi_t ISpi {LEDWS_SPI};

extern "C" {
// Wrapper for Tx Completed IRQ
void LedTxcIrq(void *p, uint32_t flags) {
    dmaStreamDisable(LEDWS_DMA);
//    Uart.PrintfI("Irq\r");
}
} // "C"

void LedWs_t::Init() {
    PinSetupAlterFunc(LEDWS_GPIO, LEDWS_PIN, omPushPull, pudNone, LEDWS_SPI_AF, psHigh);
    ISpi.Setup(boMSB, cpolIdleLow, cphaFirstEdge, sbFdiv2, bitn16);
    ISpi.Enable();
    ISpi.EnableTxDma();

    chBSemObjectInit(&BSemaphore, NOT_TAKEN);
    // Clear buffer
    for(uint32_t i=0; i<RST_W_CNT; i++) IBuf[i] = 0;

    // ==== DMA ====
    dmaStreamAllocate     (LEDWS_DMA, IRQ_PRIO_LOW, LedTxcIrq, NULL);
    dmaStreamSetPeripheral(LEDWS_DMA, &LEDWS_SPI->DR);
    dmaStreamSetMode      (LEDWS_DMA, LED_DMA_MODE);
}

void LedWs_t::AppendBitsMadeOfByte(uint8_t Byte) {
    uint16_t seq;
    for(int i=0; i<8; i++) {
        seq = (Byte & 0x80)? SEQ_1 : SEQ_0;
        Byte <<= 1;
        // Append sequence
        switch(Indx) {
            case 0:
                *PBuf = seq;
                break;
            case 1:
                *PBuf |= seq >> 10;
                PBuf++;
                *PBuf = seq << 6;
                break;
            case 2:
                *PBuf |= seq >> 4;
                break;
            case 3:
                *PBuf |= seq >> 14;
                PBuf++;
                *PBuf = seq << 2;
                break;
            case 4:
                *PBuf |= seq >> 8;
                PBuf++;
                *PBuf = seq << 8;
                break;
            case 5:
                *PBuf |= seq >> 2;
                break;
            case 6:
                *PBuf |= seq >> 12;
                PBuf++;
                *PBuf = seq << 4;
                break;
            case 7:
                *PBuf |= seq >> 6;
                PBuf++;
                break;
            default: break;
        }
        Indx++;
        if(Indx > 7) Indx = 0;
    } // for

}

void LedWs_t::AppendOnes() {
//    switch(Indx) {
//        case 0: *PBuf  = 0xFFFF; break;
//        case 1: *PBuf |= 0x003F; break;
//        case 2: *PBuf |= 0x0FFF; break;
//        case 3: *PBuf |= 0x0003; break;
//        case 4: *PBuf |= 0x00FF; break;
//        case 5: *PBuf |= 0x3FFF; break;
//        case 6: *PBuf |= 0x000F; break;
//        case 7: *PBuf |= 0x03FF; break;
//        default: break;
//    }
    PBuf++;
    *PBuf = 0;
//    while(PBuf < &IBuf[TOTAL_W_CNT]) *PBuf++ = 0xFFFF;
}

void LedWs_t::ISetCurrentColors() {
//    if(chBSemWait(&BSemaphore) != MSG_OK) return;
    // Fill bit buffer
    PBuf = &IBuf[RST_W_CNT];    // Do not touch first "reset" bits
    Indx = 0;
    for(uint32_t i=0; i<LED_CNT; i++) {
        AppendBitsMadeOfByte(ICurrentClr[i].G);
        AppendBitsMadeOfByte(ICurrentClr[i].R);
        AppendBitsMadeOfByte(ICurrentClr[i].B);
    }
    AppendOnes();

//    Uart.Printf("\r");
//    for(int i = RST_W_CNT; i<TOTAL_W_CNT; i++) Uart.Printf("%04X\r", IBuf[i]);

    // Start transmission
    dmaStreamSetMemory0(LEDWS_DMA, IBuf);
    dmaStreamSetTransactionSize(LEDWS_DMA, TOTAL_W_CNT);
    dmaStreamSetMode(LEDWS_DMA, LED_DMA_MODE);
    dmaStreamEnable(LEDWS_DMA);
//    chBSemSignal(&BSemaphore);
}
