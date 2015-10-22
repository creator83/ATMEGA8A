#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "max6675.h"
#include "uart.h"




int main ()
{
	usart_init (BRR_VAL);
	max6675_init ();
	
	
	while (1)
	{
		transmit_byte (readCelsius());
		_delay_ms (500);
	}
	
}

