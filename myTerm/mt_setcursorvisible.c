#include "mt.h"

int
mt_setcursorvisible (int value)
{
  char *seq = value ? "\033[?25h" : "\033[?25l";
  if (write (STDOUT_FILENO, seq, 6) == -1)
    return -1;
  return 0;
}