//
//  testBumpers.c
//  RP6Applications
//
//  Created by Maximilian Voss on 23/12/14.
//  Copyright (c) 2014 Maximilian Voss. All rights reserved.
//

#include "testBumpers.h"

void testBumpers(void){
    
    LEDs_t *statusLEDs = getStatusLEDs();
    
    uart_writeString_P("\nBumper Test\n");
    uart_writeString_P("Please hit both bumpers and verify \n");
    uart_writeString_P("that both Bumpers are working properly!\n\n");
    uart_writeString_P("### The Test is running now.\n### Enter \"x\" and hit return to STOP this test!\n\n");

    while(1)
    {
        if(getInputLine())
            break;
        
        static uint8_t info_left = 0;
        static uint8_t info_right = 0;
        uint8_t bumper_left = isBumperLeft();
        uint8_t bumper_right = isBumperRight();
        
        if(bumper_left)
        {
            if(!info_left)
            {
                uart_writeString_P("OBSTACLE: LEFT!\n");
                info_left = 1;
            }
        }
        else if(info_left)
        {
            uart_writeString_P("FREE: LEFT!\n");
            info_left = 0;
        }
        if(bumper_right)
        {
            if(!info_right)
            {
                uart_writeString_P("OBSTACLE: RIGHT!\n");
                info_right = 1;
            }
        }
        else if(info_right) 
        {
            uart_writeString_P("FREE: RIGHT!\n");
            info_right = 0;
        }
        statusLEDs->LED4 = (!bumper_left);
        statusLEDs->LED1 = (!bumper_right);
        updateLEDs();
        mSleep(50);
    }
    setLEDs(0b000000);
}
