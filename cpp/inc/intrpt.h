/* 
* intrpt.h
*
* Created: 26.06.2015 11:16:07
* Author: User
*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Gpio.h"

#ifndef __INTRPT_H__
#define __INTRPT_H__


class intrpt
{
//variables
public:
	enum INT {INTRPT0 , INTRPT1};
	enum SCtrl {LowLev , AnyChange , FallEdge , RiseEdge};
protected:
private:
	Gpio pin;
	static unsigned char Regstr [2][3];

//functions
public:
	intrpt(INT i , SCtrl e);
	

protected:
private:


}; //intrpt

#endif //__INTRPT_H__
