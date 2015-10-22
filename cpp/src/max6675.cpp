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
} //max6675

#else
max6675::max6675()
{
	
} //max6675
#endif


