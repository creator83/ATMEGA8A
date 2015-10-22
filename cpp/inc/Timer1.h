/* 
* Timer1.h
*
* Created: 05.09.2015 21:18:38
* Author: KOSHELEV
*/
#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef __TIMER1_H__
#define __TIMER1_H__


class Timer1
{
//variables
public:
enum prsk {no_div =1 , div8  , div64 , div256 , div1024};
enum intr {TOIE , OCIEB , OCIEA  , TICIE};
enum mode {OVF , CTC};
enum OCR {A , B};

protected:
private:

prsk div;

//functions
public:
Timer1(prsk, mode);
void Start ();
void Stop ();
void Set_Tcnt (uint16_t val);
void Set_OCR (uint16_t val, OCR);
void interpt (intr i);
}; //Timer1

#endif //__TIMER1_H__
