/* 
* Spi.cpp
*
* Created: 17.06.2015 16:09:03
* Author: User
*/


#include "Spi.h"

//unsigned char Spi::SPCR_reg = 0x2D;

// default constructor
Spi::Spi(div d , role r)
:pin (Gpio::B)
{
	pin.setDirPin(CS);
	pin.setDirPin(SCK);
	pin.setDirPin(MOSI);
	pin.setPin(CS);
	
	SPCR |= d;
	SPCR |= (1 << SPE)|(r << MSTR);

} //Spi

unsigned char Spi::transfer (unsigned char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}
/*
unsigned char Spi::transfer_byte (unsigned char data)
{
	pin.clearPin (CS);
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	pin.setPin(CS);
	return SPDR;
}
*/
void Spi::CS_SET ()
{
	pin.setPin(CS);
}

void Spi::CS_CLEAR ()
{
	pin.clearPin(CS);
}
