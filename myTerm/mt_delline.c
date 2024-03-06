#include "../include/mt.h"

int
mt_delline (void)
{
  char seq[] = "\033[M";
  if (write (STDOUT_FILENO, seq, sizeof (seq) - 1) == -1)
    return -1;
  return 0;
}
