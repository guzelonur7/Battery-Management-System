/*
 * midapp.c
 *
 *  Created on: Feb 8, 2024
 *      Author: User
 */

#include "C:\Users\User\Desktop\BMS\Prototips\3\Code\App\inc\midapp.h"


// READ CELL VOLTAGES
void readCellVoltages(float *cellVoltages)
{}

void getCellVotagesInteger(uint8_t *cellVoltagesInteger)
{

    uint8_t seriesCellCount = getSeriesCellCount();

    float cellVoltages[seriesCellCount] = { 0 };

    readCellVoltages(cellVoltages);
    uint8_t i = 0;
    for (i; i < seriesCellCount; i++)
        cellVoltagesInteger[i] = (uint8_t) (cellVoltages[i] / 1.0F);
}

void getCellVotagesDecimalHigh(uint8_t *cellVoltagesDecimalHigh)
{

    uint8_t seriesCellCount = getSeriesCellCount();

    float cellVoltages[seriesCellCount] = { 0 };

    readCellVoltages(cellVoltages);
    uint8_t i = 0;
    for (i; i < seriesCellCount; i++)
        cellVoltagesDecimalHigh[i] = (((uint16_t) (cellVoltages[i] * 1000F))
                % 1000) >> 8;
}

void getCellVotagesDecimalLow(uint8_t *cellVoltagesDecimal)
{

    uint8_t seriesCellCount = getSeriesCellCount();

    float cellVoltages[seriesCellCount] = { 0 };

    readCellVoltages(cellVoltages);
    uint8_t i = 0;
    for (i; i < seriesCellCount; i++)
        cellVoltagesDecimal[i] = ((uint16_t) (cellVoltages[i] * 1000F) % 1000)
                & 0x00FF;
}

// READ INSTANT CURRENT
float readInstantCurrent(uint8_t SENSOR)
{

    static uint16_t adcValue = 0;
    static float instantCurrent = 0.0f;

    ADC_forceSOC(ADCA_BASE, SENSOR);    // SENSOR: SOC NUMBER
    while (ADC_getInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1) == false);
    ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);
    adcValue = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER0);
    instantCurrent = (float) adcValue * 0.0008057; // 3.3/4095

    return instantCurrent;
}

uint8_t getCurrentDecimal(float instantCurrentValue)
{

    uint8_t result = 0;

    result = (uint8_t) (((instantCurrentValue * 1000) % 1000) / 3.921);
    // 1000 / 255 = 3.921

    return result;
}

uint8_t getCurrentIntegerLow(float instantCurrentValue){

    uint8_t result = 0;
    uint16_t resultBuffer = 0;

    resultBuffer = (uint16_t) instantCurrentValue;
    result = resultBuffer >> 8;

    return result;
}

uint8_t getCurrentIntegerHigh(float instantCurrentValue){

    uint8_t result = 0;
    uint16_t resultBuffer = 0;

    resultBuffer = (uint16_t) instantCurrentValue;
    result = (uint8_t) resultBuffer & 0x00FF;

    return result;
}

// READ TEMPERATURE SENSOR FUNCTIONS
float readTemperatureSensors(uint8_t SENSOR)
{
    static uint16_t adcValue = 0;
    static float temperature = 0.0F;

    ADC_forceSOC(ADCA_BASE, SENSOR);    // SENSOR: SOC NUMBER
    while (ADC_getInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1) == false);
    ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);
    adcValue = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER0);
    temperature = (float) adcValue * 0.0008057; // 3.3/4095

    return temperature;
}

// READ AUX CONTAC POSITION
bool readAuxContacPosition(uint8_t CHANNEL)
{

    static bool contacPosition = 0;

    contacPosition = GPIO_readPin(CHANNEL);

    return  contacPosition;
}


