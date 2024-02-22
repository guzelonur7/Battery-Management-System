/*
 * BTS712204ESAXUMA1.h
 *
 *  Created on: Aug 11, 2023
 *      Author: User
 */

//*****************************************************************************
//
//! * DESCRIPTIONS:
//!   -------------
//!
//! * Basic Features:
//!   ---------------
//! --> Driving capability suitable for 5 A and 3 A loads and
//!     high in-rush current loads.
//! --> High-Side Switch with Diagnosis and Embedded Protection.
//! --> Daisy Chain capable SPI interface.
//! --> Slew rate control for all Channels.
//! --> Switch ON capability while Inverse Current condition.
//!
//!
//! * Protection Features:
//!   --------------------
//! --> Absolute and dynamic temperature limitation with controlled restart.
//! --> Over-current protection(tripping) with Programmable Restart Control
//!     and Current Threshold.
//! --> Under-voltage shutdown.
//! --> Over-voltage protection with external components.
//!
//! * Functional Safety Features:
//!   ---------------------------
//! --> Limp Home mode.
//! --> Monitoring of Input pin status (IN and LHI).
//! --> Checksum verification of Configuration Registers.
//! --> Current Sense verification mode.
//!
//! * The BTS71220-4ESA is a Serial Interface Power Controller, providing
//!   protection functions and diagnosis. The device is integrated
//!   in SMART7 technology.
//!
//
//*****************************************************************************

#ifndef DRIVERS_INC_HW_BTS712204ESAXUMA1_H_
#define DRIVERS_INC_HW_BTS712204ESAXUMA1_H_

#include"C:\Users\User\Desktop\BMS\Prototips\3\Code\drivers\inc\HW_librarys.h"

//
// Define definations
//

//
// Registers Write Addresses
//
#define WRITE_OUT  0x80    // 0b100xdddd   DCR.SWR = x, RB = 0      ++
#define WRITE_DCR  0xF7    // 0b1111dddd   DCR.SWR = x, RB = 1      +-
#define WRITE_RCD  0xC0    // 0b1100dddd   DCR.SWR = 1, RB = 1      ++
#define WRITE_PCS  0xD0    // 0b1101dddd   DCR.SWR = 1, RB = 1      +-
#define WRITE_ICS  0xE0    // 0b1110dddd   DCR.SWR = 1, RB = 1      --
#define WRITE_OCR  0xC0    // 0b1100dddd   DCR.SWR = 0, RB = 1      ++
#define WRITE_KRC  0xD0    // 0b1101dddd   DCR.SWR = 0, RB = 1      ++
#define WRITE_HWCR 0xE0    // 0b11100dd0   DCR.SWR = 0, RB = 1      ++

//
// Registers Read Addresses
//
#define READ_OUT        0x00    // 0b0xxx0000
#define READ_OCR        0x04    // 0b0xxx0100
#define READ_KRC        0x05    // 0b0xxx0101
#define READ_HWCR       0x06    // 0b0xxx0110
#define READ_DCR        0x07    // 0b0xxxx111
#define READ_RCS        0x08    // 0b0xxx1000
#define READ_SRC        0x09    // 0b0xxx1001
#define READ_RCD        0x0C    // 0b0xxx1100
#define READ_PCS        0x0D    // 0b0xxx1101
#define READ_ICS        0x0E    // 0b0xxx1110       ++
#define READ_WRNDIAG    0x01    // 0b0xxx0001
#define READ_STDDIAG    0x02    // 0b0xxx0010
#define READ_ERRDIAG    0x03    // 0b0xxx0011

//*****************************************************************************
//
//! Channels.
//
//*****************************************************************************
enum{
    CHANNEL0,
    CHANNEL1,
    CHANNEL2,
    CHANNEL3
};

//*****************************************************************************
//
//! Channel output status.
//
//*****************************************************************************
enum{

    CHANNEL_OFF,
    CHANNEL_ON
};

//*****************************************************************************
//
//! Overcurrent IL levels.
//
//*****************************************************************************
enum{
    LOW_LEVEL,
    HIGH_LEVEL
};

//*****************************************************************************
//
//! Current sense ratio ranges.
//
//*****************************************************************************
enum{

    LOW_RANGE,
    HIGH_RANGE
};

//*****************************************************************************
//
//! Input combinatorials.
//
//*****************************************************************************
enum{

    OR_COMBINE,
    AND_COMBINE
};

//*****************************************************************************
//
//! Switch register positions.
//
//*****************************************************************************
enum{

    POSITION_0,
    POSITION_1
};

