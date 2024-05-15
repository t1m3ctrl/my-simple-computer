#include <myTerm.h>

int
mt_setdefaultcolor (void)
{
  printf ("\E[97m\E[40m");

  return 0;
}