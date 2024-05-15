#include <mySimpleComputer.h>
#include <sc.h>

int
sc_regGet (int regist, int *value)
{
  if (regist > 0 && regist < 6)
    {
      *value = (flagRegister >> (regist - 1)) & 0x1;
      return 0;
    }
  else
    {
      sc_regSet (WRONG_FLAG, 1);
      return -1;
    }
}