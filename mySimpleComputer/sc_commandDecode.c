#include <mySimpleComputer.h>
#include <sc.h>

int
sc_commandDecode (int value, int *command, int *operand)
{
  if ((value >> 14) != 0x0)
    {
      return -1;
    }
  *command = value >> 7;
  *operand = value & 0x7F;
  if (!(sc_commandValidate (*command)))
    {
      *command = 0;
      *operand = 0;
      return -1;
    }
  return 0;
}