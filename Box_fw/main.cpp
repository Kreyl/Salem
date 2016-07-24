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

App_t App;
AppState_t appState = appsIdle;

TmrKL_t TmrEverySecond{MS2ST(5400), EVT_EVERY_SECOND, tktPeriodic};

void SetStateIndication();

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
    App.InitThread();

    // ==== Init hardware ====
    Uart.Init(115200, UART_GPIO, UART_TX_PIN, UART_GPIO, UART_RX_PIN);
    Uart.Printf("\r%S %S\r", APP_NAME, BUILD_TIME);
    Clk.PrintFreqs();

    Effects.Init();
//    Effects.AllTogetherNow({54,0,0});
//    Effects.AllTogetherSmoothly(clGreen, 360);
//    Effects.ChunkRun(clYellow, 3);
//    Effects.SinusRun();
//    Effects.Flashes();
    Effects.RandomGlow();

//    if(Radio.Init() != OK) {
////        Led.StartSequence(lsqFailure);
//        chThdSleepMilliseconds(2700);
//    }
//    else Led.StartSequence(lsqStart);

    TmrEverySecond.InitAndStart();

    // Main cycle
    App.ITask();
}

__noreturn
void App_t::ITask() {
//    bool flag = false;
    while(true) {
        __unused eventmask_t Evt = chEvtWaitAny(ALL_EVENTS);
        if(Evt & EVT_EVERY_SECOND) {
//            Uart.Printf("#\r");

//            if(flag) Effects.AllTogetherSmoothly(clGreen, 360);
//            else Effects.AllTogetherSmoothly(clBlack, 360);
//            flag = !flag;

            switch(appState) {
                case appsIdle: appState = appsRed; break;
                case appsRed: appState = appsBlue; break;
                case appsBlue: appState = appsWhite; break;
                case appsWhite: appState = appsIdle; break;
            }
//            SetStateIndication();
        }

#if UART_RX_ENABLED
        if(Evt & EVT_UART_NEW_CMD) {
            OnCmd((Shell_t*)&Uart);
            Uart.SignalCmdProcessed();
        }
#endif

    } // while true
}

void SetStateIndication() {
    switch(appState) {
        case appsIdle: Effects.AllTogetherSmoothly(clBlack, 720); break;
        case appsRed: Effects.SinusRun(); break;
        case appsBlue:  break;
        case appsWhite:  break;
    } // switch
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

