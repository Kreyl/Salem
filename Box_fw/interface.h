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
//        Lcd.Printf(9, 1, "Active");
//        Lcd.Printf(8, 2, "duration");
        Lcd.Printf(0, 0, "Test");
        Lcd.Symbols(0, 5, LineHorizDouble, 16, 0);
//        for(int i=0; i<5; i++) Lcd.Symbols(6, i, ((i == 2)? LineVertDoubleLeft : LineVertDouble), 1,0);
//        Lcd.Symbols(0, 2, LineHorizDouble, 6, 0);
        ShowMSns1(0);
        ShowMSns2(0);
        ShowLedOff();
    }
    // Status line
    void ShowMSns1(bool Sns) { if(Sns) Lcd.PrintfInverted(0,  6, "Sns1"); else Lcd.Printf(0,  6, "Sns1"); }
    void ShowMSns2(bool Sns) { if(Sns) Lcd.PrintfInverted(11, 6, "Sns2"); else Lcd.Printf(11, 6, "Sns2"); }

    void ShowLedOn()  { Lcd.PrintfInverted(6, 6, "Out"); }
    void ShowLedOff() { Lcd.Printf(6, 6, "Out"); }

    void Error(const char* msg) { Lcd.PrintfInverted(0, 2, "%S", msg); }
};

extern Interface_t Interface;

#endif /* INTERFACE_H_ */
