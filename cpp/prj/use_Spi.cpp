/*
 * use_Spi.cpp
 *
 * Created: 17.06.2015 16:08:27
 *  Author: User
 */ 
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "Spi.h"


int main()
{
	Spi spi (Spi::div64);
	
	
	while(1)
	{
		spi.transfer_byte(0xF0);
		_delay_ms(1000);
		spi.transfer_byte(0x0F);
		_delay_ms(1000);

	}
}