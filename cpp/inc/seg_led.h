/* 
* seg_led.h
*
* Created: 02.02.2015 11:33:53
* Author: User
*/
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Gpio.h"

#ifndef __SEG_LED_H__
#define __SEG_LED_H__
//#define Shift


class seg_led
{
//variables
public:
	static unsigned char time;
	static char digit [11];
	static char digitDp [11];
	unsigned char hun , dec, ones, decimal;
protected:
	Gpio seg;
	Gpio dig;
private:

//functions
public:
	seg_led();
	void Show_digit (float num);
	void Show_digit1 (float num);
	//void Calc_digit (unsigned int n);
	void Calc_digit (float n);
	unsigned int div10 (unsigned int);

}; //seg_led

ISR (TIMER0_OVF_vect);

#endif //__SEG_LED_H__
