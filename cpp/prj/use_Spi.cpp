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
		spi.CS_CLEAR();
		spi.transfer(0xF0);
		spi.CS_SET();
		_delay_ms(200);
		spi.CS_CLEAR();
		spi.transfer(0x0F);
		spi.CS_SET();
		_delay_ms(200);
	}
}