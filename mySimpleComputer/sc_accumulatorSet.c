#include <mySimpleComputer.h>
#include <sc.h>

int
sc_accumulatorSet (int value)
{
  if (value < -32768 || value > 32767)
    {
      return -1;
    }

  accumulator = value;
  return 0;
}
