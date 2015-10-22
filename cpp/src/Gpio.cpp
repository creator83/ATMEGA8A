/* 
* Gpio.cpp
*
* Created: 17.06.2015 9:47:58
* Author: User
*/


#include "Gpio.h"

unsigned char Gpio::portAdr [3] = {0x37 , 0x34 , 0x31};
unsigned char Gpio::pAdr [3] = {0x38 , 0x35 , 0x32};	
	

// default constructor
Gpio::Gpio(port p)
{
	prt = p;
} //Gpio

void Gpio::setPin (unsigned char pin )
{

	*(reg)(pAdr [prt]) |= 1 << pin;
}

void Gpio::setDirPin (unsigned char pin , DIR d)
{
	*(reg)(portAdr [prt]) &= ~(d << pin);
	*(reg)(portAdr [prt]) |= d << pin;	
}

void Gpio::clearPin (unsigned char pin)
{
	*(reg)(pAdr [prt]) &= ~(1 << pin);
}

void Gpio::ChangePinState (unsigned char pin)
{
	*(reg)(pAdr [prt]) ^= 1 << pin;
}

void Gpio::SetPinState (unsigned char pin , unsigned char state)
{
	if (state) setPin(pin);
	else clearPin(pin);
}
	
void Gpio::setValPort (unsigned char value)
{
	*(reg)(pAdr [prt]) = value;
}

void Gpio::setDirPort (unsigned char value)
{
	*(reg)(portAdr [prt]) = value;
}


