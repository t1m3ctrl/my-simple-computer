#include "../include/mySimpleComputer.h"
#include <console.h>
#include <myBigChars.h>
#include <myReadKey.h>
#include <myTerm.h>
#include <rk_structs.h>

int
uiAdd (void)
{
  mt_setbgcolor (DEFAULT);

  mt_clrscr ();
  boxesUI ();
  textsUI ();
  memoryUI ();
  printFlags ();
  cellUI ();
  miniCellUI ();
  printAccumulator ();
  printCommand ();
  printCounters ();
  bigCharsUI ();
  printTerm (cell, 0, membuffer);
  // sc_commandDecode(cell, 0x1, 0);
  // printf("%X", command);
  if (flagUi)
    {
      uiCommand1 ();
    }
  cacheUI ();
  mt_gotoXY (1, 26);
  printf ("Input:\n");
  return 0;
}
