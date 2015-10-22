/*
 * atmega8_uart.c
 *
 * Created: 11.09.2015 23:03:22
 *  Author: KOSHELEV
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "hcsr4.h"
#include "uart.h"



//  текстовые замены дл€ удобства управл таймером
#define Start 1
#define Stop 0

extern unsigned int N_takt; //глобальна€ переменна€ хранени€ тактов

//макросы вычислени€ скорости
#define BAUD 9600
#define UBRR_VAL F_CPU/16/BAUD-1


ISR (INT0_vect)  //переход на следующий режим при ажатии кнопки
{
	if(Echo_PIN & (1<<Echo_N)) //если передний фронт
	timer_Start_Stop (Start);  //«апускаем таймер
	else //если задний фронт
	N_takt = timer_Start_Stop (Stop);	//останавливаем таймер
}



int main (void)
{
	HC_SRC4_Init();
	usart_init (UBRR_VAL);//инициализаци€ модул€
	init_interp(); //инициализаци€ внешних прерываний
	sei();
	//char i=0;//переменна€ на отправку
	while(1)
	{
		transmit_byte (HC_SRC4_Get_CM ());
		
		_delay_ms(400);
		/*
		UDR=i;
		_delay_ms(1000);
		i+=1;*/
	}
}

