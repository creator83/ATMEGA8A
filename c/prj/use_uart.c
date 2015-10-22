/*
 * use_uart.c
 *
 * Created: 22.10.2015 19:59:21
 *  Author: KOSHELEV
 */ 
#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"




int main(void)
{
	
	usart_init (BRR_VAL);
	
	while(1)
	{
		transmit ("Hello Atmega8a===");
		_delay_ms(1000);
	}
}
