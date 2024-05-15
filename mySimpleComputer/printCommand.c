#include <mySimpleComputer.h>
#include <myTerm.h>
#include <sc.h>

void
printCommand ()
{
  mt_setfgcolor (WHITE);
  int address, value;
  mt_gotoXY (93, 5);
  sc_icounterGet (&address);
  if (address >= 0 && address < 128)
    {
      if (!sc_commandValidate (memory[address]))
        {
          printf ("! ");
          printf ("+FF: FF");
        }
      else
        {
          sc_memoryGet (address, &value);
          printf ("%02d: %d", address, memory[address]);
        }
    }
  else
    {
      printf ("Неверный адрес команды");
    }
  mt_setfgcolor (DEFAULT);
}