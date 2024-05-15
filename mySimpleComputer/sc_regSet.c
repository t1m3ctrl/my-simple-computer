#include <mySimpleComputer.h>
#include <sc.h>

int
sc_regSet (int regist, int value)
{
  if (regist > 0 && regist < 6)
    {
      if (value == 1)
        {
          flagRegister = flagRegister | (1 << (regist - 1));
          return 0;
        }
      else if (value == 0)
        {
          flagRegister = flagRegister & (~(1 << (regist - 1)));
          return 0;
        }
      else
        {
          sc_regSet (OVERFLOW_OPERATION, 1);
          return -1;
        }
    }
  else
    {
      sc_regSet (OVERFLOW_OPERATION, 1);
      return -1;
    }
}