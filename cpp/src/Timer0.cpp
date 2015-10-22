/* 
* Timer0.cpp
*
* Created: 26.06.2015 10:03:45
* Author: User
*/


#include "Timer0.h"

// default constructor
Timer0::Timer0(prsk p)
{
	div=p;
} //Timer0

void Timer0::Start ()
{
	TCCR0 &= ~(0x07);
	TCCR0 |= div;
}

void Timer0::Stop ()
{
	TCCR0 &= ~(0x07);
}

void Timer0::Set_Tcnt (unsigned char val)
{
	TCNT0 = val;
}

void Timer0::interpt (intr i)
{
	TIMSK &= ~ (1 << TOIE0);
	TIMSK |= i << TOIE0;
	sei();
}
