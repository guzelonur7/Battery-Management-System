/*
 * librarys.h
 *
 *  Created on: Dec 26, 2023
 *      Author: User
 */

#ifndef DRIVERS_INC_HW_LIBRARYS_H_
#define DRIVERS_INC_HW_LIBRARYS_H_

#include <stdint.h>
#include <stdbool.h>
#include "board.h"      // For system configurations
#include "device.h"     // For device configurations
#include "driverlib.h"  // For peripheral libraries

//
// Error enumerations.
//
enum{

    NO_ERROR = 0,
    ERROR = 0xFF
};


#endif /* DRIVERS_INC_HW_LIBRARYS_H_ */
