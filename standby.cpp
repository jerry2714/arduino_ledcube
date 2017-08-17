#include"standby.h"

void red(LedStrip *ledstrip)//255,0,0
{
  //led breath from dark to bright
  for(int j=0;j<=255;j++)
  {
    for(int i=0;i<ledstrip -> numPixels();i++)
    {
      ledstrip -> setPixelColor(i, j, 0, 0);
    }
    ledstrip -> show();
    //delay(delay_time);
  }
  //led breath from bright to dark
  for(int j=255;j>=0;j--)
  {
    for(int i=0;i<ledstrip -> numPixels();i++)
    {
      ledstrip -> setPixelColor(i, j, 0, 0);
    }
    ledstrip -> show();
    delay(delay_time);
  }
}
///////////////////////////////////////////////////////
void green(LedStrip *ledstrip)//0,255,0
{
  //led breath from dark to bright
  for(int j=0;j<=255;j++)
  {
    for(int i=0;i<ledstrip -> numPixels();i++)
    {
      ledstrip -> setPixelColor(i, 0, j, 0);
    }
    ledstrip -> show();
    delay(delay_time);
  }
  //led breath from bright to dark
  for(int j=255;j>=0;j--)
  {
    for(int i=0;i<ledstrip -> numPixels();i++)
    {
      ledstrip -> setPixelColor(i, 0, j, 0);
    }
    ledstrip -> show();
    delay(delay_time);
  }
}
////////////////////////////////////////////////////////////
void blue(LedStrip *ledstrip)//0,0,255
{
  //led breath from dark to bright
  for(int j=0;j<=255;j++)
  {
    for(int i=0;i<ledstrip -> numPixels();i++)
    {
      ledstrip -> setPixelColor(i, 0, 0, j);
    }
    ledstrip -> show();
    delay(delay_time);
  }
  //led breath from bright to dark
  for(int j=255;j>=0;j--)
  {
    for(int i=0;i<ledstrip -> numPixels();i++)
    {
      ledstrip -> setPixelColor(i, 0, 0, j);
    }
    ledstrip -> show();
    delay(delay_time);
  }
}
/////////////////////////////////////////////////////////
void cyan(LedStrip *ledstrip)//0,255,255
{
  //led breath from dark to bright
  for(int j=0;j<=255;j++)
  {
    for(int i=0;i<ledstrip -> numPixels();i++)
    {
      ledstrip -> setPixelColor(i, 0, j, j);
    }
    ledstrip -> show();
    delay(delay_time);
  }
  //led breath from bright to dark
  for(int j=255;j>=0;j--)
  {
    for(int i=0;i<ledstrip -> numPixels();i++)
    {
      ledstrip -> setPixelColor(i, 0, j, j);
    }
    ledstrip -> show();
    delay(delay_time);
  }
}
/////////////////////////////////////////////////////////
void magenta(LedStrip *ledstrip)//255,0,255
{
  //led breath from dark to bright
  for(int j=0;j<=255;j++)
  {
    for(int i=0;i<ledstrip -> numPixels();i++)
    {
      ledstrip -> setPixelColor(i, j, 0, j);
    }
    ledstrip -> show();
    delay(delay_time);
  }
  //led breath from bright to dark
  for(int j=255;j>=0;j--)
  {
    for(int i=0;i<ledstrip -> numPixels();i++)
    {
      ledstrip -> setPixelColor(i, j, 0, j);
    }
    ledstrip -> show();
    delay(delay_time);
  }
}
/////////////////////////////////////////////////////////
void yellow(LedStrip *ledstrip)//255,255,0
{
  //led breath from dark to bright
  for(int j=0;j<=255;j++)
  {
    for(int i=0;i<ledstrip -> numPixels();i++)
    {
      ledstrip -> setPixelColor(i, j, j, 0);
    }
    ledstrip -> show();
    delay(delay_time);
  }
  //led breath from bright to dark
  for(int j=255;j>=0;j--)
  {
    for(int i=0;i<ledstrip -> numPixels();i++)
    {
      ledstrip -> setPixelColor(i, j, j, 0);
    }
    ledstrip -> show();
    delay(delay_time);
  }
}

