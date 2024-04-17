#include "../include/bc.h"
#include <stdio.h>

int
bc_bigcharread (int fd, int *big, int need_count, int *count)
{
  int result = read (fd, big, need_count * 4);
  if (result != -1)
    *count = result;
  else
    *count = 0;
  // for (size_t i = 0; (int)i < need_count; i++)
  // {
  //   printf("\n%d", big[i]);
  // }

  // printf("\n%d\n", result);
  if (result != -1)
    return 0;
  else
    return -1;
}