/*
 * board.h
 *
 *  Created on: 12 сент. 2015 г.
 *      Author: Kreyl
 */

#pragma once

#include <inttypes.h>

// ==== General ====
#define BOARD_NAME          "SalemBox"
#define APP_NAME            "RockOfDalan"

// MCU type as defined in the ST header.
#define STM32L151xB

// Freq of external crystal if any. Leave it here even if not used.
#define CRYSTAL_FREQ_HZ     12000000

#define SYS_TIM_CLK         (Clk.APB1FreqHz)
#define I2C1_ENABLED        FALSE
#define I2C_USE_SEMAPHORE   FALSE
#define ADC_REQUIRED        FALSE

#if 1 // ========================== GPIO =======================================
// PortMinTim_t: GPIO, Pin, Tim, TimChnl, invInverted, omPushPull, TopValue
// UART
#define UART_GPIO       GPIOA
#define UART_TX_PIN     9
#define UART_RX_PIN     10
#define UART_AF         AF7 // for USART1 @ GPIOA

#define LEDWS_GPIO      GPIOB
#define LEDWS_PIN       15

// Radio
#define CC_GPIO         GPIOA
#define CC_GDO2         NC
#define CC_GDO0         0
#define CC_SCK          5
#define CC_MISO         6
#define CC_MOSI         7
#define CC_CS           1
// Input pin
#define CC_GDO0_IRQ     { CC_GPIO, CC_GDO0, pudNone }

#endif // GPIO

#if 1 // =========================== SPI =======================================
#define LEDWS_SPI       SPI2
#define LEDWS_SPI_AF    AF5
#define CC_SPI          SPI1
#define CC_SPI_AF       AF5
#endif

#if 1 // ========================== USART ======================================
#define UART            USART1
#define UART_TX_REG     UART->DR
#define UART_RX_REG     UART->DR
#endif

#if 1 // =========================== DMA =======================================
#define STM32_DMA_REQUIRED  TRUE    // Always

#define LEDWS_DMA       STM32_DMA1_STREAM5  // SPI2 TX

// ==== Uart ====
#define UART_DMA_TX     STM32_DMA1_STREAM4
#define UART_DMA_RX     STM32_DMA1_STREAM5
#define UART_DMA_CHNL   0   // Dummy

#endif // DMA
