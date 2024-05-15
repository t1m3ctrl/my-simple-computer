#include <myTerm.h>

int
mt_clrscr (void)
{
  printf ("\E[H\E[2J");
  return 0;
}