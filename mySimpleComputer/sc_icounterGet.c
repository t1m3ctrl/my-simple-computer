#include "sc.h"

int
sc_icounterGet (int *value)
{
  if (!value)
    return -1;

  *value = command_counter;
  return 0;
}