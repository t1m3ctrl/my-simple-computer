#include "../include/bc.h"
#include <stdio.h>
#include <unistd.h>

int
bc_printA (char *str)
{
  int fd = STDOUT_FILENO;

  char cmd1[] = "\033(0";
  char cmd2[] = "\033(B";

  if (write (fd, cmd1, sizeof (cmd1) - 1) == -1)
    return -1;
  else
    {
      printf ("%s", str);
      if (write (fd, cmd2, sizeof (cmd2) - 1) == -1)
        return -1;
      else
        return 0;
    }
}