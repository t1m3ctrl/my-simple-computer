#include "../include/sc.h"

int
sc_commandValidate (int command)
{
  if (command < 0 || command > SC_COMMAND_MASK)
    {
      return -1;
    }
  return 0;
}