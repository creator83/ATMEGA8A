#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "spi.h"


//Soft Spi
#define SOFTSPI

#define PinDDR  DDRB
#define PinPORT PORTB

#define CS_set PinPORT |= 1 << cs
#define CS_clear PinPORT &= ~(1 << cs)

//Pins for Soft Spi
#define sclk 5
#define miso 4
#define cs   2

#define TC   2



#ifndef MAX6675_H
#define MAX6675_H


void max6675_init (void);

double readCelsius(void);

uint8_t spiread(void);

void buffer (double val);



#endif
