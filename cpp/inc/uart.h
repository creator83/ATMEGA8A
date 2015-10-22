/* 
* uart.h
*
* Created: 26.06.2015 15:36:52
* Author: User
*/
#define F_CPU 8000000
#include <avr/io.h>

#define BAUD 9600
#define UBRR_VAL F_CPU/16/BAUD-1

#ifndef __UART_H__
#define __UART_H__



class uart
{
//variables
public:
	enum speed {baud9600 , baud38400 , baud57600 , baud115200};
	enum role {Transmitter , Receiver};
protected:
private:
	static long int sp[4];

//functions
public:
	uart(speed s, role = Transmitter);
protected:
private:


}; //uart

#endif //__UART_H__
