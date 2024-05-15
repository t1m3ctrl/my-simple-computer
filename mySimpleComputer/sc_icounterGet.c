#include <mySimpleComputer.h>
#include <sc.h>

int
sc_icounterGet (int *value)
{
  if (value == NULL)
    {
      return -1;
    }

  *value = count;
  return 0;
}