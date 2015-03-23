/*
 * keys.cpp
 *
 *  Created on: 07.02.2013
 *      Author: kreyl
 */

#include <buttons.h>
#include "ch.h"
#include "evt_mask.h"
#include "SimpleSensors.h"
#include "uart.h"

Btns_t Btns;

// ==== Inner use ====
#if BTN_LONGPRESS
//static bool IsRepeating[BUTTONS_CNT], IsLongPress[BUTTONS_CNT];
#endif
//static systime_t RepeatTimer, LongPressTimer;
#if BTN_COMBO
    bool IsCombo;
#endif
//static void AddEvtToQueue(BtnEvtInfo_t Evt);
//static void AddEvtToQueue(BtnEvt_t AType, uint8_t KeyIndx);

// ==== Postprocessor for PinSns ====
void ProcessButtons(void *p, uint32_t Len) {
    PinSnsState_t *State = (PinSnsState_t*)p;
//    Uart.Printf("\r%A", p, Len, ' ');
}

/*

void Keys_t::ProcessKeysState(bool *PCurrentState) {
//    Uart.Printf("\r%A", PCurrentState, KEYS_CNT, ' ');
    // Iterate keys
    for(uint8_t i=0; i<KEYS_CNT; i++) {
        bool PressedNow = KeyIsPressed(PCurrentState[i]);

        // ==== Key Press ====
        if(PressedNow and !Key[i].IsPressed) {
            Key[i].IsPressed = true;
#if KEY_LONGPRESS
            Key[i].IsLongPress = false;
            Key[i].IsRepeating = false;
#endif
            KeyEvtInfo_t IEvt;
            IEvt.KeysCnt = 0;
            // Check if combo
            for(uint8_t j=0; j<KEYS_CNT; j++) {
                if(Key[j].IsPressed) {
                    IEvt.KeyID[IEvt.KeysCnt] = j;
                    IEvt.KeysCnt++;
                    if((j != i) and !IsCombo) {
                        IsCombo = true;
                        AddEvtToQueue(keCancel, j);
                    }
                }
            } // for j
            if(IEvt.KeysCnt == 1) {   // Single key pressed, no combo
                IsCombo = false;
                IEvt.Type = kePress;
#if KEY_LONGPRESS   // Reset timers
                RepeatTimer = chTimeNow();
                LongPressTimer = chTimeNow();
#endif
            }
            else IEvt.Type = keCombo;
            AddEvtToQueue(IEvt);
        } // if became pressed

        // ==== Key Release ====
        else if(!PressedNow and Key[i].IsPressed) {
            Key[i].IsPressed = false;
#if KEY_COMBO
            // Check if combo completely released
            if(IsCombo) {
                IsCombo = false;
                for(uint8_t j=0; j<KEYS_CNT; j++) {
                    if(Key[j].IsPressed) {
                        IsCombo = true;
                        break;
                    }
                }
            } // if combo
#endif
#if KEY_RELEASE // Send evt if not combo
            else AddEvtToQueue(keRelease, i);
#endif
        }

#if KEY_LONGPRESS // ==== Long Press ====
        else if(PressedNow and Key[i].IsPressed and !IsCombo) {
            // Check if long press
            if(!Key[i].IsLongPress) {
                if(TimeElapsed(&LongPressTimer, KEY_LONGPRESS_DELAY_MS)) {
                    Key[i].IsLongPress = true;
                    AddEvtToQueue(keLongPress, i);
                }
            }
            // Check if repeat
            if(!Key[i].IsRepeating) {
                if(TimeElapsed(&RepeatTimer, KEYS_DELAY_BEFORE_REPEAT_MS)) {
                    Key[i].IsRepeating = true;
                    AddEvtToQueue(keRepeat, i);
                }
            }
            else {
                if(TimeElapsed(&RepeatTimer, KEY_REPEAT_PERIOD_MS)) {
                    AddEvtToQueue(keRepeat, i);
                }
            }
        } // if still pressed
#endif
    } // for i
}

void Keys_t::AddEvtToQueue(KeyEvtInfo_t Evt) {
//    Uart.Printf("EvtType=%u; Keys: ", Evt.Type);
//    for(uint8_t i=0; i<Evt.NKeys; i++) Uart.Printf("%u ", Evt.KeyID[i]);
//    Uart.Printf("\r\n");
    if(App.PThread == nullptr) return;
    chSysLock();
    EvtBuf.Put(&Evt);
    chEvtSignalI(App.PThread, EVTMSK_KEYS);
    chSysUnlock();
}

void Keys_t::AddEvtToQueue(KeyEvt_t AType, uint8_t KeyIndx) {
    KeyEvtInfo_t IEvt;
    IEvt.Type = AType;
    IEvt.KeysCnt = 1;
    IEvt.KeyID[0] = KeyIndx;
    chSysLock();
    EvtBuf.Put(&IEvt);
    chEvtSignalI(App.PThread, EVTMSK_KEYS);
    chSysUnlock();
}
*/
