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
		UCSRB|=(1<<TXEN);// Разрешение работы передатчика
	} 
	else
	{
		UCSRB|=(1<<RXEN);// Разрешение работы приемника
		UCSRB|=(1<<RXCIE);// Разрешение прерываний по приему
	}
		
	
	
	// Установка формата посылки: 8 бит данных, 1 стоп-бит
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
} //uart


