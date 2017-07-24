/*
 * main.h
 *
 *  Created on: 21 дек. 2014 г.
 *      Author: Kreyl
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "kl_lib.h"
#include "ch.h"
#include "hal.h"
#include "clocking.h"
#include "evt_mask.h"
#include "uart.h"

#define VERSION_STRING  "v0.1"

enum SetupState_t { setstNotSent, setstSending, setstAccepted};
extern SetupState_t SetupState;

// All values must be 32bit to make things easier
struct Settings_t {
    uint32_t Percent;
};
#define SETTINGS_SZ32   (sizeof(Settings_t) / 4)
// EEPROM addresses
#define EE_ADDR     0
#define EE_PTR      (reinterpret_cast<Settings_t*>(EEPROM_BASE_ADDR + EE_ADDR))

// ==== Constants and default values ====
#define Percent_MIN             0
#define Percent_MAX             100
#define Percent_DEFAULT         100

class App_t {
private:
    VirtualTimer ITmrSaving, ITmrMSnsTimeout, ITmrRadioTimeout, ITmrBacklight, ITmrDeadTime;
    void ISaveSettingsReally();    // Really save settings
    Thread *PThread;
    void IProcessLedLogic();
    bool SettingsHasChanged;
public:
    void InitThread() { PThread = chThdSelf(); }
    Settings_t Settings;
    void LoadSettings();
    void SaveSettings() { chVTRestart(&ITmrSaving, S2ST(4), EVTMSK_SAVE); } // Prepare to save settings
    void SignalEvt(eventmask_t Evt) {
        chSysLock();
        chEvtSignalI(PThread, Evt);
        chSysUnlock();
    }
    void SignalEvtI(eventmask_t Evt) { chEvtSignalI(PThread, Evt); }
    // Inner use
    void ITask();
    friend class Interface_t;
};

extern App_t App;


#endif /* MAIN_H_ */
