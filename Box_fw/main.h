/*
 * main.h
 *
 *  Created on: 21 дек. 2014 г.
 *      Author: Kreyl
 */

#pragma once

#include "kl_lib.h"
#include "ch.h"
#include "hal.h"
#include "clocking.h"
#include "evt_mask.h"
#include "uart.h"

#define VERSION_STRING  "v1"

class App_t {
private:
    Thread *PThread;
public:
    void InitThread() { PThread = chThdSelf(); }
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
