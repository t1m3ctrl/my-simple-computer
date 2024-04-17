#include "../include/bc.h"

int
bc_getbigcharpos (int *big, int x, int y, int *value)
{
  if (y < 0 || y > 7 || x < 0 || x > 7)
    return -1;
  *value = 0;
  if (x > -1 && x < 4)
    *value = (big[0] >> (y + x * 8 - 1)) & 0x1;
  else if (x > 3 && x < 8)
    *value = (big[1] >> (y + (x - 4) * 8 - 1)) & 0x1;
  return 0;
}