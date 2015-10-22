/*
 * spi.h
 *
 * Created: 22.10.2015 9:51:47
 *  Author: User
 */ 
#include <avr/io.h>

#define SPIDDR  DDRB
#define SPIPORT PORTB
#define CS      2
#define SCK     5
#define MOSI    3
#define MISO    4

#define CS_SET SPIPORT |= 1 << CS
#define CS_CLEAR SPIPORT &= ~(1 << CS)

#ifndef SPI_H_
#define SPI_H_

void spi_init (void);

uint8_t transfer (uint8_t data);

#endif /* SPI_H_ */