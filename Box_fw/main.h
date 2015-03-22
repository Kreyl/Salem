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

enum BoxState_t {bsIdle, bsActive};

class App_t {
private:
    BoxState_t State;
public:
    Thread *PThread;
    void SignalEvt(eventmask_t Evt) {
        chSysLock();
        chEvtSignalI(PThread, Evt);
        chSysUnlock();
    }
    // Inner use
    void ITask();
    App_t(): State(bsIdle), PThread(nullptr) {}
};

extern App_t App;


#endif /* MAIN_H_ */
