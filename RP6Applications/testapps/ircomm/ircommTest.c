#include <core/core.h>
#include <uart/uart.h>
#include <ircomm/ircomm.h>
#include <ircommAcs/rc5data.h>

void IRCOMM_RC5dataReady_DUMMY(RC5data_t *rc5data) {
    uart_writeString_P("Data: ");
    uart_writeInteger(rc5data->data, 10);
    uart_writeString_P("\nKey Code: ");
    uart_writeInteger(rc5data->key_code, 10);
    uart_writeString_P("\nDevice: ");
    uart_writeInteger(rc5data->device, 10);
    uart_writeString_P("\nToggle: ");
    uart_writeInteger(rc5data->toggle_bit, 10);
    uart_writeString_P("\nReserved: ");
    uart_writeInteger(rc5data->reserved, 10);
    uart_writeString_P("\n");
 }


int main(void) {
    RC5data_t rc5data;
    rc5data.data = 12320;
    
    init();
    
    uart();
    
    uart_writeString_P("Huhu");
    
    IRCOMM_RC5dataReady_DUMMY(&rc5data);
    
    ircomm();
    //acs();
    ircomm_setRC5DataHandler(IRCOMM_RC5dataReady_DUMMY);
    //acs_ircomm_send(&rc5data);

    while (1);
    
    return 0;
}
