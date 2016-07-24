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
TmrKL_t TmrEverySecond{MS2ST(99), EVT_EVERY_SECOND, tktPeriodic};

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
//    Effects.AllTogetherNow(clGreen);
//    Effects.AllTogetherSmoothly(clGreen, 360);
//    Effects.ChunkRun(clYellow, 3);
//    Effects.SinusRun();
//    Effects.Flashes();

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
    while(true) {
        __unused eventmask_t Evt = chEvtWaitAny(ALL_EVENTS);
        if(Evt & EVT_EVERY_SECOND) {
            Uart.Printf("#\r");
            Effects.AllTogetherNow(clGreen);
        }

#if UART_RX_ENABLED
        if(Evt & EVT_UART_NEW_CMD) {
            OnCmd((Shell_t*)&Uart);
            Uart.SignalCmdProcessed();
        }
#endif

    } // while true
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

