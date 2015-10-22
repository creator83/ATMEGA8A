/* 
* Timer1.cpp
*
* Created: 03.09.2015 14:53:52
* Author: User
*/


#include "Timer1.h"

// default constructor
Timer1::Timer1(prsk p, mode m)
{
	div=p;
	TCCR1B &= ~(1 << WGM12);
	TCCR1B |= (m << WGM12);
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
	TCNT1L = val;
	TCNT1H = val >> 8;
}

void Timer1::Set_OcrA (uint16_t val)
{
	OCR1AL = val;
	OCR1AH = val >> 8;
}
	
void Timer1::Set_OcrB (uint16_t val)
{
	OCR1BL = val;
	OCR1BH = val >> 8;	
}

void Timer1::interpt (intr i)
{
	TIMSK |= 0x04 << i;
}

