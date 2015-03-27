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
LedSmooth_t Led({GPIOB, 4, TIM3, 1});
Interface_t Interface;

#if 1 // ============================ Timers ===================================
// Universal VirtualTimer callback
void TmrGeneralCallback(void *p) {
    chSysLockFromIsr();
    chEvtSignalI(App.PThread, (eventmask_t)p);
    chSysUnlockFromIsr();
}
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
    App.LoadSettings();
    Interface.Reset();

    PinSensors.Init();
    Beeper.Init();
    Beeper.StartSequence(bsqBeepBeep);

    Led.Init();
    Radio.Init();

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
                Beeper.StartSequence(bsqButton);
                switch(EInfo.BtnID[0]) {
                    case btnLTop:
                        if(Settings.ID < ID_MAX) {
                            Settings.ID++;
                            SaveSettings();
                            Interface.ShowID();
                        }
                        break;

                    case btnLBottom:
                        if(Settings.ID > ID_MIN) {
                            Settings.ID--;
                            SaveSettings();
                            Interface.ShowID();
                        }
                        break;

                    case btnRTop:
                        if(Settings.DurationActive_s < DURATION_ACTIVE_MAX) {
                            Settings.DurationActive_s += 10;
                            SaveSettings();
                            Interface.ShowDurationActive();
                        }
                        break;

                    case btnRBottom:
                        if(Settings.DurationActive_s > DURATION_ACTIVE_MIN) {
                            Settings.DurationActive_s -= 10;
                            SaveSettings();
                            Interface.ShowDurationActive();
                        }
                        break;

                    default: break;
                } // switch
            } // while get
        } // if buttons
#endif

#if 1 // ==== Motion sensors ====
        // Sensors on, enter Active State now
        if(EvtMsk & EVTMSK_MSNS_ON) {
            Uart.Printf("\rMSns on");
            Led.StartSequence(lsqEnterActive);
            chVTReset(&ITmrReturnToIdle);   // Do not enter idle if was preparing
        }
        // Sensors off, wait DurationActive_s before entering Idle State
        if(EvtMsk & EVTMSK_MSNS_OFF) {
            Uart.Printf("\rMSns off");
            // Restart ReturnToIdle timer
            chVTRestart(&ITmrReturnToIdle, S2ST(Settings.DurationActive_s), TmrGeneralCallback, (void*)EVTMSK_ENTER_IDLE);
        }
#endif

#if 1 // ==== Time to enter Idle ====
        if(EvtMsk & EVTMSK_ENTER_IDLE) {
            chVTReset(&ITmrReturnToIdle);
            Led.StartSequence(lsqEnterIdle);
        }
#endif

#if 1 // ==== Saving settings ====
        if(EvtMsk & EVTMSK_SAVE) { ISaveSettings(); }
#endif
    } // while true
}

void App_t::LoadSettings() {
    if(EE_PTR->DurationActive_s < DURATION_ACTIVE_MIN or EE_PTR->DurationActive_s > DURATION_ACTIVE_MAX) {
        Settings.DurationActive_s = DURATION_ACTIVE_DEFAULT;
    }
    else Settings.DurationActive_s = EE_PTR->DurationActive_s;
    if(EE_PTR->ID < ID_MIN or EE_PTR->ID > ID_MAX) Settings.ID = ID_DEFAULT;
    else Settings.ID = EE_PTR->ID;
}

void App_t::SaveSettings() {
    chSysLock();
    if(chVTIsArmedI(&ITmrSaving)) chVTResetI(&ITmrSaving);  // Reset timer
    chVTSetI(&ITmrSaving, MS2ST(4500), TmrGeneralCallback, (void*)EVTMSK_SAVE);
    chSysUnlock();
}

void App_t::ISaveSettings() {
    Flash_t::UnlockEE();
    chSysLock();
    uint8_t r = Flash_t::WaitForLastOperation();
    if(r == OK) {
        EE_PTR->DurationActive_s = Settings.DurationActive_s;
        r = Flash_t::WaitForLastOperation();
        if(r == OK) {
            EE_PTR->ID = Settings.ID;
            r = Flash_t::WaitForLastOperation();
        }
    }
    Flash_t::LockEE();
    chSysUnlock();
    if(r == OK) Uart.Printf("\rSettings saved");
    else Uart.Printf("\rSettings saving failure");
}

