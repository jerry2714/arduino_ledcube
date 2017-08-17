#ifndef __STANDBY_H__
#define __STANDBY_H__
#define delay_time 1
#include <Adafruit_NeoPixel.h>  
typedef Adafruit_NeoPixel LedStrip;
/*************stand_by*******************************/
void red(LedStrip*);
void green(LedStrip*);
void blue(LedStrip*);
void cyan(LedStrip*);
void magenta(LedStrip*);
void yellow(LedStrip*);

/****************************************************/
#endif