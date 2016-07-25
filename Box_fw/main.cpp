/*
 * main.cpp
 *
 *  Created on: 20 февр. 2014 г.
 *      Author: g.kruglov
 */

#include "main.h"
#include "board.h"
#include "ws2812b.h"
#include "Effects.h"
#include "radio_lvl1.h"

#define REMCTRL_ID  8   // ID of remote control

enum AppState_t { appsIdle = 0, appsRed = 1, appsBlue = 2, appsWhite = 3 };

App_t App;

//TmrKL_t TmrEverySecond{MS2ST(5400), EVT_EVERY_SECOND, tktPeriodic};
TmrKL_t TmrOff{MS2ST(9000), EVT_OFF, tktOneShot};

void SetState(AppState_t NewState);

int main(void) {
    // ==== Init Vcore & clock system ====
    SetupVCore(vcore1V5);
//    Clk.SetMSI4MHz();
    Clk.SetupFlashLatency(16);
    Clk.SwitchToHSI();
    Clk.UpdateFreqValues();

    // Init OS
    halInit();
    chSysInit();
    chThdSleepMilliseconds(360);    // Let power to stabilize

    App.InitThread();

    // ==== Init hardware ====
    Uart.Init(115200, UART_GPIO, UART_TX_PIN, UART_GPIO, UART_RX_PIN);
    Uart.Printf("\r%S %S\r", APP_NAME, BUILD_TIME);
    Clk.PrintFreqs();

    Effects.Init();
//    Effects.AllTogetherNow({54,0,0});
//    Effects.AllTogetherSmoothly(clGreen, 360);
//    Effects.ChunkRun(clBlue, 3);
//    Effects.SinusRun(clBlue, clBlack);
//    Effects.Flashes();

    // Init radio
    bool RadioIsOk = false;
    for(int i=0; (i<7 and !RadioIsOk); i++) {
        if(Radio.Init() == OK) RadioIsOk = true;
    }
    if(RadioIsOk) {
        Effects.AllTogetherSmoothly(clGreen, 180);
        chThdSleepMilliseconds(900);
        Effects.AllTogetherSmoothly(clBlack, 180);
    }
    else {
        Effects.AllTogetherNow(clRed);
        chThdSleepMilliseconds(180);
        Effects.AllTogetherNow(clBlack);
        chThdSleepMilliseconds(180);
        Effects.AllTogetherNow(clRed);
        chThdSleepMilliseconds(180);
        Effects.AllTogetherNow(clBlack);
        chThdSleepMilliseconds(180);
        Effects.AllTogetherNow(clRed);
        chThdSleepMilliseconds(180);
        Effects.AllTogetherNow(clBlack);
    }

    // Timers
//    TmrEverySecond.InitAndStart();
    TmrOff.Init();

    // Main cycle
    App.ITask();
}

__noreturn
void App_t::ITask() {
    int RadioCounter = 0;
    while(true) {
        __unused eventmask_t Evt = chEvtWaitAny(ALL_EVENTS);

        if(Evt & EVT_RADIO) {
            TmrOff.Restart();
            // Accumulate data for some time
            RadioCounter++;
            if(RadioCounter >= 4) {
                RadioCounter = 0;
                Radio.RxTable.Print();
                // Check if RemCtrl presents
                rPkt_t *ptr = nullptr;
                if(Radio.RxTable.GetPktByID(REMCTRL_ID, &ptr) == OK) {
                    Uart.Printf("Remote: %u\r", ptr->State);
                    SetState((AppState_t)ptr->State);
                }
                // No Remote Control, proceed with others
                else {
                    uint32_t Cnt = Radio.RxTable.GetCount();
                    if(Cnt == 1 or Cnt == 2) SetState(appsWhite);
                    else if(Cnt == 3) SetState(appsRed);
                    else { // 4 or more
                        // Check if 0123 or 4567 present
                        if(
                               (Radio.RxTable.IDPresents(0) and
                                Radio.RxTable.IDPresents(1) and
                                Radio.RxTable.IDPresents(2) and
                                Radio.RxTable.IDPresents(3))
                                or
                               (Radio.RxTable.IDPresents(4) and
                                Radio.RxTable.IDPresents(5) and
                                Radio.RxTable.IDPresents(6) and
                                Radio.RxTable.IDPresents(7))
                           ) SetState(appsBlue);
                        else SetState(appsWhite);   // not present
                    }
                } // No rem ctrl
                Radio.RxTable.Clear();
            } // If RadioCounter
        } // Evt

        if(Evt & EVT_OFF) {
            Uart.Printf("Off\r");
            SetState(appsIdle);
        }

#if UART_RX_ENABLED
        if(Evt & EVT_UART_NEW_CMD) {
            OnCmd((Shell_t*)&Uart);
            Uart.SignalCmdProcessed();
        }
#endif

    } // while true
}

void SetState(AppState_t NewState) {
    static AppState_t OldState = appsIdle;
    if(OldState != NewState) {
        OldState = NewState;
        switch(NewState) {
            case appsIdle: Effects.AllTogetherSmoothly(clBlack, 360); break;
            case appsRed:   Effects.SinusRun(clRed, clBlack); break;
            case appsBlue:  Effects.SinusRun(clBlue, clBlack); break;
            case appsWhite: Effects.SinusRun({99,99,99}, clBlack); break;
        } // switch
    }
}


#if UART_RX_ENABLED // ======================= Command processing ============================
void App_t::OnCmd(Shell_t *PShell) {
	Cmd_t *PCmd = &PShell->Cmd;
    __attribute__((unused)) int32_t dw32 = 0;  // May be unused in some configurations
    Uart.Printf("%S\r", PCmd->Name);
    // Handle command
    if(PCmd->NameIs("Ping")) {
        PShell->Ack(OK);
    }

    else PShell->Ack(CMD_UNKNOWN);
}
#endif

