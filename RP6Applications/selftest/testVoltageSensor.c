//
//  testVoltageSensor.c
//  RP6Applications
//
//  Created by Maximilian Voss on 23/12/14.
//  Copyright (c) 2014 Maximilian Voss. All rights reserved.
//

#include "testVoltageSensor.h"

void testVoltageSensor(powermgmt_ADCStates_t *ADCStates){
    
    uart_writeString_P("\n### Voltage Sensor Test ###\n");
    uart_writeString_P("Be sure that you are using good accumulators!\n");

    uart_writeString_P("Performing 10 measurements:\n");
    uint16_t ubat;
    uint8_t i;
    for(i = 1; i <= 10; i++)
    {
        uart_writeString_P("Measurement #");
        uart_writeInteger(i, DEC);
        uart_writeString_P(": ");
        ubat = ADCStates->adcBat;
        printUBat(ubat);
        
        if(ubat >= 570 && ubat <= 970)
        {
            uart_writeString_P(" --> OK!\n");
        }
        else
        {
            uart_writeString_P("\nWARNING: VOLTAGE IS TOO ");
            if(ubat < 570) 
            {
                uart_writeString_P("LOW");
            }
            else if(ubat > 970)
            {
                uart_writeString_P("HIGH");
            }
            uart_writeString_P(" (should be min. 5.50V to max. 9.50V)!\n");
        }
        mSleep(200);
    }
}
