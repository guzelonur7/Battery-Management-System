/*
 * MW_BTS712204ESAXUMA1.c
 *
 *  Created on: Dec 25, 2023
 *      Author: User
 */

#include"C:\Users\User\Desktop\BMS\Prototips\3\Code\middleware\inc\MW_BTS712204ESAXUMA1.h"

uint32_t preChargeContactorEnable()
{

    uint32_t error = 0;
    BTS71220_channelOutputConfig(CHANNEL1, CHANNEL_ON);
    error = BTS71220_loadCurrentCheck(CHANNEL1, CHANNEL_ON);
    DEVICE_DELAY_US(10000);
    return (error);
}

uint32_t preChargeContactorDisable()
{

    uint32_t error = 0;
    BTS71220_channelOutputConfig(CHANNEL1, CHANNEL_OFF);
    error = BTS71220_loadCurrentCheck(CHANNEL1, CHANNEL_OFF);
    DEVICE_DELAY_US(10000);
    return (error);
}

uint32_t loadPositiveContactorEnable()
{

    uint32_t error = 0;
    BTS71220_channelOutputConfig(CHANNEL0, CHANNEL_ON);
    error = BTS71220_loadCurrentCheck(CHANNEL0, CHANNEL_ON);
    DEVICE_DELAY_US(10000);
    return (error);
}

uint32_t loadPositiveContactorDisable()
{

    uint32_t error = 0;
    BTS71220_channelOutputConfig(CHANNEL0, CHANNEL_OFF);
    error = BTS71220_loadCurrentCheck(CHANNEL0, CHANNEL_OFF);
    DEVICE_DELAY_US(10000);
    return (error);
}

uint32_t allContactorDisable(void)
{

    uint32_t error = 0;
    error = preChargeContactorDisable();
    error = loadPositiveContactorDisable();

    return (error);
}

uint32_t BTS71220_loadCurrentCheck(uint8_t channel, uint8_t status)
{

    float32_t current = 0.0F;
    uint32_t error = NO_ERROR;

    BTS71220_setMultiplexerConfig(channel);
    current = BTS71220_readChannelCurrent(channel);

    switch (status)
    {
    case CHANNEL_OFF:
        if (current > 0.1)
            error = ERROR;
        break;

    case CHANNEL_ON:
        if (current < 0.1)
            error = ERROR;
    }

    return (error);
}

float32_t BTS71220_readChannelCurrent(uint8_t channel)
{

    uint16_t adcResult = 0;
    float32_t current = 0.0F;

    ADC_forceSOC(ADCA_BASE, ADC_SOC_NUMBER0);
    while (ADC_getInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1) == false)
        ;
    ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);
    adcResult = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER0);
    current = (3.3F / 4096.0F) * adcResult;

    if (channel == CHANNEL0)
    {
        // ch 0, current constant
        current *= 4.059F;
    }

    else if (channel == CHANNEL1)
    {
        // ch 1, current constant
        current *= 0.53;
    }

    return (current);
}
