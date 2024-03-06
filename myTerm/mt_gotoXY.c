#include "mt.h"

int
mt_gotoXY (int x, int y)
{
  char seq[16];
  int len = snprintf (seq, sizeof (seq), "\033[%d;%dH", x, y);
  if (write (STDOUT_FILENO, seq, len) == -1)
    return -1;
  return 0;
}