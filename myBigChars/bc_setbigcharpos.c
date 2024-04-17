#include "../include/bc.h"

int
bc_setbigcharpos (int *big, int x, int y, int value)
{
  if (y < 0 || y > 7 || x < 0 || x > 7)
    return -1;
  if (x > -1 && x < 4)
    {
      if (value == 1)
        big[0] = big[0] | (1 << (y + x * 8 - 1));
      else
        big[0] = big[0] & (~(1 << (y + x * 8 - 1)));
    }
  else if (x > 3 && x < 8)
    {
      if (value == 1)
        big[1] = big[1] | (1 << (y + (x - 4) * 8 - 1));
      else
        big[1] = big[1] & (~(1 << (y + (x - 4) * 8 - 1)));
    }
  return 0;
}