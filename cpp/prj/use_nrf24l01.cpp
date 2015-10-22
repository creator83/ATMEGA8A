/*
 * use_nrf24l01.cpp
 *
 * Created: 04.08.2015 21:38:12
 *  Author: KOSHELEV
 */ 
#define F_CPU 8000000
#include <avr/io.h>
#include "nrf24l01.h"
#include "uart.h"

uart uart1 (uart::baud9600);
uint8_t stat;
nrf24l01 radio;
/*	
ISR (INT0_vect)
{
	stat = radio.command(NOP);
	if (stat&(1 << 6))
	{
		//отправляем принятые данные через UART
		uart1.transmit(radio.read_data());
		//сбрасываем прерывание по приему пакета
		radio.set_bit(STATUS,RX_DR,1);
	}
	_delay_us(10);
}

*/
ISR (INT1_vect)
{
		//отправляем принятые данные через UART
		uart1.transmit(10);
		//сбрасываем прерывание по приему пакета
		
}
int main ()
{
	radio.mode(nrf24l01::receiver);
	intrpt I1 (intrpt::INTRPT1 , intrpt::RiseEdge);
	sei();


	while (1)
	{
		
	}
}