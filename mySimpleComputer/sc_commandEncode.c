#include "../include/sc.h"

int
sc_commandEncode (int sign, int command, int operand, int *value)
{
  if (sign < 0 || sign > 1 || command < 0 || command > SC_COMMAND_MASK || operand < 0 || operand > SC_OPERAND_MASK)
    {
      return -1;
    }

  *value = (sign << SC_SIGN_BIT) | (command << (SC_OPERAND_BITS + 1)) | operand;
  return 0;
}