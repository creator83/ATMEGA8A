/* 
* Timer1.h
*
* Created: 03.09.2015 14:53:53
* Author: User
*/
#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef __TIMER1_H__
#define __TIMER1_H__


class Timer1
{//variables
	public:
	enum prsk {no_div =1 , div8  , div64 , div256 , div1024};
	enum mode {OVF, CTC};
	enum intr {TOIE , OCRB , OCRA , TICIE};


	private:

	prsk div;

	//functions
	public:
	Timer1(prsk p , mode m);
	void Start ();
	void Stop ();
	void Set_Tcnt (uint16_t);
	void Set_OcrA (uint16_t);
	void Set_OcrB (uint16_t);
	void interpt (intr i);
	
	
	private:


}; //Timer1

ISR (TIMER1_COMPA_vect);
ISR (TIMER1_COMPB_vect);
ISR (TIMER1_OVF_vect);

#endif //__TIMER1_H__
