#include "selftest.h"

powermgmt_ADCStates_t *ADCStates;
char receiveBuffer[UART_RECEIVE_BUFFER_SIZE];

void printUBat(uint16_t uBat)
{
    uart_writeIntegerLength((((uBat/102.4f)+0.1f)), DEC, 2);
    uart_writeChar('.');
    uart_writeIntegerLength((((uBat/1.024f)+10)), DEC, 2);
    uart_writeChar('V');
}

uint8_t getInputLine(void)
{
	static uint8_t buffer_pos = 0;
	if(uart_getBufferLength())
	{
		receiveBuffer[buffer_pos] = uart_readChar();
		if(receiveBuffer[buffer_pos]=='\n')
		{
			receiveBuffer[buffer_pos]='\0';
			buffer_pos = 0;
			return 1;
		}
		else if(buffer_pos >= UART_RECEIVE_BUFFER_SIZE -1)
		{
			receiveBuffer[UART_RECEIVE_BUFFER_SIZE -1]='\0';
			buffer_pos = 0;
			return 2;
		}
		buffer_pos++;
	}
	return 0;
}

void enterString(void)
{
    while(!getInputLine());
}


void testMotorsAndEncoders(void){}

void speed_control(void) {}

void testMoveDistance(void) {}

void testEncoderDutyCycle(void) {}


int main(void) {
    init();
    scheduler();
    uart();
    powermgmt();
    
	uint8_t test = 0;
    ADCStates = powermgmt_getADCStates();
    
    while (1) {
        uart_writeChar('\n');
        uart_writeString_P("#####################################################################\n");
        uart_writeString_P("#########            RP6 Robot Base Selftest                #########\n");
        uart_writeString_P("#####################################################################\n");
        uart_writeString_P("#####       Main Menu         #########      Advanced Menu      #####\n");
        uart_writeString_P("#                                 #                                 #\n");
        uart_writeString_P("# 0 - Run ALL Selftests (0-8)     # s - Move at speed Test          #\n");
        uart_writeString_P("# 1 - PowerOn Test                # d - Move distance Test          #\n");
        uart_writeString_P("# 2 - LED Test                    # c - Encoder Duty-Cycle Test     #\n");
        uart_writeString_P("# 3 - Voltage Sensor Test         #                                 #\n");
        uart_writeString_P("# 4 - Bumper Test                 #                                 #\n");
        uart_writeString_P("# 5 - Light Sensor Test           #                                 #\n");
        uart_writeString_P("# 6 - ACS (and RC5 receive) Test  #                                 #\n");
        uart_writeString_P("# 7 - IRCOMM/RC5 Test             # System voltage is:              #\n");
        uart_writeString_P("# 8 - Motors and Encoders Test    #      ");
        printUBat(ADCStates->adcBat);
        uart_writeString_P("                     #\n");
        uart_writeString_P("#                                 #                                 #\n");
        uart_writeString_P("#####################################################################\n");
        uart_writeString_P("# Please enter your choice (1-8, s, d, c)!                          #\n");
        uart_writeString_P("#####################################################################\n");
        
        enterString();
		
		test = receiveBuffer[0] - 48;
		
		if(receiveBuffer[0] == 's')
		{
			speed_control();
		}
		else if(receiveBuffer[0] == 'd')
		{
			testMoveDistance();
		}
		else if(receiveBuffer[0] == 'c')
		{
			testEncoderDutyCycle();
		}
		else if(test > 8)
		{
			uart_writeString_P("You need to enter a single number from 0 to 8, s, d or c!");
			continue;
		}
		else
		{
			switch(test)
			{
				case 0:
					testPowerOn();
					testLEDs();
					testVoltageSensor(ADCStates);
					testBumpers();
					testLightSensors(ADCStates);
					testACS();
					testRC5();
					testMotorsAndEncoders();
					break;
				case 1: testPowerOn();						break;
				case 2: testLEDs();							break;
				case 3: testVoltageSensor(ADCStates);		break;
				case 4: testBumpers();						break;
				case 5: testLightSensors(ADCStates);		break;
				case 6: testACS();							break;
				case 7: testRC5();							break;
				case 8: testMotorsAndEncoders();			break;
			}
		}
	}
    return 0;
}
