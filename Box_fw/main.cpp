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
Interface_t Interface;
SetupState_t SetupState;

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
    Uart.Printf("\rStarPath %S AHB=%u\r", VERSION_STRING, Clk.AHBFreqHz);

    App.InitThread();

    Lcd.Init();
    App.LoadSettings();
    Interface.Reset();

    // Display "Not sent"
    SetupState = setstNotSent;
    Interface.ShowSetupState();
    SetupState = setstAccepted; // Do not start transmission immideately

    PinSensors.Init();
    Beeper.Init();
    Beeper.StartSequence(bsqBeepBeep);

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
                // Switch backlight on
                Lcd.Backlight(81);
                chVTRestart(&ITmrBacklight, MS2ST(4500), EVTMSK_BCKLT_OFF);
                // Process buttons
                switch(EInfo.BtnID[0]) {
                    case btnLTop:   // Increase percent
                        if(Settings.Percent < Percent_MAX) Settings.Percent++;
                        SettingsHasChanged = true;
                        SaveSettings();
                        Interface.ShowPercent();
                        break;

                    case btnLBottom: // Deadtime on/off
                        if(Settings.Percent > 0) Settings.Percent--;
                        SettingsHasChanged = true;
                        SaveSettings();
                        Interface.ShowPercent();
                        break;

                    default: break;
                } // switch
            } // while get
        } // if buttons
#endif

#if 1 // ==== Saving settings ====
        if(EvtMsk & EVTMSK_SAVE) { ISaveSettingsReally(); }
#endif

#if 1 // ==== Backlight off ====
        if(EvtMsk & EVTMSK_BCKLT_OFF) { Lcd.Backlight(0); }
#endif
    } // while true
}

#if 1 // ===================== Load/save settings ==============================
void App_t::LoadSettings() {
    if(EE_PTR->Percent < Percent_MIN or EE_PTR->Percent > Percent_MAX) Settings.Percent = Percent_DEFAULT;
    else Settings.Percent = EE_PTR->Percent;
    SettingsHasChanged = false;
}

void App_t::ISaveSettingsReally() {
    // Save settings to EE
    Flash_t::UnlockEE();
    chSysLock();
    uint8_t r = OK;
    uint32_t *Src = (uint32_t*)&Settings;
    uint32_t *Dst = (uint32_t*)EE_PTR;
    for(uint32_t i=0; i<SETTINGS_SZ32; i++) {
        r = Flash_t::WaitForLastOperation();
        if(r != OK) break;
        *Dst++ = *Src++;
    }
    Flash_t::LockEE();
    chSysUnlock();
    if(r == OK) {
        Uart.Printf("\rSettings saved");
        SettingsHasChanged = false;
        Interface.ShowPercent();
    }
    else {
        Uart.Printf("\rSettings saving failure");
        Interface.Error("Save failure");
    }
    // Send new settings
    SetupState = setstNotSent;
}
#endif
