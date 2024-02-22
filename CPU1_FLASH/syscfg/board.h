/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************

//
// ANALOG -> myANALOGPinMux0 Pinmux
//

//
// CANA -> myCAN0 Pinmux
//
//
// CANA_RX - GPIO Settings
//
#define GPIO_PIN_CANA_RX 5
#define myCAN0_CANRX_GPIO 5
#define myCAN0_CANRX_PIN_CONFIG GPIO_5_CANA_RX
//
// CANA_TX - GPIO Settings
//
#define GPIO_PIN_CANA_TX 4
#define myCAN0_CANTX_GPIO 4
#define myCAN0_CANTX_PIN_CONFIG GPIO_4_CANA_TX
//
// GPIO11 - GPIO Settings
//
#define BTS71220_chip_select_GPIO_PIN_CONFIG GPIO_11_GPIO11
//
// GPIO13 - GPIO Settings
//
#define LHI_1_GPIO_PIN_CONFIG GPIO_13_GPIO13
//
// GPIO0 - GPIO Settings
//
#define PDRST_SHUNT_GPIO_PIN_CONFIG GPIO_0_GPIO0
//
// GPIO25 - GPIO Settings
//
#define Aux0_GPIO_PIN_CONFIG GPIO_25_GPIO25

//
// I2CA -> myI2C0 Pinmux
//
//
// I2CA_SDA - GPIO Settings
//
#define GPIO_PIN_I2CA_SDA 10
#define myI2C0_I2CSDA_GPIO 10
#define myI2C0_I2CSDA_PIN_CONFIG GPIO_10_I2CA_SDA
//
// I2CA_SCL - GPIO Settings
//
#define GPIO_PIN_I2CA_SCL 8
#define myI2C0_I2CSCL_GPIO 8
#define myI2C0_I2CSCL_PIN_CONFIG GPIO_8_I2CA_SCL

//
// SPIA -> mySPI0 Pinmux
//
//
// SPIA_PICO - GPIO Settings
//
#define GPIO_PIN_SPIA_PICO 2
#define mySPI0_SPIPICO_GPIO 2
#define mySPI0_SPIPICO_PIN_CONFIG GPIO_2_SPIA_SIMO
//
// SPIA_POCI - GPIO Settings
//
#define GPIO_PIN_SPIA_POCI 1
#define mySPI0_SPIPOCI_GPIO 1
#define mySPI0_SPIPOCI_PIN_CONFIG GPIO_1_SPIA_SOMI
//
// SPIA_CLK - GPIO Settings
//
#define GPIO_PIN_SPIA_CLK 3
#define mySPI0_SPICLK_GPIO 3
#define mySPI0_SPICLK_PIN_CONFIG GPIO_3_SPIA_CLK

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
#define myADC0_BASE ADCA_BASE
#define myADC0_RESULT_BASE ADCARESULT_BASE
#define myADC0_SOC0 ADC_SOC_NUMBER0
#define myADC0_FORCE_SOC0 ADC_FORCE_SOC0
#define myADC0_SAMPLE_WINDOW_SOC0 80
#define myADC0_TRIGGER_SOURCE_SOC0 ADC_TRIGGER_SW_ONLY
#define myADC0_CHANNEL_SOC0 ADC_CH_ADCIN5
void myADC0_init();


//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// CAN Configurations
//
//*****************************************************************************
#define myCAN0_BASE CANA_BASE

#define myCAN0_MessageObj1_ID 10
#define myCAN0_MessageObj2_ID 11
void myCAN0_init();


//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
#define myCPUTIMER0_BASE CPUTIMER0_BASE
void myCPUTIMER0_init();

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define BTS71220_chip_select 11
void BTS71220_chip_select_init();
#define LHI_1 13
void LHI_1_init();
#define PDRST_SHUNT 0
void PDRST_SHUNT_init();
#define Aux0 25
void Aux0_init();

//*****************************************************************************
//
// I2C Configurations
//
//*****************************************************************************
#define myI2C0_BASE I2CA_BASE
#define myI2C0_BITRATE 100000
#define myI2C0_TARGET_ADDRESS 81
#define myI2C0_OWN_TARGET_ADDRESS 0
void myI2C0_init();

//*****************************************************************************
//
// SPI Configurations
//
//*****************************************************************************
#define mySPI0_BASE SPIA_BASE
#define mySPI0_BITRATE 1000000
void mySPI0_init();

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	ADC_init();
void	ASYSCTL_init();
void	CAN_init();
void	CPUTIMER_init();
void	GPIO_init();
void	I2C_init();
void	SPI_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
