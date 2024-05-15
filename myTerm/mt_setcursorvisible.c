#include <myTerm.h>

int
mt_setcursorvisible (int value)
{
  if (value)
    {
      printf ("\033[?25h");
    }
  else
    {
      printf ("\033[?25l");
    }
  return 0;
}