#include <console.h>
#include <myBigChars.h>
#include <myReadKey.h>
#include <mySimpleComputer.h>
#include <myTerm.h>
#include <rk_structs.h>

int
boxesUI (void)
{
  if (bc_box (1, 1, 61, 15)) // memory
    return -1;
  if (bc_box (62, 1, 27, 3)) // accumulator
    return -1;
  if (bc_box (62, 4, 27, 3)) // counter
    return -1;
  if (bc_box (89, 4, 27, 3)) // operation
    return -1;
  if (bc_box (89, 1, 27, 3)) // flags
    return -1;
  if (bc_box (62, 7, 54, 12)) // bigChars
    return -1;
  if (bc_box (84, 19, 32, 7)) // keys
    return -1;
  if (bc_box (1, 16, 61, 3)) //  bigChar mini
    return -1;
  if (bc_box (1, 19, 69, 7)) //  cache
    return -1;
  if (bc_box (70, 19, 14, 7)) //  In-Out
    return -1;

  return 0;
}