#include "../include/sc.h"

int
sc_commandDecode (int value, int *sign, int *command, int *operand)
{
  if (value > 32768 - 1)
    {
      return -1;
    }

  *sign = (value & SC_SIGN_MASK) >> SC_SIGN_BIT;
  *command = (value >> (SC_OPERAND_BITS + 1)) & SC_COMMAND_MASK;
  *operand = value & SC_OPERAND_MASK;
  return 0;
}