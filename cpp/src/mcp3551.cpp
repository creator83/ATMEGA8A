/* 
* mcp3551.cpp
*
* Created: 29.06.2015 9:26:42
* Author: User
*/


#include "mcp3551.h"

// default constructor
mcp3551::mcp3551()
:pin (Gpio::C)
{
	_delay_ms(1);	
	pin.setDirPin(CS);
	pin.setPin(CS);
} //mcp3551

bool mcp3551::isReady()
{
	pin.clearPin(CS);
	_delay_ms(80);
	if (!(PINB & (1 << Spi::MISO)))
	{
		return true;
	}
	else
	{
		pin.setPin(CS);
		return false;
	}
}

bool mcp3551::getCode()
{
	if (isReady())
	{
		spi_code.Byte[3] = 0x00;
		spi_code.Byte[2] = spi.transfer(0);
		spi_code.Byte[1] = spi.transfer(0);
		spi_code.Byte[0] = spi.transfer(0);
		
		OVH = spi_code.Byte[5] & (1 << 7);
		OVL = spi_code.Byte[5] & (1 << 8);
		if (OVH && OVL) return false;
		if (OVH && !OVL) spi_code.Byte [2] &= ~(1<<6|1<<7);
		pin.clearPin(CS);
		if ((!OVH && (spi_code.Byte[2] & (1 << 5))) || OVL )
		{
			spi_code.Byte [2] |= (1 << 7|1 << 8);
			spi_code.Byte [3] = 0xFF;
		}
		pin.setPin(CS);
		byteCode = spi_code.ByteCode;
		return true;		
	}
	else return false;
}

bool mcp3551::getOVH()
{
	return OVH;
}

bool mcp3551::getOVL()
{
	return OVL;
}