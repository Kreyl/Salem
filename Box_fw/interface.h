/*
 * interface.h
 *
 *  Created on: 22 марта 2015 г.
 *      Author: Kreyl
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "lcd1200.h"
#include "main.h"

class Interface_t {
public:
    void Reset() {
        Lcd.Printf(9, 1, "Active");
        Lcd.Printf(8, 2, "Duration");
        ShowDurationActive();
        ShowID();
    }
    void ShowDurationActive() {
        if(App.Settings.HasChanged) Lcd.Printf(11, 4, "%u*  ", App.Settings.DurationActive_s);
        else Lcd.Printf(11, 4, "%u   ", App.Settings.DurationActive_s);
    }
    void ShowID() {
        if(App.Settings.HasChanged) Lcd.Printf(0, 4, "ID = %u* ", App.Settings.ID);
        else Lcd.Printf(0, 4, "ID = %u ", App.Settings.ID);
    }

    void ShowMSns(bool Sns1, bool Sns2) { Lcd.Printf(0, 6, "Sns1 %u;  Sns2 %u", Sns1, Sns2); }

    void Error(const char* msg) { Lcd.Printf(0, 7, "%S", msg); }
};

extern Interface_t Interface;

#endif /* INTERFACE_H_ */
