//
//  testPowerOn.c
//  RP6Applications
//
//  Created by Maximilian Voss on 23/12/14.
//  Copyright (c) 2014 Maximilian Voss. All rights reserved.
//

#include "testPowerOn.h"


void testPowerOn(void){
    uart_writeString_P("Power On/Off test\n");
    
    uart_writeString_P("Power Off\n");
    ledPowerOff();
    uart_writeString_P("Power Off2\n");
    //mSleep(1000);
    
    uart_writeString_P("Power On\n");
    ledPowerOn();
    //mSleep(1000);
    
    uart_writeString_P("Power Off\n");
    ledPowerOff();
    //mSleep(1000);
    
    uart_writeString_P("Power On\n");
    ledPowerOn();
    //mSleep(1000);
    
    uart_writeString_P("Power Off\n");
    ledPowerOff();
    //mSleep(1000);
}