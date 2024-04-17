#include "../include/bc.h"

int
bc_printbigchar (int *big, int x, int y, enum colors fg, enum colors bg)
{
  int fd = STDOUT_FILENO;

  char cmd1[] = "\033(0";
  char cmd2[] = "\033(B";

  int result = write (fd, cmd1, sizeof (cmd1) - 1);
  printf ("\n");

  mt_setbgcolor (bg);
  mt_setfgcolor (fg);
  printf ("\n");

  for (size_t i = 0; i < 8; i++)
    {
      mt_gotoXY (x + i, y);
      for (int k = 7; k > -1; k--)
        {
          int value = 0;
          bc_getbigcharpos (big, i, k, &value);
          if (value)
            printf ("a");
          else
            printf (" ");
        }
      printf ("\n");
    }

  result = write (fd, cmd2, sizeof (cmd2) - 1);
  printf ("\n");

  mt_setdefaultcolor ();
  printf ("\n");

  if (result != -1)
    return 0;
  else
    return -1;
}