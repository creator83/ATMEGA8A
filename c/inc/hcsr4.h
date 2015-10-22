/*
 * hcsr4.h
 *
 * Created: 29.09.2015 19:30:08
 *  Author: KOSHELEV
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


//определяем ножку Echo
#define Echo_PORT PORTD
#define Echo_DDR DDRD
#define Echo_PIN PIND
#define Echo_N 2
//определяем ножку  Trig
#define Trig_PORT PORTD
#define Trig_DDR DDRD
#define Trig_PIN PIND
#define Trig_N 3


#ifndef HCSR4_H_
#define HCSR4_H_


void HC_SRC4_Init(void);
void HC_SRC4_Send_strob(void);
void init_interp (void);
unsigned int timer_Start_Stop (char flag);
uint8_t HC_SRC4_Convert_CM (unsigned int N_t);
uint8_t HC_SRC4_Get_CM (void);

#endif /* HCSR4_H_ */