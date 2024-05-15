#include <myTerm.h>

int
mt_setbgcolor (enum colors color)
{
  printf ("\E[48;5;%dm", color);
  return 0;
}