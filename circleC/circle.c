#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


void circle (int cx, int cy, int radius)
{
  int error = -radius;
  int x = radius;
  int y = 0;


  while (x >= y)
  {
    plot8points (cx, cy, x, y);
    error += y;
    ++y;
    error += y;

    if (error >= 0)
    {
      --x;
      error -= x;
      error -= x;
    }
  }
}


void
plot8points (int cx, int cy, int x, int y)
{
  plot4points (cx, cy, x, y);
  if (x != y) plot4points (cx, cy, y, x);
}


void
plot4points (int cx, int cy, int x, int y)
{
  setPixel (cx + x, cy + y);
  if (x != 0) setPixel (cx - x, cy + y);
  if (y != 0) setPixel (cx + x, cy - y);
  if (x != 0 && y != 0) setPixel (cx - x, cy - y);
}
