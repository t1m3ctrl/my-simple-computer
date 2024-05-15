#include <mySimpleComputer.h>
#include <myTerm.h>
#include <sc.h>

void
printDecodedCommand (int value)
{
  mt_gotoXY (2, 18);
  mt_setfgcolor (WHITE);
  // value &= 0x3FFF;
  if ((value >> 14) & 1)
    {
      if ((value >> 13) & 1)
        printf (
            "dec: -%d | oct: -%o | hex: -%X | bin: ", (~(value - 1)) & 0x3FFF,
            (~(value - 1)) & 0x3FFF, (~(value - 1)) & 0x3FFF);
      else
        printf ("dec: %d | oct: %o | hex: %X | bin: ", value & 0x1FFF,
                value & 0x1FFF, value & 0x1FFF);
    }

  else
    {
      printf ("dec: %d | oct: %o | hex: %X | bin: ", value, value, value);
    }

  for (int i = 15; i >= 0; i--)
    {
      printf ("%d", (value >> i) & 1);
    }
  mt_setfgcolor (DEFAULT);
}
