/*
 * app.c
 *
 *  Created on: Dec 5, 2023
 *      Author: User
 */

#include "C:\Users\User\Desktop\BMS\Prototips\3\Code\App\inc\app.h"

#define TEMPSENSORCOUNT 4
#define AUXCONTACCOUNT  4
#define TOTALERRORCOUNT 25

enum contactorControl{

    OFF,
    ON
};

enum contactorChannels{

    CHANNEL0,
    CHANNEL1,
    CHANNEL2,
    CHANNEL3,
    ALL
};

enum operationMode {

    BALANCE,
    DISCHARGE,
    CHARGE
};

//*******************************************
//
// readConfigMessagesWriteToFlash
//
//*******************************************
bool readConfigMessagesWriteToFlash(void)
{

    bool result = 0;
    bool newMessageFlag[8] = 0;

    static uint8_t limitData1[8] = 0;
    static uint8_t limitData2[8] = 0;
    static uint8_t errorTimes1[8] = 0;
    static uint8_t errorTimes2[8] = 0;
    static uint8_t errorSelection[8] = 0;
    static uint8_t featureUsage[8] = 0;
    static uint8_t offsetConfig[8] = 0;


    newMessageFlag[0] = CAN_readMessage(myCAN0_BASE, 1, limitData1);
    newMessageFlag[1] = CAN_readMessage(myCAN0_BASE, 2, limitData2);
    newMessageFlag[2] = CAN_readMessage(myCAN0_BASE, 3, errorSelection);
    newMessageFlag[3] = CAN_readMessage(myCAN0_BASE, 4, errorTimes1);
    newMessageFlag[4] = CAN_readMessage(myCAN0_BASE, 5, errorTimes2);
    newMessageFlag[5] = CAN_readMessage(myCAN0_BASE, 6, featureUsage);
    newMessageFlag[6] = CAN_readMessage(myCAN0_BASE, 7, offsetConfig);

    uint8_t i = 0;
    for (i = 0; i < 8; i++)
        result |= newMessageFlag[i];

    if (result)
    {
        //writeToFlash(limitData1);
        //writeToFlash(limitData2);
        //writeToFlash(errorTime1);
        //writeToFlash(errorTime2);
        //writeToFlash(errorSelection);
        //writeToFlash(featureUsage);
    }

    return (result);
}

//*******************************************
//
// sendAllData
//
//*******************************************
void sendAllData(void)
{

    static uint8_t seriesCellCount = getSeriesCellCount();
    static uint8_t cellVoltagesInteger[seriesCellCount] = {0};
    static uint8_t cellVoltagesDecimal[seriesCellCount] = {0};
    static uint8_t temperatures[TEMPSENSORCOUNT] = { 0 };
    static bool errors[TOTALERRORCOUNT] = {0};

    static uint8_t currentIntegerLow = 0;
    static uint8_t currentIntegerHigh = 0;
    static uint8_t currentDecimal = 0;

    getCellVotagesInteger(cellVoltagesInteger);
    getCellVotagesDecimal(cellVoltagesDecimal);

    currentDecimal = getCurrentDecimal();
    currentIntegerLow = getCurrentIntegerLow();
    currentIntegerHigh = getCurrentIntegerHigh();

    getTemperatures(temperatures, TEMPSENSORCOUNT);

    checkErrors(errors);
}

//*******************************************
//
// operationModeLauncher
//
//*******************************************
void operationModeLauncher(void)
{

    static uint8_t operationMode = 0;
    static uint8_t operationModeBuffer = 0xFF; // must be different from
                                               // zero to enter balance mode for the first time.
    static bool flagOfSystemDisable = 0;
    static bool systemRestartMessage = 0;
    static bool flagOfModeChange = 0;

    flagOfSystemDisable = getFlagSystemDisable();
    if (flagOfSystemDisable)
    {
        contactorControl(OFF, ALL);
        operationMode = 0;
        while (!systemRestartMessage)
            systemRestartMessage = readSystemRestartMessage();
    }

    else
    {
        operationMode = getOperationMode();
        if (operationMode == operationModeBuffer)
            flagOfModeChange = 0;
        else
            flagOfModeChange = 1;

        switch (operationMode)
        {
        case BALANCE:
            modeBalancing(flagOfModeChange);
            break;

        case DISCHARGE:
            modeDischarge(flagOfModeChange);
            break;

        case CHARGE:
            modeCharge(flagOfModeChange);
            break;
        }
        operationModeBuffer = operationMode;
    }
}

//
// End of the file.
//
