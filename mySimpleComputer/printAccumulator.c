#include <mySimpleComputer.h>
#include <myTerm.h>
#include <sc.h>

void
printAccumulator ()
{
  mt_setfgcolor (WHITE);
  mt_gotoXY (65, 2);

  int accumulator_value;
  sc_accumulatorGet (&accumulator_value);
  if ((accumulator_value >> 14) & 1)
    {
      if ((accumulator_value >> 13) & 1)
        printf ("sc: -%04d hex: -0x%04X", ~(accumulator_value - 1) & 0x1FFF,
                ~(accumulator_value - 1) & 0x1FFF);
      else
        printf ("sc: %04d hex: 0x%04X", accumulator_value & 0x1FFF,
                accumulator_value & 0x1FFF);
    }
  else
    {
      printf ("sc: %04d hex: 0x%04X", accumulator_value & 0x1FFF,
              accumulator_value & 0x1FFF);
    }
  // printf ("sc: %04d hex: 0x%04X", accumulator_value, accumulator_value);
  mt_setfgcolor (DEFAULT);
}