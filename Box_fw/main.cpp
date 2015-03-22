/*
 * File:   main.cpp
 * Author: Kreyl
 * Project: Salem Box
 *
 * Created on Mar 22, 2015, 01:23
 */

#include "main.h"
#include "SimpleSensors.h"
#include "keys.h"
#include "interface.h"
#include "beeper.h"
#include "Sequences.h"
#include "led.h"

App_t App;
Beeper_t Beeper;
LedSmooth_t Led({GPIOB, 4, TIM3, 1});

#if 1 // ============================ Timers ===================================

#endif

int main(void) {
    // ==== Init Vcore & clock system ====
    SetupVCore(vcore1V5);
    Clk.UpdateFreqValues();

    // ==== Init OS ====
    halInit();
    chSysInit();

    // ==== Init Hard & Soft ====
    Uart.Init(115200);
    Uart.Printf("\rSalemBox AHB=%u", Clk.AHBFreqHz);

    App.PThread = chThdSelf();

    Lcd.Init();
    Lcd.Backlight(50);
    Lcd.Printf(1,1,"Aiya Feanaro!");

    Sensors.Init();
    Beeper.Init();
    Beeper.StartSequence(bsqBeepBeep);

    Led.Init();
    Led.StartSequence(lsqFadeIn);

    // Main cycle
    App.ITask();
}

__attribute__ ((__noreturn__))
void App_t::ITask() {
    while(true) {
        uint32_t EvtMsk = chEvtWaitAny(ALL_EVENTS);
#if 1 // ==== Keys ====
        if(EvtMsk & EVTMSK_KEYS) {
            KeyEvtInfo_t EInfo;
            while(Keys.EvtBuf.Get(&EInfo) == OK) {
                Uart.Printf("\rEinfo: %u, %u, %u", EInfo.Type, EInfo.KeysCnt, EInfo.KeyID[0]);
                if(EInfo.Type == kePress or EInfo.Type == keRepeat) {
                    Beeper.StartSequence(bsqButton);
                    switch(EInfo.KeyID[0]) {
                        case keyLTop:
                            SignalEvt(EVTMSK_MSNS_ON);
                            break;

                        case keyLBottom:
                            SignalEvt(EVTMSK_MSNS_ON);
                            break;

                        default: break;
                    } // switch
                } // if press
            } // while get
        } // if keys
#endif

#if 1 // ==== Motion sensors ====
        if(EvtMsk & EVTMSK_MSNS_ON) {

        }
        if(EvtMsk & EVTMSK_MSNS_OFF) {

        }
#endif
    } // while true
}
