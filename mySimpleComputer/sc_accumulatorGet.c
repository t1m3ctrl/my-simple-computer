#include <mySimpleComputer.h>
#include <sc.h>

int
sc_accumulatorGet (int *value)
{
  if (value == 0)
    {
      return -1;
    }

  *value = accumulator;
  return 0;
}