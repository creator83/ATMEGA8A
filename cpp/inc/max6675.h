/* 
* max6675.h
*
* Created: 11.09.2015 15:24:41
* Author: User
*/
#include <avr/io.h>
#include "Gpio.h"


#ifndef __MAX6675_H__
#define __MAX6675_H__

#define SoftSpi

class max6675
{
//variables
public:

	enum PORT {B, C, D};
			
private:

#ifdef SoftSpi	
	Gpio pin;
#else
	Spi spi1;
#endif

//functions
public:
#ifdef SoftSpi
	max6675(PORT , uint8_t _cs, uint8_t _sck, uint8_t _miso);

#else

	max6675();
	
#endif

protected:
private:

}; //max6675

#endif //__MAX6675_H__
