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



//  ��������� ������ ��� �������� ������ ��������
#define Start 1
#define Stop 0

extern unsigned int N_takt; //���������� ���������� �������� ������

//������� ���������� ��������
#define BAUD 9600
#define UBRR_VAL F_CPU/16/BAUD-1


ISR (INT0_vect)  //������� �� ��������� ����� ��� ������ ������
{
	if(Echo_PIN & (1<<Echo_N)) //���� �������� �����
	timer_Start_Stop (Start);  //��������� ������
	else //���� ������ �����
	N_takt = timer_Start_Stop (Stop);	//������������� ������
}



int main (void)
{
	HC_SRC4_Init();
	usart_init (UBRR_VAL);//������������� ������
	init_interp(); //������������� ������� ����������
	sei();
	//char i=0;//���������� �� ��������
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

