#include "sleep.h"

scheduler_t schedmSleep;

void sleepInit(void) {
    schedmSleep.cur_time = 0;
    schedmSleep.exe_time = 65535;
    schedmSleep.func = NULL;
    scheduler_regEvent(&schedmSleep, EVENT_1);
}


void mSleep(uint16_t time) {
    uint16_t currentTime = schedmSleep.cur_time;
    uint16_t stopTime;
    
    if ( time > 65535 - currentTime) {
        stopTime = time - (65535 - currentTime);
    } else {
        stopTime = currentTime + time;
    }
    
    while ( stopTime != schedmSleep.cur_time);
}