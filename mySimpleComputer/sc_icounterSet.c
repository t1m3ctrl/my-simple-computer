#include "sc.h"

int
sc_icounterSet (int value)
{
  command_counter = value;
  return 0;
}