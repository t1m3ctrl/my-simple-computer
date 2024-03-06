#include "../include/sc.h"

int
sc_regGet (int reg, int *value)
{
  if (reg < FLAG_OVERFLOW || reg > FLAG_INVALID_COMMAND || !value)
    return -1;

  *value = (flag_register >> reg) & 0x1;
  return 0;
}