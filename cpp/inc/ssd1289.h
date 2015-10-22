/* 
* ssd1289.h
*
* Created: 18.06.2015 21:05:44
* Author: KOSHELEV
*/
#define F_CPU 8000000
#include <util/delay.h>
#include "Gpio.h"

#ifndef __SSD1289_H__
#define __SSD1289_H__


const unsigned int BLACK =	0x0000;
const unsigned int BLUE	 =  0xF800;
const unsigned int RED 	 =  0x001F;
const unsigned int GREEN =	0x07E0;
const unsigned int CYAN	 =  0x07FF;
const unsigned int MAGENTA= 0xF81F;
const unsigned int YELLOW=	0xFFE0;
const unsigned int WHITE=	0xFFFF;

class ssd1289
{
//variables
public:
protected:
private:
	Gpio pinDataLow;
	Gpio pinDataHigh;
	Gpio pinCommand;
	enum commPins {RST, WR , CS , RS ,RD};

//functions
public:
	ssd1289();
	void point (char x , char y, unsigned int color);
	void fill_screen (unsigned int color);
	void set_cursor (char x , char y);
protected:
private:
	void init();
	void index(unsigned int indx);
	void data(unsigned int dta);
	void wr_reg (unsigned int indx , unsigned int dta);

}; //ssd1289

#endif //__SSD1289_H__