//*****************************************************************************
//
//! Restart Strategys
//
//*****************************************************************************
enum{

    AUTOMATIC_MODE,
    LATCH_MODE
};

//*****************************************************************************
//
//! Parallel Channel Config
//
//*****************************************************************************
enum{

    INDEPENTEND,
    OUT0_OUT3,
    OUT1_OUT2,
    BOTH
};

//*****************************************************************************
//
//! Current Sense Multiplexer Configuration
//
//*****************************************************************************
enum{

    CH0_ROUTED,
    CH1_ROUTED,
    CH2_ROUTED,
    CH3_ROUTED,
    NON_ROUTED,
};


//*****************************************************************************
//
//! This function write datas.
//!
//! \param data: Data to be written.
//
//*****************************************************************************
void BTS71220_writeRegisters(uint8_t data);

//*****************************************************************************
//
//! This function reads registers.
//!
//! \param addr: Registers read addresses.
//
//*****************************************************************************
uint8_t BTS71220_readRegisters(uint8_t address);

//*****************************************************************************
//
//!
//!
//! \param addr:
//
//*****************************************************************************
uint8_t BTS71220_readWarningDiag(void);

//*****************************************************************************
//
//!
//!
//! \param addr:
//
//*****************************************************************************
uint8_t BTS71220_readErrorDiag(void);

//*****************************************************************************
//
//!
//!
//! \param addr:
//
//*****************************************************************************
uint8_t BTS71220_readStandardDiag(void);



//*****************************************************************************
//
//! This function read input status all channels.
//
//*****************************************************************************
uint8_t BTS71220_readInputStatus(void);

//*****************************************************************************
//
//! This function config to 'switch' bit on DCR register.
//!
//! \param switchPosition;
//!        POSITION_0 : OUT, OCR, KRC, HWCR and DCR can be written.
//!        POSITION_1 : OUT, RCD, PCS, ICS  and DCR can be written.
//
//*****************************************************************************
void BTS71220_switchRegister(uint8_t switchPosition);

//*****************************************************************************
//
//! This function control the channels overcurrent levels.
//!
//! \param channel: CHANNEL0, CHANNEL1, CHANNEL2, CHANNEL3.
//!
//! \param level:   HIGH_LEVEL, LOW_LEVEL.
//
//*****************************************************************************
void BTS71220_overCurrentLevelConfig(uint8_t channel, uint8_t level);

//*****************************************************************************
//
//! This function control the channels current sense ratio ranges.
//!
//! \param channel: CHANNEL0, CHANNEL1, CHANNEL2, CHANNEL3.
//!
//! \param level:   HIGH_RANGE, LOW_RANGE.
//
//*****************************************************************************
void BTS71220_currentSenseRatioRangeConfig(uint8_t channel, uint8_t range);

//*****************************************************************************
//
//! This function configure the DCR multiplexer
//
//*****************************************************************************
void BTS71220_setMultiplexerConfig(uint8_t mode);

//*****************************************************************************
//
//! This function control the output channels.
//!
//! \param channel: CHANNEL0, CHANNEL1, CHANNEL2, CHANNEL3.
//!
//! \param status:  CHANNEL_OFF, CHANNEL_ON.
//
//*****************************************************************************
void BTS71220_channelOutputConfig(uint8_t channel, uint8_t status);

//*****************************************************************************
//
//! This function config parallel channels.
//!
//! \param parallel: OUT0_OUT3, OUT_1_OUT_2, BOTH.
//
//*****************************************************************************
void BTS71220_parallelChannelConfig(uint8_t parallel);

//*****************************************************************************
//
//! This function control the input combinatorial logic configuration.
//!
//! \param combine: OR_COMBINE, AND_COMBINE.
//
//*****************************************************************************
void BTS71220_inputCombinatorialLogicConfig(uint8_t combine);

//*****************************************************************************
//
//! This function config channels restart strategy.
//!
//! \param chanel:      Channel select.
//! \param strategy:    Automotic restart, Latch mode.
//
//*****************************************************************************
void BTS71220_restartStrategyConfig(uint8_t channel, uint8_t strategy);

//*****************************************************************************
//
//! This function clear all Restart Counters and Latches.
//
//*****************************************************************************
void BTS71220_clearRestartCounters(void);

//*****************************************************************************
//
//! This function reset the SPI registers to their default value but, Restart
//! counters will not be reset.
//
//*****************************************************************************
void BTS71220_resetCommand(void);




#endif /* DRIVERS_INC_HW_BTS712204ESAXUMA1_H_ */
