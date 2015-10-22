/*
 * use_Timer1.cpp
 *
 * Created: 05.09.2015 21:29:22
 *  Author: KOSHELEV
 */ 
//#define F_CPU 8000000
#include <avr/io.h>
#include "Timer1.h"
#include "Gpio.h"
#include "seg_led.h"
#include "intrpt.h"

Gpio C (Gpio::C);
Gpio B (Gpio::B);

ISR (TIMER1_COMPA_vect)
{
	PORTC ^= 0x0F;
}

int main()
{
	Timer1 t1 (Timer1::div1024);
	TCCR1B |= 1 << WGM12;
	t1.Set_OCR(7812,Timer1::A);
	B.setDirPort(0xFF);
	C.setDirPort(0x0F);
	//C.setValPort(0x0F);
	B.setValPort(0xFF);
	t1.interpt(Timer1::OCIEA);
	t1.Start();
	
	while(1)
	{

		
		//TODO:: Please write your application code
	}
}