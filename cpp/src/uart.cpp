/* 
* uart.cpp
*
* Created: 26.06.2015 15:36:51
* Author: User
*/


#include "uart.h"

long int uart::sp[4] = {9600 , 38400 , 57600 , 115200};

// default constructor
uart::uart(speed s )
{
	unsigned int spd = (F_CPU/(16*sp [s])) - 1;
	UBRRH=static_cast<unsigned char>(spd>>8);
	UBRRL=static_cast<unsigned char> (spd);
	//UBRRH = 0;
	//UBRRL = 51;
	UCSRA=0x00;
	UCSRB|=(1<<TXEN)|(1<<RXEN)|(1<<RXCIE);
	/*if (!r)
	{
		UCSRB|=(1<<TXEN);// ���������� ������ �����������
	} 
	else
	{
		UCSRB|=(1<<RXEN);// ���������� ������ ���������
		UCSRB|=(1<<RXCIE);// ���������� ���������� �� ������
	}
		*/
	
	
	// ��������� ������� �������: 8 ��� ������, 1 ����-���
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
} //uart


void uart::transmit (uint8_t data)
{
	while (!(UCSRA&(1 << UDRE)));
	UDR = data;
}

void uart::transmit (char * str)
{
	while (*str)
	{
		while (!(UCSRA&(1 << UDRE)));
		UDR = *str;
		str++;
	}
}