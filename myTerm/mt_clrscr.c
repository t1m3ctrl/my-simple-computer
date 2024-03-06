#include "mt.h"

int
mt_clrscr (void)
{
  char seq[] = "\033[H\033[J";
  if (write (STDOUT_FILENO, seq, sizeof (seq) - 1) == -1)
    return -1;
  return 0;
}