#include <console.h>
#include <sc.h>

int
ALU (int command, int operand)
{
  int value;
  if (sc_memoryGet (operand, &value) == -1)
    {
      sc_regSet (OUT_OF_MEMORY_BOUNDS, 1);
      return -1;
    }
  switch (command)
    {
    case 0x1E:
      accumulator += value;
      if (accumulator > 32767 || accumulator < -32767)
        {
          sc_regSet (OVERFLOW_OPERATION, 1);
          return -1;
        }
      count++;
      break;
    case 0x1F:
      accumulator -= value;
      if (accumulator > 32767 || accumulator < -32767)
        {
          sc_regSet (OVERFLOW_OPERATION, 1);
          return -1;
        }
      count++;
      break;
    case 0x20:
      if (value == 0)
        {
          sc_regSet (DIVISION_ERR_BY_ZERO, 1);
          return -1;
        }
      accumulator /= value;
      count++;
      break;
    case 0x21:
      accumulator *= value;
      if (accumulator > 32767 || accumulator < -32767)
        {
          sc_regSet (OVERFLOW_OPERATION, 1);
          return -1;
        }
      count++;
      break;
    default:
      return -1;
    }
  return 0;
}