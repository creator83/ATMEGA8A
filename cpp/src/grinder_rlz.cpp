/*
 * Use_seg_led.cpp
 *
 * Created: 21.06.2015 18:43:50
 *  Author: KOSHELEV
 */ 
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "Timer1.h"
#include "Timer0.h"
#include "Gpio.h"
#include "seg_led.h"
#include "intrpt.h"


Timer0 t0 (Timer0::div64);
Timer1 t1 (Timer1::div1024, Timer1::CTC);
seg_led led;
Gpio D (Gpio::D);
intrpt in1 (intrpt::INTRPT1, intrpt::RiseEdge);
intrpt in0 (intrpt::INTRPT0, intrpt::RiseEdge);

uint8_t time = 52;
uint8_t VarTime = time;

enum input_port {enc = 0 , button = 1 , butt_enc=3 , Relay = 5};
struct flags
{
	unsigned button :1;
	unsigned enc    :1;
	unsigned led    :1;
}flag;

ISR (TIMER0_OVF_vect)
{
	static uint8_t i=2;
	//static uint16_t t=0;
	if (i)
	{
		led.Show_digit(VarTime , i);
		--i;
	}
	else
	{
		led.Show_digit(VarTime , i);
		i=2;
	}
	/*	
	if (flag.button)
	{
		D.setPin(Relay);
		if (t>1999)
		{
			--VarTime;
		}
		else
		{
			++t;
		}
	}
	else
	{
		
		VarTime = time;
		
	}
	*/
	if (flag.button)
	{
		D.setPin(Relay);
		t1.Start();
	}
	else
	{
		VarTime = time;
	}
	if (VarTime<=0)
	{
		t1.Stop();
		flag.button = 0;
		VarTime=time;
		D.clearPin(Relay);
	}
	
}

ISR (TIMER1_COMPA_vect)
{
	--VarTime;
}

ISR (INT1_vect)
{

	if (!(PIND&(1 << enc)))
	{
		++time;
	}
	else
	{
		--time;
	}
}

ISR (INT0_vect)
{
	flag.led ^=1;
	if (flag.led)
	{
		t0.Stop();
		PORTC &= ~0x0F;
	} 
	else
	{
		t0.Start();
	}
	
	
}

int main()
{
	D.setDirPin(Relay);
	t0.Set_Tcnt(130);
	t0.interpt(Timer0::Enable);
	t1.Set_OCR(781, Timer1::A);
	t1.interpt(Timer1::OCIEA);
	t0.Start();
	while(1)
	{
		if (PIND&(1 << button))flag.button = 1;
		
		//TODO:: Please write your application code
	}
}