/*
 * use_gpio.cpp
 *
 * Created: 17.06.2015 9:51:29
 *  Author: User
 */ 
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "Gpio.h"

int main()
{
	
	Gpio B (Gpio::B);
	Gpio C (Gpio::C);
	//Gpio C (C);
	//B.setDirPin(7);
	//B.setPin(7);
	B.setDirPort(0xFF);
	C.setDirPort(0x0F);
	//C.setDirPort(0x0F);
	B.setValPort(0x7D);
	C.setValPort (0x01);

	while(1)
	{

		//TODO:: Please write your application code
	}
}