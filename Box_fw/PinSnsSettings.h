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

#define BUTTONS_CNT     4   // Setup appropriately. Required for buttons handler

const PinSns_t PinSns[] = {
        // Buttons
        {GPIOA,  8, pudPullUp, ProcessButtons},
        {GPIOA, 15, pudPullUp, ProcessButtons},
        {GPIOB,  6, pudPullUp, ProcessButtons},
        {GPIOB, 15, pudPullUp, ProcessButtons},
};
#define PIN_SNS_CNT     countof(PinSns)

#endif /* PINSNSSETTINGS_H_ */
