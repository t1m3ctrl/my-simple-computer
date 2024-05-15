#include <mySimpleComputer.h>
#include <sc.h>

int
sc_icounterSet (int value)
{
  if (value < 0 || value > 128)
    {
      return -1;
    }

  count = value;
  return 0;
}