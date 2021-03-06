#include <core/core.h>
#include <uart/uart.h>
#include <scheduler/scheduler.h>

scheduler_t sched_uart;


void heartbeat(void) {

    char buf[255];
    uint8_t bufLength;
    
    bufLength = readChars(buf, 254);
    if ( bufLength > 0) {
        uart_writeString_P("Echo: ");
        uart_writeStringLength(buf, bufLength, 0);
        uart_writeString_P("\n");
    }

}

int main(void) {
	init();
    scheduler();
	uart();
    
    
    sched_uart.cur_time = 0;
    sched_uart.exe_time = 1;
    sched_uart.func = *heartbeat;
    scheduler_regEvent(&sched_uart, EVENT_100);

    while (1);
	
	return 0;
}
