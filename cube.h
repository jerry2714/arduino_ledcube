#ifndef __LEDCUBE_H__
#define __LEDCUBE_H__
#define change_bright 80
#define PIX_NUM 216
#define LEDCUBE_PIN 6



#include<arduino.h>
#include<avr/wdt.h>
#include"queue.h"
#include"SerialProcessor.h"
#include"standby.h"
#include"util.h"
#include"backgroundpattern.h"
#include <Adafruit_NeoPixel.h>

#define SET              0
#define CLEAR_AND_SET    1 
#define SET_BACKGROUND   2
#define SAME_COLOR       3
#define SAME_COLOR_STRIP 4
#define STRIP            5
#define SET_LINE         6
#define SEND_OUT         2

Adafruit_NeoPixel ledstrip = Adafruit_NeoPixel(PIX_NUM, LEDCUBE_PIN, NEO_RGB + NEO_KHZ400);
CQueue queue;
SerialProcessor sp(&queue);

inline void commandTranslate();
inline void loadData(int);
inline byte readByte();

/***************operations****************************/
//assign
inline void set(bool output, int num);
inline void clearAndSet(bool output, int num);
inline void setBackground(bool output, int num);
inline void sameColor(bool output, int num);
inline void sameColorStrip(bool output, int offset, int length);
inline void strip(bool output, int offset, int length);
inline void set_line(bool output, int input001, int input002);
inline void send_out();
//
/*****************************************************/

void standBy()
{
    //red(&ledstrip);
    //green(&ledstrip);
    blue(&ledstrip);
    /*cyan(&ledstrip);
    magenta(&ledstrip);
    yellow(&ledstrip);*/
}

#endif
