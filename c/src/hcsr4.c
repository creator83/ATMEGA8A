/*
 * hcsr4.c
 *
 * Created: 29.09.2015 19:29:47
 *  Author: KOSHELEV
 */ 
#include "hcsr4.h"

unsigned int N_takt=0; //���������� ���������� �������� ������

void HC_SRC4_Init(void)
{
	//������������� ����� �� ����� � ���� ��������������
	Trig_DDR |= 1<<Trig_N;
	Trig_PORT &= ~(1<<Trig_N);
	
	Echo_DDR &= ~(1<<Echo_N);
	Echo_PORT &= ~(1<<Echo_N);
}

void HC_SRC4_Send_strob(void) // ���������� 20��� �����
{
	Trig_PORT |= 1<<Trig_N;	//������������� ��� 1
	_delay_us(20); //������������ ��������
	Trig_PORT &= ~(1<<Trig_N);	//������������� ��� 0
}

void init_interp (void) //���������� ���������� �� ������ ������
{
	MCUCR |=(1<<ISC00); //���������� �� ������ ������
	GICR |= (1<<INT0);   //���������� ���������� �� INT0
}

unsigned int timer_Start_Stop (char flag) //������� ������� � ���������
{
	unsigned int rez; // ��� �������� ������
	
	if(flag)
	{
		TCNT1H = 0;	//��������
		TCNT1L = 0;
		TCCR1B |=(1<<CS11); //������ ������� � ������������� 8
		return 0;
	}
	else
	{
		TCCR1B &= ~(1<<CS11); //������������� ������
		rez = TCNT1H;
		rez <<= 8;
		rez |=TCNT1L;
		
		return rez;
	}
}

//������� ������ ����� ����������� ������ � ���������
uint8_t HC_SRC4_Convert_CM (unsigned int N_t)
{
	unsigned long int C;
	C = N_t * 8; //���������� ����� ��������
	C /= 58; // ��������� ���������� � �����������
	C +=1;
	
	return (uint8_t)C;
}

// ������� ��������� � ��� ����� ���� ���������
uint8_t HC_SRC4_Get_CM (void)
{
	HC_SRC4_Send_strob(); //���������� �����
	
	_delay_ms(100);
	return HC_SRC4_Convert_CM(N_takt);  //���������� �������� � ��
}