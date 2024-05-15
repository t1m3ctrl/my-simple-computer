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
      currentIndex = (currentIndex + 1) % 5;
      for (int i = 0; i < 5; i++)
        {

          mt_gotoXY (72, 21 + i);
          printf ("%d ", buffer[i].addr);
          printf ("< ");
          if ((buffer[i].buf >> 14) & 1)
            {
              if ((buffer[i].buf >> 13) & 1)
                printf ("-%04X", buffer[i].buf - 1);
              else
                printf (" %04X", buffer[i].buf & 0x1FFF);
            }
          else
            {
              printf ("+%04X", buffer[i].buf);
            }
        }
    }
  if (input == 0)
    {
      for (int i = 0; i < 5; i++)
        {
          mt_gotoXY (72, 21 + i);
          printf ("%d ", buffer[i].addr);
          printf ("> ");
          if ((buffer[i].buf >> 14) & 1)
            {
              if ((buffer[i].buf >> 13) & 1)
                printf ("-%04X", ~(buffer[i].buf - 1) & 0x1FFF);
              else
                printf (" %04X", buffer[i].buf & 0x1FFF);
            }
          else
            {
              printf ("+%04X", buffer[i].buf);
            }
        }
    }
}