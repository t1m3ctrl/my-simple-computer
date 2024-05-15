#include <myTerm.h>

int
mt_delline (void)
{
  printf ("\E[K");
  return 0;
}