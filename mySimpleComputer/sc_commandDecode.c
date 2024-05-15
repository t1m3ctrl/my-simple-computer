#include <mySimpleComputer.h>
#include <sc.h>

int
sc_commandDecode (int value, int *command, int *operand)
{
  int tmpCom = 0, tmpOp = 0;
  if ((value >> 14) & 1)
    {
      sc_regSet (INCORRECT_COMMAND_RECEIVED, 4);
      return -1;
    }

  for (int i = 0; i < 7; i++)
    {
      int bit = (value >> i) & 1;
      tmpOp |= (bit << i);
    }

  for (int i = 0; i < 7; i++)
    {
      int bit = (value >> (i + 7)) & 1;
      tmpCom |= (bit << i);
    }

  *command = tmpCom;
  *operand = tmpOp;
  //  if((value >> 14) != 0x0)
  //   {
  //       return 0;
  //   }
  //   *command = value >> 7;
  //   *operand = value & 0x7F;
  //   if(!(sc_commandValidate(*command)))
  //   {
  // 	    *command = 0;
  // 	    *operand = 0;
  // 	    return -1;
  // }
  return 0;
}