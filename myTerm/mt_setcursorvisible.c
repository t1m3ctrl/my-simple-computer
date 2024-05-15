#include <myTerm.h>

int
mt_setcursorvisible (int value)
{
  if (value)
    {
      printf ("\E[?25h");
    }
  else
    {
      printf ("\E[?25l");
    }
  return 0;
}