/* 
* Timer0.h
*
* Created: 26.06.2015 10:03:46
* Author: User
*/
#include <avr/io.h>
#include <avr/interrupt.h>


#ifndef __TIMER0_H__
#define __TIMER0_H__


class Timer0
{
//variables
public:
	enum prsk {no_div =1 , div8  , div64 , div256 , div1024};
	enum intr {Disable , Enable};

protected:
private:

	prsk div;

//functions
public:
	Timer0(prsk p);
	void Start ();
	void Stop ();
	void Set_Tcnt (unsigned char val);
	void interpt (intr i);	

protected:
private:


}; //Timer0

#endif //__TIMER0_H__
