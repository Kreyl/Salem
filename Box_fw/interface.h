/*
 * interface.h
 *
 *  Created on: 22 ����� 2015 �.
 *      Author: Kreyl
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "lcd1200.h"
#include "main.h"

class Interface_t {
public:
    void Reset() {
        Lcd.Printf(9, 1, "Acive");
        Lcd.Printf(8, 2, "Duration");
        Lcd.Symbols(0, 5, LineHorizDouble, 6, LineHorizDoubleUp, 1, LineHorizDouble, 9, 0);
        for(int i=0; i<5; i++) Lcd.Symbols(6, i, ((i == 2)? LineVertDoubleLeft : LineVertDouble), 1,0);
        Lcd.Symbols(0, 2, LineHorizDouble, 6, 0);
        ShowDurationActive();
        ShowID();
        ShowMSns(0, 0);
        ShowRadio();
        ShowDeadtimeSettings();
        ShowDeadtime();
    }
    // Settings
    void ShowDurationActive() {
        if(App.SettingsHasChanged) Lcd.Printf(9, 4, "%u* s ", App.Settings.DurationActive_s);
        else Lcd.Printf(9, 4, "%u s ", App.Settings.DurationActive_s);
    }
    void ShowID() {
        if(App.SettingsHasChanged) Lcd.Printf(0, 1, "ID=%02u*", App.Settings.ID);
        else Lcd.Printf(0, 1, "ID=%02u ", App.Settings.ID);
    }
    void ShowDeadtimeSettings() {
        char c = App.SettingsHasChanged? '*' : ' ';
        Lcd.Printf(0, 3, "DeadT");
        if(App.Settings.DeadtimeEnabled) Lcd.Printf(0, 4, " On%c ", c);
        else Lcd.Printf(0, 4, " Off%c ", c);
    }

    // Status line
    void ShowMSns(bool Sns1, bool Sns2) {
        if(Sns1) Lcd.Printf(0,  6, "Sns1"); else Lcd.Printf(0,  6, "S1--");
        if(Sns2) Lcd.Printf(11, 6, "Sns2"); else Lcd.Printf(11, 6, "S2--");
    }
    void ShowRadio() {
        if(App.RadioIsOn) Lcd.Printf(0, 7, "Radio"); else Lcd.Printf(0, 7, "R----");
    }
    void ShowDeadtime() {
        if(App.DeadTimeIsNow) Lcd.Printf(11, 7, "DeadT"); else Lcd.Printf(11, 7, "D----");
    }

    void Error(const char* msg) { Lcd.Printf(0, 7, "%S", msg); }
};

extern Interface_t Interface;

#endif /* INTERFACE_H_ */
