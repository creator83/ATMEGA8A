/*
 * uart.h
 *
 * Created: 29.09.2015 19:45:31
 *  Author: KOSHELEV
 */ 
//#define F_CPU 1000000
#include <avr/io.h>
#define BAUD 9600
#define BRR_VAL F_CPU/16/BAUD-1

#ifndef UART_H_
#define UART_H_


void usart_init (unsigned int speed);
void transmit (char * str);
void transmit_byte (uint8_t n);


#endif /* UART_H_ */