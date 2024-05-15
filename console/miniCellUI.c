#include <console.h>
#include <myBigChars.h>
#include <myReadKey.h>
#include <mySimpleComputer.h>
#include <myTerm.h>
#include <rk_structs.h>

int
miniCellUI ()
{
  int value = memory[cell];
  printDecodedCommand (value);
  return 0;
}
