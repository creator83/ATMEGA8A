/* 
* Timer.h
*
* Created: 02.02.2015 11:36:24
* Author: User
*/
#define F_CPU 1000000
#include <avr/io.h>
#include <avr/interrupt.h>



#ifndef __TIMER_H__
#define __TIMER_H__


typedef unsigned char* reg;

const unsigned char OCR0A = 0x4B;
const unsigned char OCR0B = 0x49;

class Timer
{
//variables
public:
	enum num_timer {timer0 , timer1 , timer2};
	enum compare {A , B};
	enum prsk {no_div =1 , div8  , div64 , div256 , div1024};	
	//enum prsk2 {no_div = 1 , div8   ,div32 , div64 , div64 , div256 , div1024};
	enum timer_mode {OVF , PWM , CTC , FastPWM};	
	enum interrupt {Ovf0 , Ovf1 =2, Ocr1B , Ocr1A}; 
	prsk div;
	num_timer t;
	timer_mode m;
	union counter
	{
		unsigned int cnt16;
		unsigned char cnt8[2];
	};	
	union cmpr
	{
		unsigned int ocr16;
		unsigned char ocr8[2];
	};	
protected:
private:
	static unsigned char TCCR [3];
	static unsigned char TCNT [2];
//functions
public:
	
	Timer(num_timer n , prsk p , timer_mode mode = OVF);
	//Timer (prsk p); //
	void Start ();
	void Stop ();
	void Set_Ocr (compare n_cmpr , unsigned int ocr);
	void Set_Tcnt (unsigned int val);
	void interpt (interrupt i);
		
private:


}; //Timer

#endif //__TIMER_H__
