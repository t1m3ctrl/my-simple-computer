#include <myBigChars.h>
#include <myTerm.h>

int
bc_printA (char str)
{
  printf ("\E(0%c\E(B", str);
  return 0;
}