/*
 * Bluetooth_app.c
 *
 * Created: 09/06/2020 9:30:47 PM
 *  Author: M
 */ 


#include "UART.h"
int main(void)
{
	uint8_t received;
	SETBIT(DDRC,0);
	Uart_init();
    while(1)
    {

		received=Uart_Read();
		if (received=='1')
		{
			SETBIT(PORTC,0);
			Uart_Write_string("LED ON");
		}
		else if (received=='2')
		{
			CLRBIT(PORTC,0);
			Uart_Write_string("LED OFF");
		}
		else { 
			Uart_Write_string("Select proper option");
		}		
    }
}
