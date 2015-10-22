/*
 * spi.c
 *
 * Created: 22.10.2015 9:51:36
 *  Author: User
 */ 
#include "spi.h"

void spi_init (void)
{
	SPIDDR |= (1 << SCK)| (1 << MOSI)|(1 << CS);
	SPIPORT |= 1 << CS;
	SPCR = (1 << SPE)|(1 << MSTR)|(1 << SPR0)|(1 << CPHA);
}

uint8_t transfer (uint8_t data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}


