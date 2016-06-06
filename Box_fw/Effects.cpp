/*
 * Effects.cpp
 *
 *  Created on: 15 ����� 2016 �.
 *      Author: Kreyl
 */

#include "Effects.h"
#include "main.h"

Effects_t Effects;

#define CHUNK_CNT   5
static LedChunk_t Chunk[CHUNK_CNT] = {
        {0, 14},
        {15, 29},
        {30, 44},
        {45, 59},
        {60, 74},
};

#if 1 // ============================= Sinus ===================================
#define BRT_PERIOD          511
#define TICK_INC            8   // Defines speed of color switching
#define SIN_PERIOD_LEN      17   // Number of LEDs
#define SIN_PERIOD_CNT      (LED_CNT / SIN_PERIOD_LEN)
#define SIN_LED_STEP        (BRT_PERIOD / SIN_PERIOD_LEN)
#define SIN_REVERSE_DIR     TRUE
const Color_t SinColor1 = {255, 64, 0};
const Color_t SinColor2 = clRed;

class EffSinus_t {
private:
    int Tick=0;   // 0...BRT_PERIOD
    int TickToBrightness(int NLed) {
        int Phase = Tick + NLed * SIN_LED_STEP;
        if(Phase > BRT_PERIOD) Phase -= BRT_PERIOD;

        if(Phase <= (BRT_PERIOD/2)) return Phase;
        else return BRT_PERIOD-Phase;
    }
public:
    void Process() {
#if SIN_REVERSE_DIR
        Tick -= TICK_INC;
        if(Tick < 0) Tick = BRT_PERIOD;
#else
        Tick += TICK_INC;
        if(Tick > BRT_PERIOD) Tick = 0;
#endif

        for(int Per=0; Per<SIN_PERIOD_CNT; Per++) {
            for(int i=0; i<SIN_PERIOD_LEN; i++) {
                int Brt = TickToBrightness(i);
                int N = Per * SIN_PERIOD_LEN + i;
                LedWs.ICurrentClr[N].BeMixOf(SinColor1, SinColor2, Brt);
            }
        }
        LedWs.ISetCurrentColors();
        chThdSleepMilliseconds(1);
    }
};

EffSinus_t EffSinus;

void Effects_t::SinusRun() {
    chSysLock();
    IState = effSinus;
    chSchWakeupS(PThd, MSG_OK);
    chSysUnlock();
}
#endif

#if 1 // =========================== Flashes ===================================
#define FLASH_MIN_LEN           7
#define FLASH_MAX_LEN           45
#define FLASH_DURATION_MS       18
#define FLASH_BTW_DELAY_MS      99  // For double flashes
#define FLASH_T2NEXT_MIN_MS     540
#define FLASH_T2NEXT_MAX_MS     4005

static const Color_t FlashColors[] = {
        {108, 108, 255},
        {255, 108, 255},
        {255, 255, 255},
};
#define FLASH_CLR_CNT       countof(FlashColors)

class Flash_t {
private:
    int Start, Len;
    int ColorIndx;
    uint32_t TimeToNext_ms;
    int Count;
    void Generate() {
        // Color
        ColorIndx = Random(0, FLASH_CLR_CNT-1);
        Len = Random(FLASH_MIN_LEN, FLASH_MAX_LEN);
        Start = Random(0, LED_CNT - Len);
        Count = (Random(1, 10) > 7)? 2 : 1;
        TimeToNext_ms = Random(FLASH_T2NEXT_MIN_MS, FLASH_T2NEXT_MAX_MS);
        // Print
//        Uart.Printf("Flash: S=%02u; Len=%02u; Clr=%u; Count=%u; T2Next=%u\r",
//                Start, Len, ColorIndx, Count, TimeToNext_ms);
    }
public:
    void Process() {
        Generate();
        int End = Start+Len;
        for(int j=0; j<Count; j++) {
            for(int i=Start; i<End; i++) LedWs.ICurrentClr[i] = FlashColors[ColorIndx];
            LedWs.ISetCurrentColors();
            chThdSleepMilliseconds(FLASH_DURATION_MS);
            for(int i=Start; i<End; i++) LedWs.ICurrentClr[i] = clBlack;
            LedWs.ISetCurrentColors();
            chThdSleepMilliseconds(FLASH_BTW_DELAY_MS);
        } // j
        chThdSleepMilliseconds(TimeToNext_ms);
    }
};

static Flash_t Flash;

void Effects_t::Flashes() {
    chSysLock();
    IState = effFlashes;
    chSchWakeupS(PThd, MSG_OK);
    chSysUnlock();
}
#endif

static THD_WORKING_AREA(waEffectsThread, 256);
__noreturn
static void EffectsThread(void *arg) {
    chRegSetThreadName("Effects");
    Effects.ITask();
}

__noreturn
void Effects_t::ITask() {
    while(true) {
        switch(IState) {
            case effIdle: chThdSleep(TIME_INFINITE); break;

            case effAllSmoothly: {
                uint32_t Delay = 0;
                for(uint8_t i=0; i<LED_CNT; i++) {
                    uint32_t tmp = ICalcDelayN(i);  // }
                    if(tmp > Delay) Delay = tmp;    // } Calculate Delay
                    LedWs.ICurrentClr[i].Adjust(&DesiredClr[i]); // Adjust current color
                } // for
                LedWs.ISetCurrentColors();
                if(Delay == 0) {    // Setup completed
                    App.SignalEvt(EVT_LEDS_DONE);
                    IState = effIdle;
                }
                else chThdSleepMilliseconds(Delay);
            } break;

            case effChunkRunning: IProcessChunkRun(); break;
            case effSinus: EffSinus.Process(); break;
            case effFlashes: Flash.Process(); break;
        } // switch
    } // while true
}

