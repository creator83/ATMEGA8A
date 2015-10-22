/*
 * use_interrupt.cpp
 *
 * Created: 27.06.2015 9:24:01
 *  Author: KOSHELEV
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include "Gpio.h"
#include "intrpt.h"

const unsigned char button = 4;
const unsigned char led = 3;
Gpio C (Gpio::C);

ISR (INT0_vect)
{
	C.ChangePinState(led);
}

int main ()
{
	
	C.setDirPin(led);
	intrpt i0 (intrpt::INTRPT0 , intrpt::RiseEdge);
	
	
	while (1)
	{
		
	}
}