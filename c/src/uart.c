/*
 * uart.c
 *
 * Created: 29.09.2015 19:45:45
 *  Author: KOSHELEV
 */ 

#include "uart.h"

void usart_init (unsigned int speed)
{
	// ������������� �������� Baud Rate: 9600
	UBRRH=(unsigned char)(speed>>8);
	UBRRL=(unsigned char) speed;
	UCSRA=0x00;
	// ���������� ������ �����������
	UCSRB=(1<<TXEN);
	//��������� ������� �������: 8 ��� ������, 1 ����-���
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}

void transmit (char * str)
{
	while (*str)
	{
		while (!(UCSRA&(1 << UDRE)));
		UDR = *str;
		str++;
	}
}

void transmit_byte (uint8_t n)
{
	while (!(UCSRA&(1 << UDRE)));
	UDR = n;
}
