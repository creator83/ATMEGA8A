/*
 * use_spi.c
 *
 * Created: 22.10.2015 9:50:45
 *  Author: User
 */ 
#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include "spi.h"


int main(void)
{
	spi_init ();
	
	while(1)
	{
		CS_CLEAR;
		transfer (0x0F);
		CS_SET;
		_delay_ms(500);
		CS_CLEAR;
		transfer (0xF0);
		CS_SET;
		_delay_ms(500);		
	}
}