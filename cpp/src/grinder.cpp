/*
 * grinder.cpp
 *
 * Created: 24.08.2015 18:52:19
 *  Author: KOSHELEV
 */ 
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "Gpio.h"
#include "Timer0.h"
#include "seg_led.h"
#include "intrpt.h"

Timer0 timer(Timer0::div1024);
seg_led led ;
Gpio B (Gpio::B);
Gpio C (Gpio::C);
Gpio D (Gpio::D);
intrpt in1 (intrpt::INTRPT1, intrpt::RiseEdge);
intrpt in0 (intrpt::INTRPT0, intrpt::RiseEdge);
float k = 6.5;
float num = k;

enum input_port {enc = 0 , button = 1 , butt_enc=3 , Relay = 5};
struct flags
{
	unsigned button :1;
	unsigned enc    :1;
	unsigned led    :1;
}flag;


	
ISR (TIMER0_OVF_vect)
{
	static int i ;
	led.Show_digit(num);
	
	if (flag.button)
	{
		D.setPin(Relay);
		if (i>33)
		{
			num-=0.1;
			i=0;
		}
		else
		{
			++i;
		}
	}
	else
	{
		
		num = k;
		
	}
	if (num<=0)
	{
		flag.button = 0;
		num=k;
		D.clearPin(Relay);
	}
}


ISR (INT0_vect)
{
	flag.button = 1;
}

ISR (INT1_vect)
{

	if (!(PIND&(1 << enc)))
	{
		k +=0.1;
	} 
	else
	{
		k -=0.1;
	}
}




int main()
{
	timer.Set_Tcnt(254);
	timer.interpt(Timer0::Enable);
	D.setDirPin(Relay);
	B.setValPort(0xFF);
	timer.Start();
	
	while(1)
	{
			if (PIND&(1 << button))	
			{
				if (flag.led)
				{
					timer.Start();
					flag.led = 0;
					_delay_ms(1000);
					
				} 
				else
				{
					timer.Stop();
					PORTC &= ~0x0F;
					flag.led = 1;
					_delay_ms(1000);
					
				}
				
				
			}
		
		//B.setValPort(0xFF);
		//_delay_ms(500);
		//B.setValPort(0x00);
		//_delay_ms(500);
		//TODO:: Please write your application code
	}
}