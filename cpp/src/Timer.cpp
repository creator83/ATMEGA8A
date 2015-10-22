/* 
* Timer.cpp
*
* Created: 02.02.2015 11:36:24
* Author: User
*/


#include "Timer.h"

unsigned char Timer::TCCR [3] = {0x53 , 0x4E , 0x45};
unsigned char Timer::TCNT [2] = {0x52 , 0x4D};



Timer::Timer(num_timer n , prsk p , timer_mode mode)
{
	t=n;
	div=p;	
	m = mode;		
}

void Timer::Start ()
{
	*(reg)(TCCR [t]) &= ~(0x07);
	*(reg)(TCCR [t]) |= div;	
}

void Timer::Stop ()
{
	*(reg)(TCCR [t]) &= ~(0x07);
}

void Timer::Set_Ocr (compare n_cmpr , unsigned int ocr)
{
		 cmpr ocr0;
		 ocr0.ocr16 = ocr;
		 if (n_cmpr)
		 {
			*(reg)(OCR0B) = ocr0.ocr8[1];
			*(reg)(OCR0B-1) = ocr0.ocr8[0];			 
		 } 
		 else
		 {
			*(reg)(OCR0A) = ocr0.ocr8[1];
			*(reg)(OCR0A-1) = ocr0.ocr8[0]; 
		 }
		
}	

void Timer::Set_Tcnt (unsigned int val)
{
	counter cntr;
	cntr.cnt16 = val;
	if (t)
	{
		*(reg)(TCNT [t]) = cntr.cnt8[1];
		*(reg)(TCNT [t]-1) = cntr.cnt8[0];
	}
	else
	{
		*(reg)(TCNT [t]) = cntr.cnt8[0];
	}
	
}

void Timer::interpt (interrupt i)
{
	TIMSK |= 1 << i;
	sei();
}

