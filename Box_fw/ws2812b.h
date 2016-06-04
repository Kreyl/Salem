/*
 * ws2812b.h
 *
 *  Created on: 05 ���. 2014 �.
 *      Author: Kreyl
 */

#pragma once

#include "ch.h"
#include "hal.h"
#include "kl_lib.h"
#include "color.h"
#include "uart.h"

#define LED_CNT         75   // Number of WS2812 LEDs

#define LED_DMA_MODE    DMA_PRIORITY_HIGH \
                        | STM32_DMA_CR_MSIZE_HWORD \
                        | STM32_DMA_CR_PSIZE_HWORD \
                        | STM32_DMA_CR_MINC     /* Memory pointer increase */ \
                        | STM32_DMA_CR_DIR_M2P  /* Direction is memory to peripheral */ \
                        | STM32_DMA_CR_TCIE     /* Enable Transmission Complete IRQ */

// Tx timings: bit cnt
#define SEQ_0               0b1110000000000000
#define SEQ_1               0b1111111000000000
#define SEQ_LEN             10

#define RST_W_CNT           30 // zero words to produce reset

// SPI16 Buffer (no tuning required)
#define DATA_BIT_CNT        (LED_CNT * 3 * 8 * SEQ_LEN)   // Each led has 3 channels 8 bit each
#define DATA_W_CNT          ((DATA_BIT_CNT + 15) / 16)
#define TOTAL_W_CNT         (RST_W_CNT + DATA_W_CNT + 1) // Last item is 0xFFFF, to make line IdleHi

class LedWs_t {
private:
    Spi_t ISpi {LEDWS_SPI};
    uint16_t IBuf[TOTAL_W_CNT];
    uint16_t *PBuf;
    int Indx;
    void AppendBitsMadeOfByte(uint8_t Byte);
    void AppendOnes();
    binary_semaphore_t BSemaphore;
public:
    void Init();
    // Inner use
    Color_t ICurrentClr[LED_CNT];
    void ISetCurrentColors();
    void ITmrHandlerI();
};

extern LedWs_t LedWs;
