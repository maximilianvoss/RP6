#include <core/core.h>
#include <uart/uart.h>
#include <scheduler/scheduler.h>
#include <engine/engine.h>

scheduler_t sched_uart;


void heartbeat(void) {
    uart_writeString_P("Heartbeat\n");
}

int main(void) {
	init();
    scheduler();
	uart();
    engine();
    
    
    sched_uart.cur_time = 0;
    sched_uart.exe_time = 1;
    sched_uart.func = *heartbeat;
    scheduler_regEvent(&sched_uart, EVENT_1000);

    engine_setHWDirection(1,1);
    engine_setHWPower(100, 100);
    
    while (1);
	
	return 0;
}
