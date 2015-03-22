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


#ifndef SNSPINS_H_
#define SNSPINS_H_

#include "ch.h"
#include "hal.h"
#include "evt_mask.h"
#ifdef STM32F2XX
#include "kl_lib_f2xx.h"
#elif defined STM32L1XX_MD || defined STM32L1XX_HD
#include "kl_lib_L15x.h"
#endif
// Here Thread defined
#include "main.h"

#if 1 // ============================ Classes ==================================
// Single pin setup data
struct SnsData_t {
    GPIO_TypeDef *PGpio;
    uint16_t Pin;
    PinPullUpDown_t Pud;
    void Init() const { PinSetupIn(PGpio, Pin, Pud); }
    void Off()  const { PinSetupAnalog(PGpio, Pin);  }
    bool IsHi() const { return PinIsSet(PGpio, Pin); }
};

struct SnsGroup_t {
    uint32_t Cnt;
    eventmask_t EvtMskRising, EvtMskFalling;    // Events to send to App.PThread
    ftVoidPVoid pFuncPostprocessor;             // Function to call after check of group
    const SnsData_t *Pins;
    bool *WasHi;
    // Methods
    void Init() const { for(uint32_t i=0; i < Cnt; i++) Pins[i].Init(); }
    void Off()  const { for(uint32_t i=0; i < Cnt; i++) Pins[i].Off();  }
    void SignalEvtRising () const {
        chSysLock();
        chEvtSignalI(App.PThread, EvtMskRising);
        chSysUnlock();
    }
    void SignalEvtFalling() const {
        chSysLock();
        chEvtSignalI(App.PThread, EvtMskFalling);
        chSysUnlock();
    }
    void Check() const {
        for(uint32_t i=0; i < Cnt; i++) {
            if     (EvtMskRising  and  Pins[i].IsHi() and !WasHi[i]) SignalEvtRising();
            else if(EvtMskFalling and !Pins[i].IsHi() and  WasHi[i]) SignalEvtFalling();
            WasHi[i] = Pins[i].IsHi();
        } // for
        if(pFuncPostprocessor != nullptr) pFuncPostprocessor((void*)this);
    } // Check
};
#endif

// ================================= Settings ==================================

// ==== Keys group ====
// GPIOs and pins settings
const SnsData_t SnsKeyGroupData[] = {
        {GPIOA,  8, pudPullUp},  //
        {GPIOA, 15, pudPullUp},  //
        {GPIOB,  6, pudPullUp},  //
        {GPIOB, 15, pudPullUp},  //
};

// Variables etc. Change names here.
#define KEYS_CNT    countof(SnsKeyGroupData)
static bool SnsKeysWasHi[KEYS_CNT];         // Required for any group to detect edges
// Pseudo function defining what is "Key Pressed"
#define KeyIsPressed(PinIsHi)   (!PinIsHi)  // Pin is Low == Key is pressed
extern void ProcessKeyState(void *p);       // Keys handler

// Struct with variables to work with. Change reaction settings here (event etc.)
const SnsGroup_t SnsGroupKey = {
        KEYS_CNT,
        EVTMSK_NO_MASK, EVTMSK_NO_MASK,     // signal nothing
        &ProcessKeyState,                   // Keys handler
        SnsKeyGroupData,
        SnsKeysWasHi
};

// ==== Motion Sensor group ====
// GPIOs and pins settings
const SnsData_t MSnsGroupData[] = {
        {GPIOB,  2, pudPullDown},
        {GPIOB,  5, pudPullDown},
};

// Variables etc. Change names here.
#define MSNS_CNT    countof(MSnsGroupData)
static bool SnsMSnsWasHi[MSNS_CNT];         // Required for any group to detect edges

// Struct with variables to work with. Change reaction settings here (event etc.)
const SnsGroup_t SnsGroupMSns = {
        MSNS_CNT,
        EVTMSK_MSNS_ON, EVTMSK_MSNS_OFF,    // signal both
        nullptr,                            // No special post-processing
        MSnsGroupData,
        SnsMSnsWasHi
};

//// ==== USB group ====
//#define SNS_USB_CNT     1
//const SnsData_t SnsUsbData = {GPIOA,  9, pudPullDown};
//static bool UsbKeysWasHi[SNS_USB_CNT];
//
//const SnsGroup_t SnsGroupUsb = {
//        SNS_USB_CNT,
//        EVTMSK_USB_CONNECTED, EVTMSK_USB_DISCONNECTED, // Signal both
//        nullptr,
//        &SnsUsbData,
//        UsbKeysWasHi
//};

// ============================== Common data ==================================
#define SNS_POLL_PERIOD_MS  72
// Group array
const SnsGroup_t* const SnsGroups[] = {
        &SnsGroupKey,
        &SnsGroupMSns,
};
#define SNSGROUP_CNT        countof(SnsGroups)

#endif /* SNSPINS_H_ */
