/*
 * main.h
 *
 *  Created on: 15 ����. 2014 �.
 *      Author: g.kruglov
 */

#pragma once

#include "ch.h"
#include "kl_lib.h"
#include "uart.h"
#include "evt_mask.h"
#include "board.h"

// Durations

class App_t {
private:
    thread_t *PThread;
public:
    // Eternal methods
    void InitThread() { PThread = chThdGetSelfX(); }
    uint8_t GetDipSwitch();
    void SignalEvt(eventmask_t Evt) {
        chSysLock();
        chEvtSignalI(PThread, Evt);
        chSysUnlock();
    }
    void SignalEvtI(eventmask_t Evt) { chEvtSignalI(PThread, Evt); }
    void OnCmd(Shell_t *PShell);
    // Inner use
    void ITask();
};

extern App_t App;
