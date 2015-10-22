/* 
* intrpt.cpp
*
* Created: 26.06.2015 11:16:07
* Author: User
*/

#include "intrpt.h"

unsigned char intrpt::Regstr [2][3] = {
	{0 , 2 , 6}, //MCUCR , PORTD , GICR
	{2 , 3 , 7} // MCUCR , PORTD , GICR
	};
	

// default constructor
intrpt::intrpt(INT i, SCtrl e)
:pin (Gpio::D)
{
	pin.setDirPin(Regstr[i][1], Gpio::IN);	
	if (e==3)
	{
		pin.clearPin(Regstr[i][1]);
	}
	else
	{
		pin.setPin(Regstr[i][1]);
	}
	MCUCR |= e << Regstr[i][0];
	GICR |= 1 << Regstr[i][2];
	sei ();	
} //intrpt

