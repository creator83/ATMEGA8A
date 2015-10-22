/*
 * use_uart.cpp
 *
 * Created: 25.07.2015 11:45:11
 *  Author: KOSHELEV
 */ 
#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "max6675.h"



int main ()
{
	uart uart1 (uart::baud9600);
	max6675 sensor;

	while (1)
	{
		
		uart1.transmit (static_cast<uint8_t>(sensor.get_temp()));
		_delay_ms(1000);
	
		//for (uint8_t i=0;i<20;++i)
		//{
			//uart1.transmit(i);
			//_delay_ms(500);
		//}
	}
}
