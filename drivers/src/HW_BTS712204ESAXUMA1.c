/*
 * BTS712204ESAXUMA1.c
 *
 *  Created on: Aug 11, 2023
 *      Author: User
 */

#include "C:\Users\User\Desktop\BMS\Prototips\3\Code\drivers\inc\HW_BTS712204ESAXUMA1.h"

//*****************************************************************************
//
//! BTS71220_writeRegisters
//
//*****************************************************************************
void BTS71220_writeRegisters(uint8_t data){

    GPIO_writePin(BTS71220_chip_select, 0);
    DEVICE_DELAY_US(100);
    SPI_transmitByte(mySPI0_BASE,data);
    GPIO_writePin(BTS71220_chip_select, 1);
    DEVICE_DELAY_US(100);
}

//*****************************************************************************
//
//! BTS71220_readRegisters
//
//*****************************************************************************
uint8_t BTS71220_readRegisters(uint8_t address){

    uint8_t result = 0;

    BTS71220_writeRegisters(address);
    GPIO_writePin(BTS71220_chip_select, 0);
    DEVICE_DELAY_US(1000);
    result = SPI_receiveByte(mySPI0_BASE,address);
    GPIO_writePin(BTS71220_chip_select, 1);
    DEVICE_DELAY_US(1000);

    return result;
}

//*****************************************************************************
//
//! BTS71220_readWarningDiag
//
//*****************************************************************************

uint8_t BTS71220_readWarningDiag(void){

    uint8_t warning_result = 0;
    warning_result = BTS71220_readRegisters(READ_WRNDIAG);

    return warning_result;
}

//*****************************************************************************
//
//! BTS71220_readErrorDiag
//
//*****************************************************************************
uint8_t BTS71220_readErrorDiag(void){

    uint8_t error_result = 0;
    error_result = BTS71220_readRegisters(READ_ERRDIAG);

    return error_result;
}

//*****************************************************************************
//
//! BTS71220_readStandardDiag
//
//*****************************************************************************
uint8_t BTS71220_readStandardDiag(void){

    uint8_t standard_result = 0;
    standard_result = BTS71220_readRegisters(READ_STDDIAG);

    return standard_result;
}


//*****************************************************************************
//
//! BTS71220_readInputStatus
//
//*****************************************************************************
uint8_t BTS71220_readInputStatus(void){

    uint8_t result = 0;

    result = BTS71220_readRegisters(READ_ICS);

    return result;
}

//*****************************************************************************
//
//! BTS71220_switchRegister
//
//*****************************************************************************
void BTS71220_switchRegister(uint8_t switchPosition){

    uint8_t switch_data = BTS71220_readRegisters(READ_DCR);

    if (switchPosition == POSITION_0){

        switch_data &= ~(1 << 3);
        BTS71220_writeRegisters(switch_data);
    }

    else if (switchPosition == POSITION_1){

        switch_data |= 1 << 3;
        BTS71220_writeRegisters(switch_data);
    }
}

//*****************************************************************************
//
//! BTS71220_overcurrentLevelConfig
//
//*****************************************************************************
void BTS71220_overCurrentLevelConfig(uint8_t channel, uint8_t level){

    BTS71220_switchRegister(POSITION_0);

    uint8_t oc_level = 0;
    oc_level = BTS71220_readRegisters(READ_OCR);

    if (level == LOW_LEVEL){

        oc_level &= ~(1 << channel);
        BTS71220_writeRegisters(oc_level);
    }

    else if (level == HIGH_LEVEL){

        oc_level |= 1 << channel;
        BTS71220_writeRegisters(oc_level);
    }
}

//*****************************************************************************
//
//! BTS71220_currentSenseRatioRangeConfig
//
//*****************************************************************************
void BTS71220_currentSenseRatioRangeConfig(uint8_t channel, uint8_t range){

    BTS71220_switchRegister(POSITION_0);

    uint8_t ratio_range = 0;
    ratio_range = BTS71220_readRegisters(READ_KRC);

    if (range == LOW_RANGE){

        ratio_range &= ~(1 << channel);
        BTS71220_writeRegisters(ratio_range);
    }

    else if (range == HIGH_RANGE){

        ratio_range |= 1 << channel;
        BTS71220_writeRegisters(ratio_range);
    }
}

