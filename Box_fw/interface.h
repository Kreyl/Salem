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
        Lcd.Printf(4, 0, "StarPath");
        Lcd.Symbols(0, 1, LineHorizDouble, 16, 0);
        ShowPercent();
        ShowSetupState();
    }
    // Settings
    void ShowPercent() {
        if(App.SettingsHasChanged) {
            Lcd.Printf(0, 3, "%u%%* ", App.Settings.Percent);
            Lcd.Printf(0, 7, "Not Sent  "); // Remove accepted
        }
        else Lcd.Printf(0, 3, "%u%% ", App.Settings.Percent);
    }
    void ShowSetupState() {
        switch(SetupState) {
            case setstNotSent:  Lcd.Printf(0, 7, "Not Sent  "); break;
            case setstSending:  Lcd.Printf(0, 7, "Sending..."); break;
            case setstAccepted: Lcd.Printf(0, 7, "Accepted  "); break;
        }
//        if(App.RadioIsOn) Lcd.PrintfInverted(0, 7, "Radio"); else Lcd.Printf(0, 7, "Radio");
    }

    void Error(const char* msg) { Lcd.PrintfInverted(0, 2, "%S", msg); }
};

extern Interface_t Interface;

#endif /* INTERFACE_H_ */
