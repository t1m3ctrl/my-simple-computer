#include <myTerm.h>

int
mt_delline (void)
{
  printf ("\033[K");
  return 0;
}