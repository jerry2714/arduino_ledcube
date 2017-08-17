#include"util.h"
int coordinateConvert(int x, int y, int z)
{
   int l = 6;
    if(y % 2 == 0)
        return z*l*l + y*l + x;
    else
        return z*l*l + y*l + (l-x-1);
}
void invCoordinateConvert(int num, int& x, int& y, int& z)
{
  int l = 6;
  z = num / (l*l);
  num -= (z*l*l);
  y = num / l;
  num -= (y*l);
  if(y % 2 == 0)
    x = num;
  else
    x = l - num - 1;
}
