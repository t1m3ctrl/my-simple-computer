#include <mySimpleComputer.h>
#include <myTerm.h>
#include <sc.h>

int
sc_memorySet (int address, int value)
{
  int index;
  if ((address < 0 || address > 128) || (value < 0 || value > 65535))
    {
      sc_regSet (OUT_OF_MEMORY_BOUNDS, 1);
      printf ("OUT_OF_MEMORY_BOUNDS, address: %x\n", address);
      return -1;
    }

  int newAddress = address;
  newAddress = newAddress / 10 * 10;
  sc_updateCacheAfterSave (address, newAddress, &index);
  memory[address] = value;
  return 0;
}