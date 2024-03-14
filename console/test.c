#include <stdio.h>

#include "../include/mt.h"
#include "../include/sc.h"

void
printCell (int address, enum colors fg, enum colors bg)
{
  if (mt_setbgcolor (bg) == -1)
    return;
  if (mt_setfgcolor (fg) == -1)
    return;
  if (mt_gotoXY ((int)(address / 10 + 1), (int)(address % 10 * 6)) == -1)
    return;
  int x;
  sc_memoryGet (address, &x);
  if ((x >> 14) == 1)
    printf (" +%x ", x);
  else
    printf (" -%x ", x);
  mt_setdefaultcolor ();
}

void
printFlags (void)
{
  int rows;
  int cols;
  if (mt_getscreensize (&rows, &cols) == -1)
    return;
  if (mt_gotoXY (0, (int)(cols * 3 / 4)) == -1)
    return;
  int x;
  sc_regGet (FLAG_OVERFLOW, &x);
  if (x)
    printf ("P ");
  else
    printf ("_ ");

  sc_regGet (FLAG_ZERO, &x);
  if (x)
    printf ("0 ");
  else
    printf ("_ ");

  sc_regGet (FLAG_OUT_OF_MEMORY, &x);
  if (x)
    printf ("M ");
  else
    printf ("_ ");

  sc_regGet (FLAG_CLOCKING, &x);
  if (x)
    printf ("T ");
  else
    printf ("_ ");

  sc_regGet (FLAG_INVALID_COMMAND, &x);
  if (x)
    printf ("E");
  else
    printf ("_");
}

void
printDecodedCommand (int value)
{
  int rows;
  int cols;
  if (mt_getscreensize (&rows, &cols) == -1)
    return;
  if (mt_gotoXY (3, (int)(cols * 3 / 4)) == -1)
    return;
  int x = value;
  int sign = 0;
  int command = 21;
  int operand = 0;
  if (sc_commandDecode (x, &sign, &command, &operand) == 0)
    {
      if (sign != 0)
        printf ("+ %2d : %2d\n", command, operand);
      else
        printf ("- %2d : %2d\n", command, operand);
    }
  else
    {
      printf ("Команда");
      if (mt_gotoXY (5, (int)(cols * 3 / 4)) == -1)
        return;
      printf ("!");
    }
}

void
printAccumulator (void)
{
  int rows;
  int cols;
  if (mt_getscreensize (&rows, &cols) == -1)
    return;

  if (mt_gotoXY (0, (int)(cols / 4 * 2)) == -1)
    return;
  int x;
  sc_accumulatorGet (&x);
  if (((x >> (15 - 1)) & 0x1) == 1)
    printf ("sc: +%d hex: %x", x, x);
  else
    printf ("sc: -%d hex: %x", x, x);
}

void
printCounters (void)
{
  int rows;
  int cols;
  if (mt_getscreensize (&rows, &cols) == -1)
    return;
  if (mt_gotoXY (3, (int)(cols * 2 / 4)) == -1)
    return;
  int x;
  sc_icounterGet (&x);
  int y;
  sc_memoryGet (x, &y);
  printf ("IC:%x\n", x);
}

void
printTerm (int address, int input)
{
  int rows;
  int cols;
  if (mt_getscreensize (&rows, &cols) == -1)
    return;
  mt_gotoXY ((int)(rows * 2 / 3), (int)(cols * 2 / 4));
  getchar ();
  mt_delline ();
  if (mt_gotoXY ((int)(rows * 2 / 3) + 4, (int)(cols * 2 / 4)) == -1)
    return;
  if (input == 0)
    {
      int x;
      sc_memoryGet (address, &x);
      if ((x >> 14) == 1)
        printf ("+%4x", x);
      else
        printf ("-%4x", x);
    }
  else
    {
      printf ("%2d", address);
      printf ("> ");
    }
}

int
main ()
{
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();
  sc_memoryInit ();

  sc_accumulatorSet (32767);

  int fd = STDOUT_FILENO;
  printf ("проверка потока вывода..\n");
  if (!isatty (fd))
    {
      printf ("поток вывода не соответсвует терминалу!");
      return -1;
    }
  getchar ();

  int row = 0;
  int col = 0;
  printf ("row = %d, col = %d", row, col);
  if (mt_getscreensize (&row, &col) == -1)
    return -1;
  printf ("row = %d, col = %d", row, col);
  printf ("\nпроверка терминала..\n");

  if (row < 20 || col < 100)
    {
      printf ("терминал мал!");
      return -1;
    }

  printf ("очистка терминала\n");
  getchar ();

  mt_clrscr ();

  sc_memorySet (0, 32767);
  sc_memorySet (1, 32767);
  sc_memorySet (34, 23);
  printCell (0, BLACK, WHITE);
  printf ("\n");
  for (size_t i = 1; i < MEMORY_SIZE; i++)
    {
      printCell (i, WHITE, BLACK);
      printf ("\n");
    }

  int sign = 0;
  int command = 21;
  int operand = 100;
  int value = 76;
  sc_commandEncode (sign, command, operand, &value);

  sc_accumulatorSet (32767);
  printAccumulator ();
  printf ("\n");

  sc_regInit ();
  sc_regSet (FLAG_ZERO, 1);
  sc_regSet (FLAG_INVALID_COMMAND, 1);
  printFlags ();
  printf ("\n");
  printCounters ();
  printf ("\n");
  printDecodedCommand (value);
  printf ("\n");

  sc_memorySet (6, 32766);

  for (size_t i = 0; i < 7; i++)
    {
      printTerm (i, 0);
      printf ("\n");
    }
  mt_gotoXY (40, 0);
}