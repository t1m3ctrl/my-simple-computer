#include "../include/sc.h"

int
sc_regSet (int reg, int value)
{
  if (reg < FLAG_OVERFLOW || reg > FLAG_INVALID_COMMAND)
    return -1;

  if (value)
    flag_register = flag_register | (1 << reg);
  else
    flag_register = flag_register & ~(1 << reg);
  return 0;
}