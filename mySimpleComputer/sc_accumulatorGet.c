#include "sc.h"

int
sc_accumulatorGet (int *value)
{
  if (!value)
    return -1;

  *value = accumulator;
  return 0;
}