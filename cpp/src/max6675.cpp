/* 
* max6675.cpp
*
* Created: 11.09.2015 15:24:40
* Author: User
*/


#include "max6675.h"

// default constructor

#ifdef SoftSpi	
max6675::max6675(PORT n, uint8_t _cs, uint8_t _sck, uint8_t _miso)
:pin(n)
{
	pin.setDirPin(_cs);
	pin.setDirPin(_sck);
} 

#else
max6675::max6675()
{
	
} 
#endif


 double max6675::get_temp ()
 {
	 uint16_t temp;
	 spi1.CS_CLEAR();
	 temp = spi1.transfer(0);
	 temp <<=8;
	 temp |= spi1.transfer(0);
	 temp >>= 3;
	 return temp*0.25;
 }


