#include "../include/bc.h"
#include <stdio.h>

int
bc_bigcharwrite (int fd, int *big, int count)
{
  int result = write (fd, big, count * 4);

  // printf("\n%d\n",result);

  if (result != -1)
    return 0;
  else
    return -1;
}