//
// CHECK SENSOR FUNCTIONS
//
void checkAuxContacPositions(uint8_t *errorContacArray)
{
    uint8_t i = 0;

    static uint8_t channelErrorFirstTime[4] = 0;
    static uint8_t channelErrorInstantTime[4] = 0;
    static uint8_t channelErrorElapsedTime[4] = 0;
    static uint8_t channelErrorTimeStartFlag[4] = 0;
    static uint8_t channelErrorConfigurationTime[4] = 0;

    static uint8_t channelErrorCheckActive[4] = 0;

    static uint8_t contacPosition = 0;
    static uint8_t auxContacPosition = 0;
    static uint8_t newConfigurationMessageFlag = 0;

    // newConfigurationMessageFlag: if there is a new message, it's a set.
    // readToFlashNewConfigurationMessageFlag(): This function will be written in the configuration messages reading section.
    // newConfigurationMessageFlag = readNewConfigMessageFlag();
    if (newConfigurationMessageFlag)
    {
        for (i = 0; i < 4; i++)
        {

            // channelErrorCheckActive[i] = readErrorSelectionConfigMessage();
            // channelErrorConfigurationTime[i] = 0; // '0' will be replaced with the flash read code.
        }
    }

    else
    {
    }   // Empty, exit block.

    for (i = 0; i < 4; i++)
    {
        if (channelErrorCheckActive[i])
        {
            // contacPosition = read operation mode from flash
            auxContacPosition = readAuxContacPosition(i);
            if (auxContacPosition == contacPosition)
            {

                channelErrorFirstTime[i] = 0;
                channelErrorTimeStartFlag[i] = 0;
            }

            else
            {
                if (channelErrorTimeStartFlag[i])
                {

                    // channelErrorInstantTime[i] = takeGlobalTime();
                    // channelErrorElapsedTime[i] = channelErrorInstantTime[i] - channelErrorFirstTime[i];
                    if (channelErrorElapsedTime[i]
                            > channelErrorConfigurationTime[i])
                        errorContacArray[i] = 1;
                    else
                    {
                    }  // No error. Empty, exit block.
                }

                else
                {
                    // channelErrorFirstTime = takeGlobalTime;
                    // channelErrorTimeStartFlag[i] = 1;
                }
            }
        }

        else
        {
        }  // Channel error check disable. Empty, exit block.
    }
}

////////////////////////////////////////////app to midapp/////////////////////////////////////////////////////////
//*******************************************
//
// readSensors
//
//*******************************************
void readSensors(bool *auxContacPositions, float *cellVoltages,
                 float *temperatures, float *instantCurrentAndTime)
{

    static uint8_t seriesCellCount = getSeriesCellCount();
    static bool newConfigMessageFlag = 0;

    newConfigMessageFlag = getNewConfigMessage();
    if (newConfigMessageFlag)
        seriesCellCount = getSeriesCellCount();

    uint8_t i = 0;

    for (i = 0; i < seriesCellCount; i++)
        cellVoltages[i] = readCellVoltages(i);

    for (i = 0; i < TEMPSENSORCOUNT; i++)
        temperatures[i] = readTemperatureSensors(i);

    for (i = 0; i < AUXCONTACCOUNT; i++)
        auxContacPositions[i] = readAuxContacPosition(i);

    instantCurrentAndTime[0] = readInstantCurrent;
    instantCurrentAndTime[1] = (float) getTimer0Count(); // sureyi veren bir fonksiyon yazilacak

}

