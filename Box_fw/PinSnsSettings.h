/*
 * SnsPins.h
 *
 *  Created on: 17 ���. 2015 �.
 *      Author: Kreyl
 */

/* ================ Documentation =================
 * There are several (may be 1) groups of sensors (say, buttons and USB connection).
 * There is GPIO and Pin data for every sensor.
 *
 */


#ifndef PINSNSSETTINGS_H_
#define PINSNSSETTINGS_H_

#include "ch.h"
#include "hal.h"
#include "kl_lib.h"
#include "main.h" // App.thd here
#include "interface.h"
#include "evt_mask.h"

#define SNS_POLL_PERIOD_MS  72

enum PinSnsState_t {pssLo, pssHi, pssRising, pssFalling};
typedef void (*ftVoidPSnsStLen)(PinSnsState_t *PState, uint32_t Len);

// Single pin setup data
struct PinSns_t {
    GPIO_TypeDef *PGpio;
    uint16_t Pin;
    PinPullUpDown_t Pud;
    ftVoidPSnsStLen Postprocessor;
    void Init() const { PinSetupIn(PGpio, Pin, Pud); }
    void Off()  const { PinSetupAnalog(PGpio, Pin);  }
    bool IsHi() const { return PinIsSet(PGpio, Pin); }
};

// ================================= Settings ==================================
// Buttons handler
extern void ProcessButtons(PinSnsState_t *PState, uint32_t Len);

// Motion sensors handler
static void ProcessMSensors(PinSnsState_t *PState, uint32_t Len) {
    // Display status
    if(PState[0] == pssRising) Interface.ShowMSns1(1);
    else if(PState[0] == pssFalling) Interface.ShowMSns1(0);
    if(PState[1] == pssRising) Interface.ShowMSns2(1);
    else if(PState[1] == pssFalling) Interface.ShowMSns2(0);

    // Send ON evt if any is rising
    if(PState[0] == pssRising or PState[1] == pssRising) App.SignalEvt(EVTMSK_MSNS_ON);
    // Send OFF evt if one is falling and other is low
    else if((PState[0] == pssFalling and PState[1] == pssLo) or
            (PState[0] == pssLo      and PState[1] == pssFalling) or
            (PState[0] == pssFalling and PState[1] == pssFalling)
            ) {
        App.SignalEvt(EVTMSK_MSNS_OFF);
    }
}

#define BUTTONS_CNT     4   // Setup appropriately. Required for buttons handler

const PinSns_t PinSns[] = {
        // Buttons
        {GPIOA,  8, pudPullUp, ProcessButtons},
        {GPIOA, 15, pudPullUp, ProcessButtons},
        {GPIOB,  6, pudPullUp, ProcessButtons},
        {GPIOB, 15, pudPullUp, ProcessButtons},
        // Motion sensors
        {GPIOB,  2, pudPullDown, ProcessMSensors},
        {GPIOB,  5, pudPullDown, ProcessMSensors},
};
#define PIN_SNS_CNT     countof(PinSns)

#endif /* PINSNSSETTINGS_H_ */
