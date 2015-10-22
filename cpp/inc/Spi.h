/* 
* Spi.h
*
* Created: 17.06.2015 16:09:04
* Author: User
*/

#include <avr/io.h>
#include "Gpio.h"


#ifndef __SPI_H__
#define __SPI_H__


class Spi
{
//variables
public:
	enum div {div4 , div16 , div64 , div128};
	enum role {Slave , Master};
	enum SpiPin {CS = 2 , MOSI,MISO,SCK};		
protected:

private:

	Gpio pin;
//	static unsigned char SPCR_reg;

//functions
public:
	Spi(div d=div4 , role r=Master);
	unsigned char transfer (unsigned char data);
	unsigned char transfer_byte (unsigned char data);
	void CS_SET ();
	void CS_CLEAR ();

protected:
private:


}; //Spi

#endif //__SPI_H__
