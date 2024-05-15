#include <mySimpleComputer.h>
#include <sc.h>

int
sc_memoryGet (int address, int *value)
{
  // int index = memory[address];
  int index;
  if (address < 0 || address > 128)
    {
      sc_regSet (OUT_OF_MEMORY_BOUNDS, 1);
      return 0;
    }
  else
    {
      int newAddress = address;
      newAddress = newAddress / 10 * 10;
      sc_updateCacheAfterSave (address, newAddress, &index);
      *value = index;
    }
  return 0;
}
