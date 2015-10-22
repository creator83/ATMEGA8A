/* 
* Gpio.h
*
* Created: 17.06.2015 9:47:58
* Author: User
*/
#include <avr/io.h>

#ifndef __GPIO_H__
#define __GPIO_H__


typedef unsigned char* reg;

//порты
/*
const char B = 0;
const char C = 1;
const char D = 2;
*/

class Gpio
{
//variables
public:
	enum DIR {IN , OUT};
	enum port {B , C , D};
protected:
private:
	static unsigned char portAdr [3];
	static unsigned char pAdr [3];	
	unsigned char prt;
	//functions
public:
	Gpio(port p);
	void setDirPin (unsigned char pin , DIR d = OUT);	
	void setPin (unsigned char pin );
	void clearPin (unsigned char pin);	
	void setValPort (unsigned char value);	
	void setDirPort (unsigned char value);		
	void ChangePinState (unsigned char pin);
	void SetPinState (unsigned char pin , unsigned char state);


}; //Gpio

#endif //__GPIO_H__
