#include "board.h"
#include "led.h"
#include "Sequences.h"
#include "kl_lib.h"
#include "MsgQ.h"
#include "SimpleSensors.h"
#include "color.h"
#include "uart.h"

#if 1 // ======================== Variables and defines ========================
// Forever
EvtMsgQ_t<EvtMsg_t, MAIN_EVT_Q_LEN> EvtQMain;
static const UartParams_t CmdUartParams(115200, CMD_UART_PARAMS);
CmdUart_t Uart{&CmdUartParams};
static void ITask();
static void OnCmd(Shell_t *PShell);

// LED band
uint32_t OnDurationMin = 36, OnDurationMax = 207, OffDurationMin = 306, OffDurationMax = 2007;
PinOutput_t LedBand{GPIOB, 0, omPushPull};
TmrKL_t TmrBandOn{evtIdBandOff, tktOneShot};
TmrKL_t TmrBandOff{evtIdBandOn, tktOneShot};
TmrKL_t TmrBandOffDelay{evtIdBandOffDelay, tktOneShot};

bool MustShine = true;

// Inputs
PinInput_t Sns1{GPIOB, 2, pudPullDown};
PinInput_t Sns2{GPIOB, 5, pudPullDown};
#endif

int main(void) {
    SetupVCore(vcore1V5);
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
    TmrBandOff.StartOrRestart(TIME_MS2I(45));
    TmrBandOffDelay.StartOrRestart(TIME_MS2I(5400));

    Sns1.Init();
    Sns2.Init();

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

            case evtIdBandOn:
                Printf("Sns: %u %u\r", Sns1.IsHi(), Sns2.IsHi());
                if(Sns1.IsHi() or Sns2.IsHi()) {
                    TmrBandOffDelay.StartOrRestart(TIME_MS2I(5400));
                    MustShine = true;
                }
                if(MustShine) LedBand.SetHi();
                TmrBandOn.StartOrRestart(TIME_MS2I(Random::Generate(OnDurationMin, OnDurationMax)));
                break;
            case evtIdBandOff:
                LedBand.SetLo();
                TmrBandOff.StartOrRestart(TIME_MS2I(Random::Generate(OffDurationMin, OffDurationMax)));
                break;
            case evtIdBandOffDelay:
                MustShine = false;
                Printf("OffDelay\r");
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

    else if(PCmd->NameIs("Set")) {
        if(     PCmd->GetNext<uint32_t>(&OnDurationMin) == retvOk and
                PCmd->GetNext<uint32_t>(&OnDurationMax) == retvOk and
                PCmd->GetNext<uint32_t>(&OffDurationMin) == retvOk and
                PCmd->GetNext<uint32_t>(&OffDurationMax) == retvOk) PShell->Ok();
        else PShell->BadParam();
    }

    else PShell->CmdUnknown();
}
#endif
