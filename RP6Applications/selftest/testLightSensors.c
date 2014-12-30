//
//  textLightSensors.c
//  RP6Applications
//
//  Created by Maximilian Voss on 23/12/14.
//  Copyright (c) 2014 Maximilian Voss. All rights reserved.
//

#include "testLightSensors.h"


scheduler_t sched_uart;
scheduler_t sched_led;
powermgmt_ADCStates_t *states;

uint16_t adcLSL;
uint16_t adcLSR;


void ledStats(void) {
    uint16_t sens_l;
    uint16_t sens_r;
    sens_l = states->adcLSL;
    sens_r = states->adcLSR;
        
    int16_t dif = ((int16_t)(sens_l - sens_r));
    if(dif > 160) dif = 160;
    if(dif < -160) dif = -160;
        
    // Set LEDs - a small bargraph display that shows which sensor has detected
    // brighter light - and how much brighter it is:
    if(dif > 140)
        setLEDs(0b111000);
    else if(dif > 75)
        setLEDs(0b011000);
    else if(dif > 35)
        setLEDs(0b001000);
    else if(dif > -35)
        setLEDs(0b001001);
    else if(dif > -75)
        setLEDs(0b000001);
    else if(dif > -140)
        setLEDs(0b000011);
    else
        setLEDs(0b000111);
}

void printUartStats(void) {
    uint16_t sens_l;
    uint16_t sens_r;
    sens_l = states->adcLSL;
    sens_r = states->adcLSR;
        
    uart_writeString_P("Left: ");
    uart_writeIntegerLength(sens_l, DEC, 4);
    uart_writeString_P(",  Right: ");
    uart_writeIntegerLength(sens_r, DEC, 4);
    uart_writeChar('\n');
}



void testLightSensors(powermgmt_ADCStates_t *ADCStates) {
    states = ADCStates;

    
    uart_writeString_P("\n### Light Sensor Test ###\n");
    uart_writeString_P("Please get yourself a small flashlight!\n");
    uart_writeString_P("While the test runs, move it in front of the Robot\n");
    uart_writeString_P("and watch if the values change accordingly!\n\n");
    uart_writeString_P("### The Test is running now.\n### Enter \"x\" and hit return to STOP this test!\n\n");
    mSleep(1000);
    
    uart_writeString_P("Performing measurements...:\n");
    uart_clearReceptionBuffer();
    
    sched_uart.cur_time = 0;
    sched_uart.exe_time = 3;
    sched_uart.func = *printUartStats;
    scheduler_regEvent(&sched_uart, EVENT_100);
    
    sched_led.cur_time = 0;
    sched_led.exe_time = 5;
    sched_led.func = *ledStats;
    scheduler_regEvent(&sched_led, EVENT_10);
    
    while(1)
    {
        if(getInputLine())
            break;
    }
    
    scheduler_unregEvent(&sched_uart, EVENT_100);
    scheduler_unregEvent(&sched_led, EVENT_10);
}