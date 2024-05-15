#include <mySimpleComputer.h>
#include <sc.h>

int
sc_memoryGet (int address, int *value)
{
  int index = memory[address];
  if (address < 0 || address >= 127)
    {
      sc_regSet (OUT_OF_MEMORY_BOUNDS, 1);
      return 0;
    }
  else
    {
      *value = index;
    }
  return 0;
}