/*
 * keys.h
 *
 *  Created on: 07.02.2013
 *      Author: kreyl
 */

#ifndef KEYS_H_
#define KEYS_H_

#include "hal.h"
#ifdef STM32F2XX
#include "kl_lib_f2xx.h"
#elif defined STM32L1XX_MD || defined STM32L1XX_HD
#include "kl_lib_L15x.h"
#endif
#include "kl_buf.h"

#include "SnsPins.h"

// Select required events. KeyPress is a must.
#define KEY_RELEASE     FALSE
#define KEY_LONGPRESS   TRUE
#define KEY_COMBO       FALSE

#define KEY_REPEAT_PERIOD_MS        180
#define KEY_LONGPRESS_DELAY_MS      603
#define KEYS_DELAY_BEFORE_REPEAT_MS (KEY_REPEAT_PERIOD_MS + KEY_LONGPRESS_DELAY_MS)

#define KEYS_EVT_Q_LEN              7   // Length of events' query

enum KeyName_t {keyRTop=0, keyRBottom=1, keyLTop=2, keyLBottom=3};

// Key status
struct Key_t {
    bool IsPressed
#if KEY_LONGPRESS
    , IsRepeating, IsLongPress
#endif
    ;
};

// KeyEvent: contains info about event type, count of participating keys and array with key IDs
enum KeyEvt_t {kePress, keLongPress, keRelease, keCancel, keRepeat, keCombo};
struct KeyEvtInfo_t {
    KeyEvt_t Type;
    uint8_t KeysCnt;
    uint8_t KeyID[KEYS_CNT];
};

class Keys_t {
private:
    Key_t Key[KEYS_CNT];
    systime_t RepeatTimer, LongPressTimer;
    bool IsCombo;
    void AddEvtToQueue(KeyEvtInfo_t Evt);
    void AddEvtToQueue(KeyEvt_t AType, uint8_t KeyIndx);
public:
    void ProcessKeysState(bool *PCurrentState);
    // Events
    CircBuf_t<KeyEvtInfo_t, KEYS_EVT_Q_LEN> EvtBuf;
};

extern Keys_t Keys;

#endif /* KEYS_H_ */
