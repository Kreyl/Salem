/*
 * File:   main.cpp
 * Author: Kreyl
 * Project: Salem Box
 *
 * Created on Mar 22, 2015, 01:23
 */

#include <buttons.h>
#include "main.h"
#include "SimpleSensors.h"
#include "interface.h"
#include "beeper.h"
#include "Sequences.h"
#include "led.h"
#include "radio_lvl1.h"

App_t App;
Beeper_t Beeper;
LedSmooth_t Led({GPIOB, 0, TIM3, 3});
Interface_t Interface;

// Universal VirtualTimer one-shot callback
void TmrOneShotCallback(void *p) {
    chSysLockFromIsr();
    App.SignalEvtI((eventmask_t)p);
    chSysUnlockFromIsr();
}

int main(void) {
    // ==== Init Vcore & clock system ====
    SetupVCore(vcore1V5);
    Clk.UpdateFreqValues();

    // ==== Init OS ====
    halInit();
    chSysInit();

    // ==== Init Hard & Soft ====
    Uart.Init(115200);
    Uart.Printf("\rLedBand %S AHB=%u", VERSION_STRING, Clk.AHBFreqHz);

    App.InitThread();

    Lcd.Init();
    Interface.Reset();

    PinSensors.Init();
    Beeper.Init();
    Beeper.StartSequence(bsqBeepBeep);

    Led.Init();
//    Radio.Init();

    // Main cycle
    App.ITask();
}

__attribute__ ((__noreturn__))
void App_t::ITask() {
    while(true) {
        uint32_t EvtMsk = chEvtWaitAny(ALL_EVENTS);
#if 1 // ==== Buttons ====
        if(EvtMsk & EVTMSK_BUTTONS) {
            BtnEvtInfo_t EInfo;
            while(ButtonEvtBuf.Get(&EInfo) == OK) {
//                Uart.Printf("\rEinfo: %u, %u,  %A", EInfo.Type, EInfo.BtnCnt, EInfo.BtnID, EInfo.BtnCnt, '-');
//                Beeper.StartSequence(bsqButton);
                // Switch backlight on
//                Lcd.Backlight(81);
//                chVTRestart(&ITmrBacklight, MS2ST(4500), EVTMSK_BCKLT_OFF);
                // Process buttons
                switch(EInfo.BtnID[0]) {
                    case btnLTop:   // Iterate IDs
                        Led.StartSequence(lsqActivated);
                        Beeper.StartSequence(bsqActivated);
                        break;

//                    case btnLBottom: // Deadtime on/off
//                        break;

//                    case btnRTop:
//                        if(Settings.DurationActive_s < DURATION_ACTIVE_MAX_S) {
//                            Settings.DurationActive_s += 10;
//                            SettingsHasChanged = true;
//                            SaveSettings();
//                            Interface.ShowDurationActive();
//                        }
//                        break;

//                    case btnRBottom:
//                        if(Settings.DurationActive_s > DURATION_ACTIVE_MIN_S) {
//                            Settings.DurationActive_s -= 10;
//                            SettingsHasChanged = true;
//                            SaveSettings();
//                            Interface.ShowDurationActive();
//                        }
//                        break;

                    default: break;
                } // switch
            } // while get
        } // if buttons
#endif

#if 1 // ==== Motion sensors ====
        // Sensors on, enter Active State now
        if(EvtMsk & EVTMSK_MSNS_ON) {
            Uart.Printf("\rMSns on");
            Led.StartSequence(lsqActivated);
            Beeper.StartSequence(bsqActivated);
        }
#endif

#if 0 // ==== Radio ====
        if(EvtMsk & EVTMSK_RADIO_RX) {
            Uart.Printf("\rRadioRx %d", Radio.LastRssidB);
            RadioIsOn = true;
            Interface.ShowRadio();
            chVTRestart(&ITmrRadioTimeout, S2ST(RADIO_NOPKT_TIMEOUT_S), EVTMSK_RADIO_ON_TIMEOUT);
            IProcessLedLogic();
            // Radio RX disables Deadtime if it is on
            DeadTimeIsNow = false;
            chVTReset(&ITmrDeadTime);
        }
        if(EvtMsk & EVTMSK_RADIO_ON_TIMEOUT) {
//            Uart.Printf("\rRadioTimeout");
            RadioIsOn = false;
            Interface.ShowRadio();
            IProcessLedLogic();
        }
#endif
    } // while true
}

