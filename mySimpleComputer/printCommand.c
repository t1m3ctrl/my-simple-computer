#include <mySimpleComputer.h>
#include <myTerm.h>
#include <sc.h>

void
printCommand ()
{
  mt_setfgcolor (WHITE);
  int address, command, operand;
  mt_gotoXY (93, 5);
  sc_icounterGet (&address);
  // >> 8
  sc_commandDecode (memory[address], &command, &operand);
  if (address >= 0 && address < 128)
    {
      if (!sc_commandValidate (command))
        {
          printf ("! ");
          printf ("+FF: FF");
        }
      else
        {
          printf ("%03d: %d", address, command);
        }
    }
  else
    {
      printf ("Неверный адрес команды");
    }
  mt_setfgcolor (DEFAULT);
}