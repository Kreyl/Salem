/*
 * color.h
 *
 *  Created on: 05 ���. 2014 �.
 *      Author: Kreyl
 */

#pragma once

#include "inttypes.h"
#include "uart.h"

// Mixing two colors
#define ClrMix(C, B, L)     ((C * L + B * (255 - L)) / 255)

// Smooth delay
static inline uint32_t CalcDelay(uint16_t AValue, uint32_t Smooth) {
    return (uint32_t)((Smooth / (AValue+4)) + 1);
}

struct Color_t {
    union {
        struct {
            uint8_t R, G, B;
        };
        uint32_t DWord32;
    };
    bool operator == (const Color_t &AColor) { return ((R == AColor.R) and (G == AColor.G) and (B == AColor.B)); }
    bool operator != (const Color_t &AColor) { return ((R != AColor.R) or  (G != AColor.G) or  (B != AColor.B)); }
    Color_t& operator = (const Color_t &Right) { R = Right.R; G = Right.G; B = Right.B; return *this; }
    void Adjust(const Color_t &PColor) {
        if     (R < PColor.R) R++;
        else if(R > PColor.R) R--;
        if     (G < PColor.G) G++;
        else if(G > PColor.G) G--;
        if     (B < PColor.B) B++;
        else if(B > PColor.B) B--;
    }
    void Adjust(const Color_t &PColor, uint32_t Step) {
        uint32_t ThrsR = 255 - Step;
        if(R < PColor.R) {
            if(R <= ThrsR) R += Step;
            else R = 255;
        }
        else if(R > PColor.R) {
            if(R >= Step) R -= Step;
            else R = 0;
        }

        if(G < PColor.G) {
            if(G <= ThrsR) G += Step;
            else G = 255;
        }
        else if(G > PColor.G) {
            if(G >= Step) G -= Step;
            else G = 0;
        }

        if(B < PColor.B) {
            if(B <= ThrsR) B += Step;
            else B = 255;
        }
        else if(B > PColor.B) {
            if(B >= Step) B -= Step;
            else B = 0;
        }
    }
    void Set(uint8_t Red, uint8_t Green, uint8_t Blue) { R = Red; G = Green; B = Blue; }
    void Get(uint8_t *PR, uint8_t *PG, uint8_t *PB) const { *PR = R; *PG = G; *PB = B; }
    uint8_t RGBTo565_HiByte() const {
        uint32_t rslt = R & 0b11111000;
        rslt |= G >> 5;
        return (uint8_t)rslt;
    }
    uint8_t RGBTo565_LoByte() const {
        uint32_t rslt = (G << 3) & 0b11100000;
        rslt |= B >> 3;
        return (uint8_t)rslt;
    }
    void BeMixOf(const Color_t &Fore, const Color_t &Back, uint32_t Brt) {
        R = ClrMix(Fore.R, Back.R, Brt);
        G = ClrMix(Fore.G, Back.G, Brt);
        B = ClrMix(Fore.B, Back.B, Brt);
    }
    void Print() { Uart.Printf("{%u, %u, %u}\r", R, G, B); }
} __attribute__((packed));

// ==== Colors ====
#define clBlack     ((Color_t){0,   0,   0})
#define clRed       ((Color_t){255, 0,   0})
#define clGreen     ((Color_t){0,   255, 0})
#define clBlue      ((Color_t){0,   0,   255})
#define clYellow    ((Color_t){255, 255, 0})
#define clMagenta   ((Color_t){255, 0, 255})
#define clCyan      ((Color_t){0, 255, 255})
#define clWhite     ((Color_t){255, 255, 255})

#define CL_DARK_V       27
#define clDarkRed       ((Color_t){CL_DARK_V, 0,         0})
#define clDarkGreen     ((Color_t){0,         CL_DARK_V, 0})
#define clDarkBlue      ((Color_t){0,         0,         CL_DARK_V})
#define clDarkYellow    ((Color_t){CL_DARK_V, CL_DARK_V, 0})
#define clDarkMagenta   ((Color_t){CL_DARK_V, 0,         CL_DARK_V})
#define clDarkCyan      ((Color_t){0,         CL_DARK_V, CL_DARK_V})
#define clDarkWhite     ((Color_t){CL_DARK_V, CL_DARK_V, CL_DARK_V})

#if 0 // ============================ Color table ==============================
const Color_t ColorTable[] = {
        {255,0,0},
        {255,24,0},
        {255,48,0},
        {255,71,0},
        {255,94,0},
        {255,117,0},
        {255,138,0},
        {255,158,0},
        {255,177,0},
        {255,195,0},
        {255,210,0},
        {255,224,0},
        {255,235,0},
        {255,244,0},
        {255,250,0},
        {255,254,0},
        {254,255,0},
        {250,255,0},
        {241,255,0},
        {228,255,0},
        {212,255,0},
        {193,255,0},
        {172,255,0},
        {150,255,0},
        {127,255,0},
        {104,255,0},
        {82,255,0},
        {61,255,0},
        {42,255,0},
        {26,255,0},
        {13,255,0},
        {4,255,0},
        {0,255,0},
        {0,255,1},
        {0,255,7},
        {0,255,17},
        {0,255,31},
        {0,255,48},
        {0,255,68},
        {0,255,89},
        {0,255,112},
        {0,255,135},
        {0,255,157},
        {0,255,179},
        {0,255,199},
        {0,255,217},
        {0,255,233},
        {0,255,244},
        {0,255,252},
        {0,255,255},
        {0,252,255},
        {0,244,255},
        {0,233,255},
        {0,217,255},
        {0,199,255},
        {0,179,255},
        {0,157,255},
        {0,135,255},
        {0,112,255},
        {0,89,255},
        {0,68,255},
        {0,48,255},
        {0,31,255},
        {0,17,255},
        {0,7,255},
        {0,1,255},
        {0,0,255},
        {4,0,255},
        {13,0,255},
        {26,0,255},
        {42,0,255},
        {61,0,255},
        {82,0,255},
        {104,0,255},
        {127,0,255},
        {150,0,255},
        {172,0,255},
        {193,0,255},
        {212,0,255},
        {228,0,255},
        {241,0,255},
        {250,0,255},
        {254,0,255},
        {255,0,254},
        {255,0,251},
        {255,0,245},
        {255,0,237},
        {255,0,227},
        {255,0,215},
        {255,0,201},
        {255,0,186},
        {255,0,169},
        {255,0,151},
        {255,0,131},
        {255,0,111},
        {255,0,90},
        {255,0,68},
        {255,0,45},
        {255,0,22},
        {255,0,0}
};
#define COLOR_TABLE_SZ  countof(ColorTable)
#endif
