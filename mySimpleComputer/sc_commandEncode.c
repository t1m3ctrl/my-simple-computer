#include <mySimpleComputer.h>
#include <sc.h>

int
sc_commandEncode (int command, int operand, int *value)
{
  if (!(sc_commandValidate (command)) || operand < 0 || operand > 127)
    {
      return -1;
    }
  *value = (command << 7) | operand;
  return 0;
}