//*****************************************************************************
//
//! BTS71220_setMultiplexerConfig
//
//*****************************************************************************
void BTS71220_setMultiplexerConfig(uint8_t mode){

    uint8_t mux_state = 0;

    // DCR REGISTER CONFIG
    switch(mode){

    case CH0_ROUTED:
        mux_state = 0xF8;  // 1111 1000
        break;

    case CH1_ROUTED:
        mux_state = 0xF9;  // 1111 1001
        break;

    case CH2_ROUTED:
        mux_state = 0xFA;  // 1111 1010
        break;

    case CH3_ROUTED:
        mux_state = 0xFB;  // 1111 1011
        break;

    case NON_ROUTED:
        mux_state = 0xFC;  // 1111 1100
        break;
    }

    BTS71220_writeRegisters(mux_state);
}

//*****************************************************************************
//
//! BTS71220_channelOutputConfig
//
//*****************************************************************************
void BTS71220_channelOutputConfig(uint8_t channel, uint8_t status){

    uint8_t channel_level = 0;

    BTS71220_setMultiplexerConfig(channel);

    channel_level = BTS71220_readRegisters(READ_OUT);

    if(status == CHANNEL_OFF){

        channel_level &= ~(1 << channel);
        BTS71220_writeRegisters(channel_level);
    }

    else if(status == CHANNEL_ON){

        channel_level |= 1 << channel;
        BTS71220_writeRegisters(channel_level);
    }
}

//*****************************************************************************
//
//! BTS71220_parallelChannelConfig
//
//*****************************************************************************
void BTS71220_parallelChannelConfig(uint8_t parallel){

    BTS71220_switchRegister(POSITION_1);

    uint8_t parallel_data = 0;
    parallel_data = WRITE_PCS;

    switch(parallel){

    case INDEPENTEND:
        parallel_data &= 0xF3;      // 0b 1111 0011
        break;

    case OUT0_OUT3:
        parallel_data |= 0x04;      // 0b 0000 0100
        break;

    case OUT1_OUT2:
        parallel_data |= 0x08;      // 0b 0000 1000
        break;

    case BOTH:
        parallel_data |= 0x0C;      // 0b 0000 1100
        break;
    }

    BTS71220_writeRegisters(parallel_data);
}

//*****************************************************************************
//
//! BTS71220_inputCombinatorialLogicConfig
//
//*****************************************************************************
void BTS71220_inputCombinatorialLogicConfig(uint8_t combine){

    BTS71220_switchRegister(POSITION_0);

    uint8_t combine_type = 0;
    combine_type = BTS71220_readRegisters(READ_HWCR);

    if(combine == OR_COMBINE){

        combine_type &= ~(1 << 2);
        BTS71220_writeRegisters(combine_type);
    }

    else if(combine == AND_COMBINE){

        combine_type |= 1 << 2;
        BTS71220_writeRegisters(combine_type);
    }
}

//*****************************************************************************
//
//! BTS71220_restartStrategyConfig
//
//*****************************************************************************
void BTS71220_restartStrategyConfig(uint8_t channel, uint8_t strategy){

    BTS71220_switchRegister(POSITION_1);

    uint8_t strategy_data = 0;
    strategy_data = WRITE_RCD;

    if(strategy == AUTOMATIC_MODE){

        strategy_data &= (1 << channel);
        BTS71220_writeRegisters(strategy_data);
    }

    else if(strategy == LATCH_MODE){

        strategy_data |= 1 << channel;
        BTS71220_writeRegisters(strategy_data);
    }

    BTS71220_switchRegister(POSITION_0);
}

//*****************************************************************************
//
//! BTS71220_clearRestartCounters
//
//*****************************************************************************
void BTS71220_clearRestartCounters(void){

    BTS71220_switchRegister(POSITION_0);

    uint8_t clear = 0;
    clear = WRITE_HWCR;

    clear |= 1 << 0;
    BTS71220_writeRegisters(clear);
}

//*****************************************************************************
//
//! BTS71220_resetCommand
//
//*****************************************************************************
void BTS71220_resetCommand(void){

    BTS71220_switchRegister(POSITION_0);

    uint8_t reset = 0;
    reset = WRITE_HWCR;

    reset |= 1 << 1;
    BTS71220_writeRegisters(reset);
}

// End of the file.
