/*
 * use_timer.cpp
 *
 * Created: 21.06.2015 19:03:42
 *  Author: KOSHELEV
 */ 
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "Timer.h"
#include "Timer0.h"
#include "Gpio.h"
#include "seg_led.h"
#include "intrpt.h"
#include "mcp3551.h"


	Gpio D (Gpio::D);
	seg_led led;
	Timer0 t0 (Timer0::div64);
	float time = 5.9;
	unsigned char flag;
	unsigned char off;
	

ISR (INT1_vect)
{
	if (!(PIND&1<<1))
	{
		time+=0.1;
	}
	else
	{
		time-=0.1;
	}
}

ISR (INT0_vect)
{
	if (off)
	{
		t0.interpt(Timer0::Disable);
		PORTC &= ~ 0x0F;
		off = 0;
	} 
	else
	{
		t0.interpt(Timer0::Enable);
		off = 1;
	}
}
	
ISR (TIMER0_OVF_vect)
{
	led.Show_digit(time);
	if (!(PIND&1<<4))
	{
		for (float i = time;i>0;i-=0.1)
		{
			led.Show_digit(time);
			_delay_ms(100);
		}		
	}
}


int main()
{
	mcp3551 t_sensor;
	intrpt encButt (intrpt::INTRPT1 , intrpt::FallEdge);
	intrpt enc (intrpt::INTRPT0 , intrpt::FallEdge);
	D.setDirPin(4);
	D.setPin(4);
	t0.Set_Tcnt(130);
	t0.Start();
	t0.interpt(Timer0::Enable);
	
	while(1)
	{

		//TODO:: Please write your application code
	}
}