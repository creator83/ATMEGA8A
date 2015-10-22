/* 
* uart.cpp
*
* Created: 26.06.2015 15:36:51
* Author: User
*/


#include "uart.h"

long int uart::sp[4] = {9600 , 38400 , 57600 , 115200};

// default constructor
uart::uart(speed s , role r)
{
	unsigned int spd = F_CPU/16/sp [s] - 1;
	UBRRH=static_cast<unsigned char>(spd>>8);
	UBRRL=static_cast<unsigned char> (spd);
	UCSRA=0x00;

	if (!r)
	{
		UCSRB|=(1<<TXEN);// ���������� ������ �����������
	} 
	else
	{
		UCSRB|=(1<<RXEN);// ���������� ������ ���������
		UCSRB|=(1<<RXCIE);// ���������� ���������� �� ������
	}
		
	
	
	// ��������� ������� �������: 8 ��� ������, 1 ����-���
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
} //uart


