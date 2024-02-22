#include "sc.h"

int
sc_memoryGet (int address, int *value)
{
  if (address < 0 || address >= MEMORY_SIZE || !value)
    {
      return -1;
    }
  *value = memory[address];
  return 0;
}