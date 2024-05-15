#include <mySimpleComputer.h>
#include <sc.h>

int
sc_commandEncode (int command, int operand, int *value)
{
  if (command > 0x7F)
    return -1;
  if (operand > 0x7F)
    return -1;

  *value = 0;

  for (int i = 0; i < 7; i++)
    {
      int bit = (operand >> i) & 1;
      *value |= (bit << i);
    }
  for (int i = 0; i < 7; i++)
    {
      int bit = (command >> i) & 1;
      *value |= (bit << (i + 7));
    }
  // if (!sc_commandValidate(command & 0x7F))
  //   {
  //     sc_regSet (INCORRECT_COMMAND_RECEIVED, 1);
  //     //return -1;
  //   }
  // *value = (command << 7) | operand;
  return 0;
}