void Effects_t::Init() {
    LedWs.Init();
    PThd = chThdCreateStatic(waEffectsThread, sizeof(waEffectsThread), HIGHPRIO, (tfunc_t)EffectsThread, NULL);
}


void Effects_t::AllTogetherNow(Color_t Color) {
    IState = effIdle;
    for(uint32_t i=0; i<LED_CNT; i++) LedWs.ICurrentClr[i] = Color;
    LedWs.ISetCurrentColors();
    App.SignalEvt(EVT_LEDS_DONE);
}

void Effects_t::AllTogetherSmoothly(Color_t Color, uint32_t ASmoothValue) {
    if(ASmoothValue == 0) AllTogetherNow(Color);
    else {
        chSysLock();
        for(uint32_t i=0; i<LED_CNT; i++) {
            DesiredClr[i] = Color;
            SmoothValue[i] = ASmoothValue;
        }
        IState = effAllSmoothly;
        chSchWakeupS(PThd, MSG_OK);
        chSysUnlock();
    }
}

#if 1 // ============================ ChunkRun =================================
void Effects_t::ChunkRun(Color_t Color, uint32_t NLeds) {
    chSysLock();
    for(uint32_t i=0; i<CHUNK_CNT; i++) {
        Chunk[i].Color = Color;
        Chunk[i].NLeds = NLeds;
        Chunk[i].StartOver();
    }
    IState = effChunkRunning;
    chSchWakeupS(PThd, MSG_OK);
    chSysUnlock();
}

void Effects_t::IProcessChunkRun() {
//    uint32_t Delay = 0;
    for(uint32_t i=0; i<CHUNK_CNT; i++) {
//        uint32_t ChunkDelay =
                Chunk[i].ProcessAndGetDelay();
//        if(ChunkDelay > Delay) Delay = ChunkDelay;
    }
    LedWs.ISetCurrentColors();
    chThdSleepMilliseconds(360);
}

uint32_t Effects_t::ICalcDelayN(uint32_t n) {
    uint32_t DelayR = (LedWs.ICurrentClr[n].R == DesiredClr[n].R)? 0 : CalcDelay(LedWs.ICurrentClr[n].R, SmoothValue[n]);
    uint32_t DelayG = (LedWs.ICurrentClr[n].G == DesiredClr[n].G)? 0 : CalcDelay(LedWs.ICurrentClr[n].G, SmoothValue[n]);
    uint32_t DelayB = (LedWs.ICurrentClr[n].B == DesiredClr[n].B)? 0 : CalcDelay(LedWs.ICurrentClr[n].B, SmoothValue[n]);
//    Uart.Printf("I=%u; R=%u/%u; G=%u/%u; B=%u/%u\r",
//            Indx,
//            IClr[Indx].Red,   DesiredClr[Indx].Red,
//            IClr[Indx].Green, DesiredClr[Indx].Green,
//            IClr[Indx].Blue,  DesiredClr[Indx].Blue);
//    Uart.Printf("DR=%u; DG=%u; DB=%u\r", DelayR, DelayG, DelayB);
    uint32_t Rslt = DelayR;
    if(DelayG > Rslt) Rslt = DelayG;
    if(DelayB > Rslt) Rslt = DelayB;
    return Rslt;
}

#if 1 // ============================== LedChunk ===============================
uint32_t LedChunk_t::ProcessAndGetDelay() {
    if(LedWs.ICurrentClr[Head] == Color) {   // Go on if done with current
        GetNext(&Head);
        GetNext(&Tail);
        Effects.DesiredClr[Head] = Color;
        Effects.DesiredClr[Tail] = clBlack;
    }
    // Iterate Leds
//    uint32_t Delay = 99;
    int n = Start;
    do {
//        uint32_t tmp = Effects.ICalcDelayN(n);  // }
//        if(tmp > Delay) Delay = tmp;            // } Calculate Delay
//        if(Delay!= 0)
//            LedWs.ICurrentClr[n].Adjust(&Effects.DesiredClr[n]); // Adjust current color
            LedWs.ICurrentClr[n] = Effects.DesiredClr[n]; // Adjust current color
    } while(GetNext(&n) == OK);
    return 0;
}

void LedChunk_t::StartOver() {
    Head = Start; //Random(Start, End);
    Tail = GetPrevN(Head, NLeds);
    Effects.DesiredClr[Head] = Color;
    Effects.DesiredClr[Tail] = clBlack;
}

uint8_t LedChunk_t::GetNext(int *PCurrent) {
    int curr = *PCurrent;
    if(curr == End) {
        *PCurrent = Start;
        return OVERFLOW;
    }
    else {
        if(End > Start) *PCurrent = curr + 1;
        else *PCurrent = curr - 1;
        return OK;
    }
}

int LedChunk_t::GetPrevN(int Current, int N) {
    int Rslt;
    if(End > Start) {
        Rslt = Current - N;
        if(Rslt < Start) Rslt += 1 + End - Start;
    }
    else {
        Rslt = Current + N;
        if(Rslt > Start) Rslt -= Start - End + 1;
    }
    return Rslt;
}
#endif

#endif
