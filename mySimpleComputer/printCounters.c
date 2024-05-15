#include <mySimpleComputer.h>
#include <myTerm.h>
#include <sc.h>

void
printCounters ()
{
  mt_setfgcolor (WHITE);
  mt_gotoXY (66, 5);

  int icounter_value;
  sc_icounterGet (&icounter_value);
  printf ("T: %02d", icounter_value);
  mt_setfgcolor (DEFAULT);
}