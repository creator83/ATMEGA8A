/* 
* mcp3551.h
*
* Created: 29.06.2015 9:26:46
* Author: User
*/
#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include "Gpio.h"
#include "Spi.h"

#ifndef __MCP3551_H__
#define __MCP3551_H__

	const uint8_t pt = 100;
	const uint16_t r_val = 13407;
	
	const int8_t CS = 2;// pin CS


class mcp3551
{
//variables
public:
	int32_t byteCode;

protected:
private:
	Gpio pin;
	bool OVH, OVL;
	Spi spi;
	union {
	int32_t ByteCode;
	uint8_t Byte[4];
	}spi_code ;

	

//functions
public:
	mcp3551();
	float getTemp (int32_t code);
	bool getCode();
	
	
protected:
private:

	bool getOVH();
	bool getOVL();
	bool isReady();

}; //mcp3551

#endif //__MCP3551_H__
