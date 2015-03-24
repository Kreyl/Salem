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
                        SignalEvt(EVTMSK_MSNS_ON);
                        break;

                    case btnLBottom:
                        SignalEvt(EVTMSK_MSNS_OFF);
                        break;

                    case btnRTop:
                        if(Settings.DurationActive_s < DURATION_ACTIVE_MAX) Settings.DurationActive_s += 10;
                        SaveSettings();
                        Interface.ShowDurationActive();
                        break;

                    case btnRBottom:
                        if(Settings.DurationActive_s > DURATION_ACTIVE_MIN) Settings.DurationActive_s -= 10;
                        SaveSettings();
                        Interface.ShowDurationActive();
                        break;

                    default: break;
                } // switch
            } // while get
        } // if buttons
#endif

#if 1 // ==== Motion sensors ====
        if(EvtMsk & EVTMSK_MSNS_ON) {
            EnterActiveState();
        }
        if(EvtMsk & EVTMSK_MSNS_OFF) {
            EnterIdleState();
        }
#endif

#if 1 // ==== Saving settings ====
        if(EvtMsk & EVTMSK_SAVE) { ISaveSettings(); }
#endif
    } // while true
}


void App_t::EnterIdleState() {
    Led.StartSequence(lsqEnterIdle);
}
void App_t::EnterActiveState() {
    Led.StartSequence(lsqEnterActive);
}


void App_t::LoadSettings() {
    Settings_t *p = EE_PTR;
    if(p->DurationActive_s < DURATION_ACTIVE_MIN or p->DurationActive_s > DURATION_ACTIVE_MAX) {
        // Setup defaults
        Settings.DurationActive_s = DURATION_ACTIVE_DEFAULT;
    }
    else {
        Settings.DurationActive_s = p->DurationActive_s;
    }
}

void App_t::SaveSettings() {
    chSysLock();
    if(chVTIsArmedI(&ISavingTmr)) chVTResetI(&ISavingTmr);  // Reset timer
    chVTSetI(&ISavingTmr, MS2ST(4500), TmrGeneralCallback, (void*)EVTMSK_SAVE);
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

