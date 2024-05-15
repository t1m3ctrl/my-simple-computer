#include <mySimpleComputer.h>
#include <myTerm.h>
#include <sc.h>

void
printFlags ()
{
  mt_setfgcolor (WHITE);
  mt_gotoXY (95, 2);
  int value;
  sc_regGet (OUT_OF_MEMORY_BOUNDS, &value);
  if (value)
    {
      printf ("P ");
    }
  else
    {
      printf ("_ ");
    }
  sc_regGet (WRONG_FLAG, &value);
  if (value)
    {
      printf ("M ");
    }
  else
    {
      printf ("_ ");
    }
  sc_regGet (IGNORING_TACT_PULSES, &value);
  if (value)
    {
      printf ("T ");
    }
  else
    {
      printf ("_ ");
    }
  sc_regGet (INCORRECT_COMMAND_RECEIVED, &value);
  if (value)
    {
      printf ("E ");
    }
  else
    {
      printf ("_ ");
    }
  sc_regGet (DIVISION_ERR_BY_ZERO, &value);
  if (value)
    {
      printf ("0 ");
    }
  else
    {
      printf ("_ ");
    }
  mt_setfgcolor (DEFAULT);
}