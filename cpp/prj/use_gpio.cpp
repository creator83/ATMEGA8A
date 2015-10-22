/*
 * use_gpio.cpp
 *
 * Created: 17.06.2015 9:51:29
 *  Author: User
 */ 
#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include "Gpio.h"

int main()
{
	
	Gpio B (Gpio::B);
	B.setDirPin(7);
	
	while(1)
	{
		B.ChangePinState(7);
		_delay_ms(500);

		//TODO:: Please write your application code
	}
}