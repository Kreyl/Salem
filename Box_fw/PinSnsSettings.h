/*
 * SnsPins.h
 *
 *  Created on: 17 џэт. 2015 у.
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
#ifdef STM32F2XX
#include "kl_lib_f2xx.h"
#elif defined STM32L1XX_MD || defined STM32L1XX_HD
#include "kl_lib_L15x.h"
#endif

#define SNS_POLL_PERIOD_MS  180//72

// Single pin setup data
struct PinSns_t {
    GPIO_TypeDef *PGpio;
    uint16_t Pin;
    PinPullUpDown_t Pud;
    ftVoidPVoidLen Postprocessor;
    void Init() const { PinSetupIn(PGpio, Pin, Pud); }
    void Off()  const { PinSetupAnalog(PGpio, Pin);  }
    bool IsHi() const { return PinIsSet(PGpio, Pin); }
};

// ================================= Settings ==================================
extern void ProcessButtons(void *p, uint32_t Len);   // Buttons handler

// Motion sensors handler
static void ProcessMSensors(void *p, uint32_t Len) { }

#define BUTTONS_CNT     4       // Setup appropriately. Required for buttons handler

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
