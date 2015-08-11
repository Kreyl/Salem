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
        Lcd.Printf(11, 0, VERSION_STRING);
        Lcd.Printf(9, 1, "Active");
        Lcd.Printf(8, 2, "duration");
        Lcd.Symbols(0, 5, LineHorizDouble, 6, LineHorizDoubleUp, 1, LineHorizDouble, 9, 0);
        for(int i=0; i<5; i++) Lcd.Symbols(6, i, ((i == 2)? LineVertDoubleLeft : LineVertDouble), 1,0);
        Lcd.Symbols(0, 2, LineHorizDouble, 6, 0);
        ShowDurationActive();
        ShowID();
        ShowMSns1(0);
        ShowMSns2(0);
        ShowRadio();
        ShowDeadtimeSettings();
        ShowDeadtime();
        ShowLedOff();
    }
    // Settings
    void ShowDurationActive() {
        if(App.SettingsHasChanged) Lcd.Printf(9, 4, "%u* s ", App.Settings.DurationActive_s);
        else Lcd.Printf(9, 4, "%u s ", App.Settings.DurationActive_s);
    }
    void ShowID() {
        if(App.SettingsHasChanged) Lcd.Printf(0, 0, "ID=%02u*", App.Settings.ID);
        else Lcd.Printf(0, 0, "ID=%02u ", App.Settings.ID);
    }
    void ShowDeadtimeSettings() {
        char c = App.SettingsHasChanged? '*' : ' ';
        Lcd.Printf(0, 3, "DeadT");
        if(App.Settings.DeadtimeEnabled) Lcd.Printf(0, 4, " On%c ", c);
        else Lcd.Printf(0, 4, " Off%c ", c);
    }

    // Status line
    void ShowMSns1(bool Sns) { if(Sns) Lcd.PrintfInverted(0,  6, "Sns1"); else Lcd.Printf(0,  6, "Sns1"); }
    void ShowMSns2(bool Sns) { if(Sns) Lcd.PrintfInverted(11, 6, "Sns2"); else Lcd.Printf(11, 6, "Sns2"); }
    void ShowRadio() {
        if(App.RadioIsOn) Lcd.PrintfInverted(0, 7, "Radio"); else Lcd.Printf(0, 7, "Radio");
    }
    void ShowDeadtime() {
        if(App.DeadTimeIsNow) Lcd.PrintfInverted(11, 7, "DeadT"); else Lcd.Printf(11, 7, "DeadT");
    }
    void ShowLedOn()  { Lcd.PrintfInverted(6, 6, "Out"); }
    void ShowLedOff() { Lcd.Printf(6, 6, "Out"); }

    void Error(const char* msg) { Lcd.PrintfInverted(0, 2, "%S", msg); }
};

extern Interface_t Interface;

#endif /* INTERFACE_H_ */
