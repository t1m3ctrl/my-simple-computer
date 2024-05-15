#include <myTerm.h>

int
mt_setfgcolor (enum colors color)
{
  printf ("\E[38;5;%dm", color);
  return 0;
}