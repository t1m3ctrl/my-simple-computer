#include <console.h>
#include <sc.h>

int
CU (void)
{
  int operand, command, value, InputValue, valueAc;
  flagUi = false;

  sc_memoryGet (count, &value);
  sc_commandDecode (value, &command, &operand);
  sc_icounterSet (count);
  if (sc_commandValidate (command) == 0)
    {
      sc_regSet (INCORRECT_COMMAND_RECEIVED, 4);
      return -1;
    }
  if (command >= 0x1E && command <= 0x21)
    {
      return ALU (command, operand) == 0 ? 0 : -1;
    }

  switch (command)
    {
    case 0x0:
      if (count < 127)
        {
          count++;
        }

      break;
    case 0x1:
      flagUi = true;
      if (count < 127)
        {
          count++;
        }

      break;
    case 0xA:
      alarm (0);
      ticks = 0;
      rk_myTermRegime (1, 1, 1, 1, 1);
      scanf ("%d", &InputValue);

      rk_myTermRegime (0, 0, 1, 0, 1);
      if (sc_memorySet (operand, InputValue) == -1)
        {
          sc_regSet (OUT_OF_MEMORY_BOUNDS, 1);
          return -1;
        }

      printTerm (count, 1, membuffer);
      if (count < 127)
        {
          count++;
        }

      break;
    case 0xB:

      if (sc_memoryGet (operand, &value) == -1)
        {
          sc_regSet (OUT_OF_MEMORY_BOUNDS, 1);
          return -1;
        }
      printf ("%X", value);
      ticks = 0;

      printTerm (operand, 0, membuffer);
      if (count < 127)
        {
          count++;
        }

      break;
    case 0x14:
      if (sc_memoryGet (operand, &value))
        {
          return -1;
        }

      accumulator = value;
      printTerm (count, 0, membuffer);
      if (count < 127)
        {
          count++;
        }

      break;
    case 0x15:
      if (sc_memorySet (operand, accumulator) == -1)
        {
          sc_regSet (OUT_OF_MEMORY_BOUNDS, 1);
          return -1;
        }
      printTerm (operand, 1, membuffer);
      printTerm (operand, 0, membuffer);
      if (count < 127)
        {
          count++;
        }

      break;
    case 0x28:
      ticks = 0;
      count = operand - 1;
      if (count < 127)
        {
          count++;
        }

      break;
    case 0x29:
      ticks = 0;
      if (accumulator < 0)
        {
          count = operand - 1;
        }
      if (count < 127)
        {
          count++;
        }

      break;
    case 0x2A:
      ticks = 0;
      if (accumulator == 0)
        {
          count = operand - 1;
        }
      if (count < 127)
        {
          count++;
        }

      break;
    case 0x2B:
      return -1;
      break;
    case 0x3A:
      break;
    case 0x37:
      if (accumulator > 0)
        {
          count = operand - 1;
        }
      if (count < 128)
        {
          count++;
        }

      break;
    case 0x42:
      if (sc_memoryGet (operand, &value) == -1)
        {
          sc_regSet (OUT_OF_MEMORY_BOUNDS, 1);
          return -1;
        }
      if (sc_memoryGet (accumulator, &valueAc) == -1)
        {
          sc_regSet (OUT_OF_MEMORY_BOUNDS, 1);
          return -1;
        }
      accumulator -= valueAc;
      if (count < 127)
        {
          count++;
        }

      break;
    default:
      if (ALU (command, operand))
        return -1;
    }
  return 0;
}