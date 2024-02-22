
//
// Included Files
//
#include "C:\Users\User\Desktop\BMS\Prototips\3\Code\App\inc\app.h"

//
// Global main variables.
//


void main(void)
{

    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Disable pin locks and enable internal pullups.
    //
    Device_initGPIO();

    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    //
    // Board initialization
    //
    Board_init();

    //
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    //
    EINT;
    ERTM;

    //
    // Loop forever. Suspend or place breakpoints to observe the buffers.
    //

    // ADC REFERANCE CODES
    // --------------------
    // ADC_forceSOC(ADCA_BASE, ADC_SOC_NUMBER0);
    // while(ADC_getInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1) == false);
    // ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);
    // adc = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER0);
    //

    // uint8_t date[8];
    // uint8_t CAN_DATA[8] = {0,0,0,0,0,0,0,0};
    // PCA85073_getDate(date);
    // CAN_sendMessage(myCAN0_BASE, 1, MSG_DATA_LENGHT, CAN_DATA);
    // CPUTimer_getTimerCount(myCPUTIMER0_BASE);
    // capacity = calculateCapacity();

    //uint16_t mode[1] = { 0 };
    //float64_t capacity = 0.0F;
    //uint16_t adc = 0;
    //uint16_t CAN_RxData[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    //uint16_t CAN_TxData[8] = { 0, 1, 8, 8, 8, 8, 8, 8 };

    //uint32_t errorArray[10] = {0};
    //uint16_t CAN_modeMessage[1] = {0};
    //uint16_t BFR_modeMessage = ModeOff;


    //errorArray[0] = get_modeMessage(CAN_modeMessage);

    //if(CAN_modeMessage[0] != BFR_modeMessage){
        //BFR_modeMessage = CAN_modeMessage[0];
        //errorArray[1] = setMode(BFR_modeMessage);
    //}

    //PreChargeContactorEnable();
    //BTS71220_currentSenseRatioRangeConfig(CHANNEL1,LOW_RANGE);
    //ADC_forceSOC(ADCA_BASE, ADC_SOC_NUMBER0);
    //while(ADC_getInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1) == false);
    //ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);
    //adc = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER0);

    //BTS71220_currentSenseRatioRangeConfig(CHANNEL1, HIGH_RANGE);
    //ADC_forceSOC(ADCA_BASE, ADC_SOC_NUMBER0);
    //while (ADC_getInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1) == false);
    //ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);
    //adc = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER0);

    // Get Mode Message
    //CAN_TX_DATA[0] = get_modeMessage(mode);
    //CAN_TX_DATA[1] = mode[0];

    // Calculate capacity
    //capacity = calculateCapacity();
    //capacity *= 1000;
    //capacity -= 100000;
    //CAN_TX_DATA[2] = (uint16_t) capacity;


    // Send messages
    //CAN_sendMessage(myCAN0_BASE, 1, MSG_DATA_LENGHT, CAN_TX_DATA);
    //DEVICE_DELAY_US(500);


    // 500 ms start-up delay.
    //DEVICE_DELAY_US(500000);

    while (1)
    {

       readConfigMessagesWriteToFlash();
       sendAllData();
       operationModeLauncher();

    }
}

//
// End File
//
