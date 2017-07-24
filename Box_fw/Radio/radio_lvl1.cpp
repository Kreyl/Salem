/*
 * radio_lvl1.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: kreyl
 */

#include "radio_lvl1.h"
#include "evt_mask.h"
#include "main.h"
#include "cc1101.h"
#include "uart.h"
#include "interface.h"

#define DBG_PINS

#ifdef DBG_PINS
#define DBG_GPIO1   GPIOC
#define DBG_PIN1    15
#define DBG1_SET()  PinSet(DBG_GPIO1, DBG_PIN1)
#define DBG1_CLR()  PinClear(DBG_GPIO1, DBG_PIN1)
#endif

rLevel1_t Radio;

#if 1 // ================================ Task =================================
static WORKING_AREA(warLvl1Thread, 256);
static void rLvl1Thread(void *arg) {
    chRegSetThreadName("rLvl1");
    Radio.ITask();
}

__attribute__((__noreturn__)) void rLevel1_t::ITask() {
    while(true) {
        if(SetupState == setstNotSent) {
            SetupState = setstSending;
            Interface.ShowSetupState();
            // Send setup data
            for(int i=0; i<7; i++) {
                Pkt.Percent = App.Settings.Percent;
                Pkt.TestWord = TEST_WORD;
                CC.TransmitSync((void*)&Pkt);
                // Receive reply
                uint8_t RxRslt = CC.ReceiveSync(RX_T_MS, &Pkt, &LastRssidB);
                if(RxRslt == OK and Pkt.TestWord == TEST_WORD) {
                    SetupState = setstAccepted;
                    Interface.ShowSetupState();
                    break;
                }
                else chThdSleepMilliseconds(45);
            } // for
            if(SetupState != setstAccepted) {   // Transmission failed
                SetupState = setstNotSent;
                Interface.ShowSetupState();
                CC.EnterPwrDown();
                chThdSleepMilliseconds(1800);
            }
        } // if not sent
        else {
            CC.EnterPwrDown();
            chThdSleepMilliseconds(360);
        }
    } // while true
}
#endif // task

#if 1 // ============================
void rLevel1_t::Init() {
    // Init radioIC
    if(CC.Init() == OK) {
        CC.SetTxPower(CC_Pwr0dBm);
        CC.SetPktSize(RPKT_LEN);
        CC.SetChannel(7);
        // Thread
        chThdCreateStatic(warLvl1Thread, sizeof(warLvl1Thread), HIGHPRIO, (tfunc_t)rLvl1Thread, NULL);
#ifdef DBG_PINS
        PinSetupOut(DBG_GPIO1, DBG_PIN1, omPushPull);
#endif
//        Uart.Printf("\rCC init OK");
    }
    else {
        Uart.Printf("\rCC init error");
        Interface.Error("  Radio Failure ");
    }
}
#endif
