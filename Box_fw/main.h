/*
 * main.h
 *
 *  Created on: 21 дек. 2014 г.
 *      Author: Kreyl
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "kl_lib_L15x.h"
#include "ch.h"
#include "hal.h"
#include "clocking_L1xx.h"
#include "evt_mask.h"
#include "uart.h"

struct Settings_t {
    uint32_t DurationActive_s;
    uint32_t ID;
};
#define EE_ADDR     0
#define EE_PTR      ((Settings_t*)(EEPROM_BASE_ADDR + EE_ADDR))

#define DURATION_ACTIVE_MIN     10
#define DURATION_ACTIVE_MAX     9990
#define DURATION_ACTIVE_DEFAULT 300

class App_t {
private:
    VirtualTimer ITmrSaving, ITmrReturnToIdle;
    void ISaveSettings();    // Really save settings
public:
    Thread *PThread;
    Settings_t Settings;
    void LoadSettings();
    void SaveSettings();    // Prepare to save settings
    void SignalEvt(eventmask_t Evt) {
        chSysLock();
        chEvtSignalI(PThread, Evt);
        chSysUnlock();
    }
    // Inner use
    void ITask();
//    App_t(): State(bsIdle), PThread(nullptr) {}
};

extern App_t App;


#endif /* MAIN_H_ */
