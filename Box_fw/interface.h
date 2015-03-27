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
    void ShowDurationActive() { Lcd.Printf(11, 4, "%u   ", App.Settings.DurationActive_s); }
    void ShowID() { Lcd.Printf(0, 4, "ID = %u ", App.Settings.ID); }
};

#endif /* INTERFACE_H_ */