//*******************************************
//
// readOperationModeMessage
//
//*******************************************
uint8_t readOperationModeMessage(void)
{

    uint8_t elapsedTime = 0; // gecen sure cinsi ms cinsinden ve virgulsuz olacak sekilde guncellenecek.
    static uint8_t result = 0;
    bool flagNewCANMessage = 0;
    static uint32_t instantTime = 0;
    static uint8_t canMessage[8] = { 0 };
    static uint32_t previousTime = 1000000;

    instantTime = getTimer0Count();

    // if the timer counter restarted.
    if (instantTime > previousTime)
        previousTime = 1000000;

    elapsedTime = previousTime - instantTime;
    if (elapsedTime > 1000)
    {

        // CAN mesaj yapisi kontrol edilecek. (kac byte gonderecegi)
        flagNewCANMessage = CAN_readMessage(myCAN0_BASE, 2, canMessage);
        result = canMessage[0];
        if (flagNewCANMessage)
            result = ERROR;
        previousTime = getTimer0Count();
    }

    return (result);
}

//*******************************************
//
// checkErrors
//
//*******************************************
void checkErrors(bool *errors)
{
    static uint8_t seriesCellCount = getSeriesCellCount();
    static bool auxContacErrors[AUXCONTACCOUNT] = {0};
    static bool temperatureErrorMin[TEMPSENSORCOUNT] = {0};
    static bool temperatureErrorMax[TEMPSENSORCOUNT] = {0};
    static bool cellVoltageErrorsMin[seriesCellCount] = {0};
    static bool cellVoltageErrorsMax[seriesCellCount] = {0};
    static bool packageVoltageMinError = 0;
    static bool packageVoltageMaxError = 0;
    static bool instantCurrentError = 0;
    static bool packageHealthError = 0;
    static bool packageCapacityErrorMin = 0;
    static bool packageCapacityErrorMax = 0;
    static bool connectionLostError = 0;

    connectionLostError = checkHostConneciton();
    packageVoltageMinError = checkPackageVoltageMin();
    packageVoltageMaxError = checkPackageVoltageMax();
    instantCurrentError = checkInstantCurrent();
    packageHealthError = checkPackageHealth();
    packageCapacityErrorMin = checkPackageCapacityMin();
    packageCapacityErrorMax = checkPackageCapacityMax();
    checkAuxContacPositions(auxContacErrors);
    checkCellVoltagesMin(cellVoltageErrorsMin);
    checkCellVoltagesMax(cellVoltageErrorsMax);
    checkTemperaturesMin(temperatureErrorMin);
    checkTemperaturesMax(temperatureErrorMax);

    // tum hatalari birlestir. errorSaveArray = ...
}

/////////////////////////////////////////////////////////eski fonksiyonlar///////////////////////////////
//*******************************************
//
// getTimerTime
//
//*******************************************
uint64_t getTimer0Count()
{
    //
    // Function variables.
    //
    uint64_t result = 0;

    //
    // Taking timer0 counter value.
    //
    result = CPUTimer_getTimerCount(myCPUTIMER0_BASE);
    return result;
}

//*******************************************
//
// calculateCapacity
//
//*******************************************
float64_t calculateCapacity()
{
    //
    // Local static variables.
    //
    static float64_t batteryCapacity = 100.0F;
    static float32_t instantCapacity = 0.0F;
    static uint32_t previousTimerCount = 1000000;

    //
    // Local variables.
    //
    float32_t elapsedTime = 0.0F;
    float32_t instantCurrent = 0.0F;
    uint32_t currentTimerCount = 0;

    //
    // Read instant current, calculate elapsed time.
    //
    instantCurrent = readCurrent(SHUNT);
    currentTimerCount = getTimer0Count();
    elapsedTime = calculateElapsedTime(previousTimerCount, currentTimerCount);

    //
    // if there is no error, calculate capacity.
    // Capacity = Time(ms) * Instant Current(A) * Capacity Const
    //
    if ((previousTimerCount > currentTimerCount) && (instantCurrent != ERROR))
    {
        instantCapacity = (instantCurrent * elapsedTime * CAPACTY_CONST);
        batteryCapacity += instantCapacity;
        previousTimerCount = currentTimerCount;
        return batteryCapacity;
    }

    else
    {
        batteryCapacity += instantCapacity;
        previousTimerCount = currentTimerCount;
        return ERROR;
    }
}

