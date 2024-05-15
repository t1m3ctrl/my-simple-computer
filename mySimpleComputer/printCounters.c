#include <console.h>
#include <mySimpleComputer.h>
#include <myTerm.h>
#include <sc.h>

void
printCounters ()
{
  mt_setfgcolor (WHITE);
  mt_gotoXY (66, 5);

  int icounter_value;
  int value;
  sc_regGet (IGNORING_TACT_PULSES, &value);
  sc_icounterGet (&icounter_value);
  printf ("T: %04d   IC: +%04X", ticks, icounter_value);
  mt_setfgcolor (DEFAULT);
}