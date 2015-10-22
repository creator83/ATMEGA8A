#include "max6675.h"
#include "spi.h"



#ifdef SOFTSPI

void max6675_init (void)
{
	PinDDR |= (1 << sclk)|(1 << cs);
	PinDDR &= ~1 << miso;
	PinPORT |= 1 << cs;
	
}

uint8_t spiread(void)
{
  int8_t i;
  uint8_t d = 0;

  for (i=7; i>=0; i--)
  {
    PinPORT &=~(1 << sclk);
    _delay_ms(1);
    if ((PinPORT & (1 << miso)))
    {
      //set the bit to 0 no matter what
      d |= (1 << i);
    }

    PinPORT |=(1 << sclk);
    _delay_ms(1);
  }
  return d;
}

uint8_t readCelsius(void)
{
  uint16_t v;

  CS_clear;
  _delay_ms(1);

  v = spiread();
  v <<= 8;
  v |= spiread();

   CS_set;

  if (v & 0x4) {
    // uh oh, no thermocouple attached!
    return 0; 
    //return -100;
  }

  v >>= 3;

  return (uint8_t)v*0.25;
}
#else

void max6675_init (void)
{
	spi_init ();
}


uint8_t readCelsius(void)
{
  uint16_t v;

  CS_CLEAR;
  _delay_ms(1);

  v = transfer(0);
  v <<= 8;
  v |= transfer(0);

  CS_SET;

  if (v & (1 << TC)) 
  {
    // uh oh, no thermocouple attached!
    return 0; 
    //return -100;
  }

  v >>= 3;

  return (uint8_t)v*0.25;
}
#endif






