/*
 * AD7171.h
 *
 *  Created on: Aug 11, 2023
 *      Author: User
 */

// *****************************************************************************
//
//! --> AD7171 16-Bit ADC IC.
//!
//! 1-  When the ADC cycle is complete, the DOUT/RDY pin goes low.
//!
//! 2-  When enough SCLK pulses are applied, a 24-bit word is placed on the
//!     DOUT/RDY pin.
//!
//! 3-  If the conversion is not read, DOUT/RDY goes high. When the DOUT/RDY
//!     pin is high, this means that no readings will be made from the device.
//!
//! 4-  The data register is updated for every conversion. So, when a
//!     conversion is complete, the serial interface is reset and the new
//!     conversion is placed in the data register.
//!
//! 5-  The user must ensure that the entire word is read before the next
//!     conversion is completed.
//!
//! 6-  Of these 24 bits, 16 are conversion result and 8 are status bits.
//!
//! -----------------------------------------------------------------------------
//!
//! --> Status Bits:
//!     ------------
//! --> RDY | 0 | ERR | ID1 | ID0 | PAT2 | PAT1 | PAT0
//!
//! 1-  RDY:              This is conversion ready bit. If conversion completed,
//!                       bit set low.
//!
//! 2-  0:                This bit set to 0.
//!
//! 3-  ERR:              If an error occurs during the ADC conversion, this bit
//!                       is set high. For example, when the analog input is
//!                       outside range.
//!
//! 4-  ID1, ID0:         This bits are ID bits. Bit ID1 is set to 0, bit ID0 is
//!                       set to 1, for the AD7171.
//!
//! 5-  PAT2, PAT1, PAT0: This bits are status pattern bits. This bits are set
//!                       to '1 0 1' by default. When reads the data from
//!                       AD7171, user can check this bits. if the PAT2, PAT1,
//!                       PAT0 bits are different from their default values,
//!                       it means that the serial transfer from the ADC is
//!                       not performed correctly.
//!
//! ----------------------------------------------------------------------------
//!
//! --> PDRST:
//!
//! 1- When PDRST is low, the DOUT/RDY pin is High Impedance.
//!
//! 2- When PDRST is taken high, the internal clock requires 1ms, approximately,
//!     to power up.
//!
//! 3- Following this, the ADC continuously converts.
//!
//! 4- The first conversion requires the complete settling time (25ms).
//!
//! 5- DOUT/RDY goes high when PDRST is taken high and returns low only when a
//!   conversion is available.
//!
//! 6- The ADC then converts continuously, subsequent conversions being
//!    available at 125 Hz (8 mS each conversion).
//
// *****************************************************************************

#ifndef DRIVERS_INC_HW_AD7171_H_
#define DRIVERS_INC_HW_AD7171_H_

#include"C:\Users\User\Desktop\BMS\Prototips\3\Code\drivers\inc\HW_librarys.h"

#define AD7171_REFV 4.069F

//*****************************************************************************
//
//! This function combines 24-bit data from AD7171.
//!
//! \param None.
//!
//! \note Example of combined data:
//!
//! byte3       | byte2       | byte1      | byte0
//! -----------------------------------------------------------
//!   0(Empty)  | Data(MSB)   | Data(LSB)  | Data(Status byte)
//!
//! \return 32-bit AD7171 data.
//
//*****************************************************************************
uint32_t AD7171_readData(void);

//*****************************************************************************
//
//! This function checks data error.
//!
//! \param 32-Bit data read from AD7171.
//!
//! \return error state, NO_ERROR = 0, NO_ERROR = FFFFFFFF
//
//*****************************************************************************
uint32_t AD7171_errorCheck(uint32_t data);

//*****************************************************************************
//
//! This function calculates voltage.
//!
//! \param 32-Bit data read from AD7171.
//!
//! \return float32-Bit voltage result.
//
//*****************************************************************************
float32_t AD7171_calculateVoltage(uint32_t data);



#endif /* DRIVERS_INC_HW_AD7171_H_ */
