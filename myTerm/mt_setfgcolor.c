#include "../include/mt.h"

int
mt_setfgcolor (enum colors color)
{
  char seq[16];
  int len = snprintf (seq, sizeof (seq), "\033[3%dm", color);
  if (write (STDOUT_FILENO, seq, len) == -1)
    return -1;

  return 0;
}