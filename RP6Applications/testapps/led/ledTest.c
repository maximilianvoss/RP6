#include <core/core.h>
#include <scheduler/scheduler.h>

uint8_t runningLight = 1;
uint8_t ledsDirection = 1;
scheduler_t sched_led;

void changeLed(void) {
    setLEDs(runningLight);
    
    if ( ledsDirection) {
        runningLight <<= 1;
        
        if ( runningLight > 32 ) {
            runningLight = 1;
            ledsDirection = 1;
        }
    }
}


int main(void) {
    init();
    scheduler();
    leds();
    
    sched_led.cur_time = 0;
    sched_led.exe_time = 2;
    sched_led.func = *changeLed;
    scheduler_regEvent(&sched_led, EVENT_100);
    

    while (1);
    
    return 0;
}

