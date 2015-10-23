#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "max6675.h"
#include "uart.h"

extern char buff[4];


int main ()
{
	uint8_t i;
	usart_init (BRR_VAL);
	max6675_init ();
	
	while (1)
	{
		buffer (readCelsius());
		for (i=0;i<4;++i)
		{
			transmit_byte (buff[i]);
		}
		
		_delay_ms (500);
	}
	
}

