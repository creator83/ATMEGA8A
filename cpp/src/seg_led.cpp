/* 
* seg_led.cpp
*
* Created: 02.02.2015 11:33:52
* Author: User
*/


#include "seg_led.h"

char seg_led::digit [11] = {0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D , 0x7D , 0x07 , 0x7F , 0x6F , 0x00};
char seg_led::digitDp [11] = {0xBF , 0x86 , 0xDB , 0xCF , 0xE6 , 0xED , 0xFD , 0x87 , 0xFF , 0xEF , 0x00};
unsigned char seg_led::time = 3;

unsigned int seg_led::div10 (unsigned int number)
{
	unsigned int n;
	
	// умножение на 0,8
	n = number >> 1;
	n += n >> 1 ;
	n += n >> 4 ;
	n += n >> 8 ;
//	n += n >> 16 ;
	
	//деление на 8
	n >>= n;
	return n;
	
}

#ifdef Shift
void seg_led::Calc_digit (float n)
{
	unsigned char res;
	dec = div10(n);
	res = static_cast<unsigned char>(n);
	ones = res%10;
	res =(unsigned char) n*10;
	decimal = res%10;
}

#else
void seg_led::Calc_digit (float n)
{
	unsigned int res;
	hun = n/100;
	res = n - hun*100;
	dec = (n-hun*100)/10;
	ones = res%10;
	res = n*10;
	decimal = res%10;

}

#endif



//void seg_led::Calc_digit (unsigned int numb)
//{
	//unsigned int res;
	//if (numb>99)
	//{
		//res = div10(numb);
		//hun = div10(res);
		//res = numb - hun*100;
		//dec = div10(res);
		//ones = numb%10;
		//
	//}
	////hun = numb/100;
	////dec = (numb + hun*100)/10;
	////ones = numb%10;
//}
/*
void seg_led::Show_digit (float n)
{

		char time1=1;
		PORTC = 0;
		PORTC = 1<<0;
		PORTB = digit [hun];
		_delay_ms(time1);

		PORTC = 0;
		PORTC = 1<<1;
		PORTB = digit [dec];
		_delay_ms(time1);


	PORTC = 0;
	PORTC = 1<<2;
	PORTB = digitDp [ones];
	_delay_ms(time1);
	PORTC = 0;
	PORTC = 1<<3;
	PORTB = digit [decimal];
	_delay_ms(time1);
}
*/
void seg_led::Show_digit (float n)
{

	char time1=1;
	Calc_digit (n);
	if (!hun) PORTC = 0;
	else
	{
		PORTC = 0;
		PORTC = 1<<3;
		PORTB = digit [hun];
		_delay_ms(time1);
	}
	if (hun==0 && dec ==0)PORTC = 0;
	else
	{
		PORTC = 0;
		PORTC = 1<<2;
		PORTB = digit [dec];
		_delay_ms(time1);
	}

	PORTC = 0;
	PORTC = 1<<1;	
	PORTB = digitDp [ones];
	_delay_ms(time1);
	PORTC = 0;
	PORTC = 1<<0;
	PORTB = digit [decimal];
	_delay_ms(time1);	
}

void seg_led::Show_digit1 (float num)
{
	
}


seg_led::seg_led()
:seg (Gpio::B) , dig (Gpio::C)
{
	seg.setDirPort(0xFF);
	dig.setDirPort(0x0F);	
} 

