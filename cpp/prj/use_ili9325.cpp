/*
 * atmega8a.cpp
 *
 * Created: 17.06.2015 9:19:31
 *  Author: User
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include "ili9325.h"
#include "Gpio.h"

int main()
{
	
	/*ili9325 lcd;
	unsigned int col[3] = { WHITE , BLUE ,RED};
	for (unsigned int j=0;j<320;++j)
	{
		lcd.set_cursor(0,j);
		for (unsigned char i=0;i<3;++i)
		{
			for (char z=0;z<80;++z)
			{
			lcd.data(col[i]);
			}
		}
	}*/
	
    while(1)
    {
	/*
		_delay_ms(500);
		lcd.fill_screen(SKY);
		_delay_ms(500);
		lcd.fill_screen(ORANGE);
		_delay_ms(500);
		lcd.fill_screen(PINK);
		_delay_ms(500);	
		lcd.fill_screen(BROWN);
		_delay_ms(500);
		lcd.fill_screen(VIOLET);
		_delay_ms(500);
		lcd.fill_screen(SILVER);
		_delay_ms(500);
		lcd.fill_screen(GOLD);
		_delay_ms(500);	
		lcd.fill_screen(BEGH);
		_delay_ms(500);
		lcd.fill_screen(NAVY);
		_delay_ms(500);
		lcd.fill_screen(DARK_GREEN);
		_delay_ms(500);
		lcd.fill_screen(DARK_CYAN);
		_delay_ms(500);	
		lcd.fill_screen(MAROON);
		_delay_ms(500);
		lcd.fill_screen(PURPLE);
		_delay_ms(500);
		lcd.fill_screen(LIGHT_GREY);
		_delay_ms(500);
		lcd.fill_screen(DARK_GREY);
		_delay_ms(500);			*/	
    }
}