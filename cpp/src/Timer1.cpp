/* 
* Timer1.cpp
*
* Created: 05.09.2015 21:18:38
* Author: KOSHELEV
*/


#include "Timer1.h"

// default constructor
Timer1::Timer1(prsk p, mode m)
{
	div=p;
	TCCR1B |= m << WGM12;
} //Timer1

void Timer1::Start ()
{
	TCCR1B &= ~(0x07);
	TCCR1B |= div;
}

void Timer1::Stop ()
{
	TCCR1B &= ~(0x07);
}

void Timer1::Set_Tcnt (uint16_t val)
{
	TCNT1 = val;
}

void Timer1::Set_OCR (uint16_t val , OCR i)
{

	if (i)
	{
		OCR1B = val;
	} 
	else
	{
		OCR1A = val;
	}
	
}

void Timer1::interpt (intr i)
{
	TIMSK |= 0x04 << i;
	sei();
}