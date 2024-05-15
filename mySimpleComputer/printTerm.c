#include <mySimpleComputer.h>
#include <myTerm.h>
#include <sc.h>

void
printTerm (int address, int input, memBuffer1 buffer[])
{
  static int currentIndex = 0;

  if (input == 1)
    {
      buffer[currentIndex].addr = address;
      buffer[currentIndex].buf = memory[address];
      currentIndex = (currentIndex + 1) % 4;
    }

  if (input == 0)
    {
      for (int i = 0; i < 4; i++)
        {
          mt_gotoXY (71, 21 + i);
          printf ("%d ", buffer[i].addr);
          printf ("> ");
          printf ("+%04X\n", buffer[i].buf);
        }
    }
}