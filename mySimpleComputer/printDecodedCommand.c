#include <mySimpleComputer.h>
#include <myTerm.h>
#include <sc.h>

void
printDecodedCommand (int value)
{
  mt_gotoXY (2, 18);
  mt_setfgcolor (WHITE);
  printf ("dec: %d | oct: %o | hex: %X | bin: ", value, value, value);
  for (int i = 15; i >= 0; i--)
    {
      printf ("%d", (value >> i) & 1);
    }
  mt_setfgcolor (DEFAULT);
}
