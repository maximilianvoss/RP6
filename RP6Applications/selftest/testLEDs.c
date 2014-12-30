//
//  testLEDs.c
//  RP6Applications
//
//  Created by Maximilian Voss on 23/12/14.
//  Copyright (c) 2014 Maximilian Voss. All rights reserved.
//

#include "testLEDs.h"

void testLEDs(void){
    uart_writeString_P("\n### LED Test ###\n");
    uart_writeString_P("Please watch the LEDs and verify that they all work!\n");
    mSleep(1000);
    setLEDs(0b111111);
    mSleep(500);
    setLEDs(0b000000);
    mSleep(500);
    setLEDs(0b111111);
    mSleep(500);
    setLEDs(0b000000);
    mSleep(250);
    uint8_t testLEDs = 1;
    uint8_t i;
    for(i = 0; i < 12; i++){
        setLEDs(testLEDs);
        testLEDs <<= 1;
        if(testLEDs > 63)
            testLEDs = 1;
        mSleep(400);
    }
    setLEDs(0b111111);
    mSleep(400);
    setLEDs(0b000000);
}
