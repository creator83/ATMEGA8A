#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "max6675.h"




int main ()
{
	max6675_init ();
	
	
	while (1)
	{
		_delay_ms (500);
	}
	
}

