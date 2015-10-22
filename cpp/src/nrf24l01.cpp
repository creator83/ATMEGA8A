/* 
* nrf24l01.cpp
*
* Created: 04.08.2015 21:37:23
* Author: KOSHELEV
*/


#include "nrf24l01.h"


nrf24l01::nrf24l01()
:pin (Gpio::B) , irq_(intrpt::INTRPT0 , intrpt::FallEdge)
{
	  pin.setDirPin (ce_);
	  init ();
} 


uint8_t nrf24l01::wr_reg (uint8_t r_n_reg , uint8_t mask1, uint8_t mask2)
{
	char SR=SREG;//сохраняем значение регистра
	cli();
	uint8_t reg = 0;
	spi1.CS_CLEAR();
	spi1.transfer (mask1 + r_n_reg);
	reg = spi1.transfer (mask2);
	spi1.CS_SET ();
	SREG=SR;
	return reg;
}

uint8_t nrf24l01::command (uint8_t mask)
{
	char SR=SREG;//сохраняем значение регистра
	cli();
	uint8_t status = 0;
	spi1.CS_CLEAR();
	status = spi1.transfer (mask);
	spi1.CS_SET ();
	SREG=SR;
	return status;
}

void nrf24l01::set_bit (uint8_t reg_ister, uint8_t register_bit, uint8_t W)
{
	uint8_t buf;
	buf = wr_reg (reg_ister , R_REGISTER , NOP);
	if (W) buf=buf|(1<<register_bit);
	else buf=buf&(~(1<<register_bit));
	wr_reg (reg_ister , W_REGISTER , buf);
}

void nrf24l01::mode (state st)
{
	//переход в режим приемника
	pin.clearPin (ce_);
	//переключаемся между режимами меняя PRIM_RX бит
	set_bit (CONFIG , PRIM_RX , st);
	//переходим в один из режимов
	pin.setPin (ce_);
	_delay_us (15);
	if (!st) pin.clearPin (ce_);
	_delay_us (150);
}

void nrf24l01::write_data (uint8_t data)
{
	spi1.CS_CLEAR();
	spi1.transfer (W_TX_PAYLOAD);
	spi1.transfer (data);
	spi1.CS_SET ();
}

void nrf24l01::transmit (uint8_t data)
{
	write_data (data);
	mode (transmitter);
	mode (receiver);
}

uint8_t nrf24l01::read_data ()
{
	uint8_t data;
	spi1.CS_CLEAR();
	spi1.transfer (R_RX_PAYLOAD);
	data = spi1.transfer (NOP);
	spi1.CS_SET ();
	return data;
}


void nrf24l01::init (uint8_t m )
{
	spi1.CS_SET();
	pin.clearPin (ce_);
	_delay_ms (15);
	set_bit (RX_PW_P0,0,1);
	
	//определяем прерывания (вкл/выключаем) их 3-и по умолчанию включены все!
	set_bit (CONFIG , MASK_MAX_RT , m&(1 << 0));
	set_bit (CONFIG , MASK_TX_DS , m&(1 << 1));
	set_bit (CONFIG , MASK_RX_DR , m&(1 << 2));
	
	//устанавливаем бит вкл в единицу (включаем модуль)
	set_bit (CONFIG , PWR_UP , 1);
	_delay_ms (2);
	
}