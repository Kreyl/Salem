#include "board.h"
#include "led.h"
#include "Sequences.h"
#include "kl_lib.h"
#include "MsgQ.h"
#include "SimpleSensors.h"
#include "color.h"
#include "uart.h"
#include "radio_lvl1.h"

#if 1 // ======================== Variables and defines ========================
// Forever
EvtMsgQ_t<EvtMsg_t, MAIN_EVT_Q_LEN> EvtQMain;
static const UartParams_t CmdUartParams(115200, CMD_UART_PARAMS);
CmdUart_t Uart{&CmdUartParams};
static void ITask();
static void OnCmd(Shell_t *PShell);

// LED band
//PinOutput_t LedBand{GPIOB, 0, omPushPull};
PinOutputPWM_t LedBand{GPIOB, 0, TIM3, 3, invNotInverted, omPushPull, 4094};
#endif

int main(void) {
    SetupVCore(vcore1V8);
    if(Clk.EnableHSI() == retvOk) {
        Clk.SetupFlashLatency(16);
        Clk.SwitchToHSI();
    }
    Clk.UpdateFreqValues();
#if 1 // ==== Init OS and UART ====
    halInit();
    chSysInit();
    EvtQMain.Init();
    Uart.Init();
    Printf("\r%S %S\r", APP_NAME, XSTRINGIFY(BUILD_TIME));
    Clk.PrintFreqs();
#endif

    LedBand.Init();

    if(Radio.Init() == retvOk) {
        LedBand.Set(99);
    }

    // Main cycle
    ITask();
}

__noreturn
void ITask() {
    while(true) {
        EvtMsg_t Msg = EvtQMain.Fetch(TIME_INFINITE);
        switch(Msg.ID) {
#if BUTTONS_ENABLED
            case evtIdButtons:
//                Printf("Btn %u\r", Msg.BtnEvtInfo.Type);
                // Main button
                if(Msg.BtnEvtInfo.BtnID == 0) {
                    if(Msg.BtnEvtInfo.Type == beLongPress) {
                        IsEnteringSleep = !IsEnteringSleep;
                        if(IsEnteringSleep) OrbRing.FadeOut();
                        else OrbRing.FadeIn();
                    }
                    else if(Msg.BtnEvtInfo.Type == beShortPress) {
                        if(IsUsbConnected()) { // Switch between flaring and Charging status
                            State = (State == stateChargingStatus)? stateFlaring : stateChargingStatus;
                        }
                        else State = stateFlaring;
                    }
                }
                // Right / Left buttons
                if(Msg.BtnEvtInfo.BtnID == 1 or Msg.BtnEvtInfo.BtnID == 2) {
                    if(State == stateFlaring) {
                        State = stateShowBounds;
                        OrbRing.StartShowBounds();
                        TmrEndShowBounds.StartOrRestart();
                    }
                    else if(State == stateShowBounds) {
                        if(Msg.BtnEvtInfo.Type == beShortPress or Msg.BtnEvtInfo.Type == beRepeat) {
                            if     (Msg.BtnEvtInfo.BtnID == 1) OrbRing.IncreaseColorBounds();
                            else if(Msg.BtnEvtInfo.BtnID == 2) OrbRing.DecreaseColorBounds();
                            TmrSave.StartOrRestart(); // Prepare to save
                            TmrEndShowBounds.StartOrRestart();
                        }
                    }
                } // btn 1 or 2
                break;
#endif
//            case evtIdEverySecond: Adc.StartMeasurement(); break;

            case evtIdRadioCmd:

                break;

            case evtIdShellCmd:
                OnCmd((Shell_t*)Msg.Ptr);
                ((Shell_t*)Msg.Ptr)->SignalCmdProcessed();
                break;
            default: Printf("Unhandled Msg %u\r", Msg.ID); break;
        } // Switch
    } // while true
} // ITask()

#if 1 // ================= Command processing ====================
void OnCmd(Shell_t *PShell) {
	Cmd_t *PCmd = &PShell->Cmd;
    __attribute__((unused)) int32_t dw32 = 0;  // May be unused in some configurations
//    Printf("%S%S\r", PCmd->IString, PCmd->Remainer? PCmd->Remainer : " empty");
    // Handle command
    if(PCmd->NameIs("Ping")) {
        PShell->Ok();
    }
    else if(PCmd->NameIs("Version")) PShell->Print("%S %S\r", APP_NAME, XSTRINGIFY(BUILD_TIME));


    else PShell->CmdUnknown();
}
#endif
