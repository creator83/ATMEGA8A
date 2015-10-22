/*
 * hcsr4.c
 *
 * Created: 29.09.2015 19:29:47
 *  Author: KOSHELEV
 */ 
#include "hcsr4.h"

unsigned int N_takt=0; //глобальная переменная хранения тактов

void HC_SRC4_Init(void)
{
	//устанавливаем ножки на выход и вход соответственно
	Trig_DDR |= 1<<Trig_N;
	Trig_PORT &= ~(1<<Trig_N);
	
	Echo_DDR &= ~(1<<Echo_N);
	Echo_PORT &= ~(1<<Echo_N);
}

void HC_SRC4_Send_strob(void) // отправляем 20мкс Строб
{
	Trig_PORT |= 1<<Trig_N;	//устанавливаем ЛОГ 1
	_delay_us(20); //длительность импульса
	Trig_PORT &= ~(1<<Trig_N);	//устанавливаем ЛОГ 0
}

void init_interp (void) //разрешение прерываний по любому фронту
{
	MCUCR |=(1<<ISC00); //Прерывание по любому фронту
	GICR |= (1<<INT0);   //разрешение прерывания на INT0
}

unsigned int timer_Start_Stop (char flag) //функция Запуска и Остановки
{
	unsigned int rez; // для хранения тактов
	
	if(flag)
	{
		TCNT1H = 0;	//обнуляем
		TCNT1L = 0;
		TCCR1B |=(1<<CS11); //запуск таймера с предделителем 8
		return 0;
	}
	else
	{
		TCCR1B &= ~(1<<CS11); //Останавливаем таймер
		rez = TCNT1H;
		rez <<= 8;
		rez |=TCNT1L;
		
		return rez;
	}
}

//функция преобр числа насчитанных тактов в растояние
uint8_t HC_SRC4_Convert_CM (unsigned int N_t)
{
	unsigned long int C;
	C = N_t * 8; //определяем время импульса
	C /= 58; // вычисляем расстояние в сантиметрах
	C +=1;
	
	return (uint8_t)C;
}

// функцию вызываещь и она возвр знач растояния
uint8_t HC_SRC4_Get_CM (void)
{
	HC_SRC4_Send_strob(); //отправляем строб
	
	_delay_ms(100);
	return HC_SRC4_Convert_CM(N_takt);  //возвращаем значение в СМ
}