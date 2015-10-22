/*
 * use_ssd1289.cpp
 *
 * Created: 18.06.2015 21:20:38
 *  Author: KOSHELEV
 */ 
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "ssd1289.h"

int main()
{
	ssd1289 lcd;
	while(1)
	{
		
	lcd.fill_screen(GREEN);	
	_delay_ms(500);
	lcd.fill_screen(BLACK);
	_delay_ms(500);	
	lcd.fill_screen(BLUE);
	_delay_ms(500);
	lcd.fill_screen(RED);
	_delay_ms(500);	
	lcd.fill_screen(CYAN);
	_delay_ms(500);
	lcd.fill_screen(MAGENTA);
	_delay_ms(500);
	lcd.fill_screen(YELLOW);
	_delay_ms(500);
	lcd.fill_screen(WHITE);
	_delay_ms(500);	
	}
}