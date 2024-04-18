#include <stdio.h>

#include "../include/bc.h"
#include "../include/mt.h"
#include "../include/sc.h"

int big2[18 * 2];

void
printBigCell (void)
{
  int rows;
  int cols;
  if (mt_getscreensize (&rows, &cols) == -1)
    return;
  if (mt_gotoXY (4, (int) (cols * 2 / 4)) == -1)
    return;
  // bc_box (4 + 3, 63, 11, 44, WHITE, BLACK,
  //         "Редактируемая ячейка (увеличенно)", RED, WHITE);
  bc_box (4 + 3, 63, 12, 44, WHITE, BLACK,
          " Редактируемая ячейка (увеличенно) ", RED, WHITE);
  printf ("\n");
  int bg[2];
  int x = memory[command_counter];
  int sign = 0;
  int command = 0;
  int operand = 0;
  // printf("\n%d\n%d\n%d\n%d\n", x/(16*16*16), x/(16*16)%16,);
  sc_commandDecode (x, &sign, &command, &operand);
  if (sign == 1)
    {
      bg[0] = big2[0 + 16 * 2];
      bg[1] = big2[1 + 16 * 2];
    }
  else
    {
      bg[0] = big2[0 + 17 * 2];
      bg[1] = big2[1 + 17 * 2];
    }
  bc_printbigchar (bg, 4 + 5, 63 + 2, WHITE, BLACK);

  bg[0] = big2[0 + x / (16 * 16 * 16) * 2];
  bg[1] = big2[1 + x / (16 * 16 * 16) * 2];
  bc_printbigchar (bg, 4 + 5, 63 + 2 + 8, WHITE, BLACK);

  bg[0] = big2[0 + x / (16 * 16) % 16 * 2];
  bg[1] = big2[1 + x / (16 * 16) % 16 * 2];
  bc_printbigchar (bg, 4 + 5, 63 + 2 + 8 * 2, WHITE, BLACK);

  bg[0] = big2[0 + x / 16 % 16 * 2];
  bg[1] = big2[1 + x / 16 % 16 * 2];
  bc_printbigchar (bg, 4 + 5, 63 + 2 + 8 * 3, WHITE, BLACK);

  bg[0] = big2[0 + x % 16 * 2];
  bg[1] = big2[1 + x % 16 * 2];
  bc_printbigchar (bg, 4 + 5, 63 + 2 + 8 * 4, WHITE, BLACK);

  if (mt_setbgcolor (BLACK) == -1)
    return;
  if (mt_setfgcolor (BLUE) == -1)
    return;
  if (mt_gotoXY (4 + 13, 63 + 2) == -1)
    return;
  printf (" Номер редактируемой ячейки: %d", command_counter);
}

void
printCell (int address, enum colors fg, enum colors bg)
{
  mt_setdefaultcolor ();
  if (mt_setbgcolor (bg) == -1)
    return;
  if (mt_setfgcolor (fg) == -1)
    return;
  if (mt_gotoXY ((int) (address / 10 + 2), (int) (address % 10 * 6) + 3) == -1)
    return;
  int x;
  sc_memoryGet (address, &x);
  if ((x >> 14) == 1)
    printf ("+%x", x);
  else
    printf ("-%x", x);
}

void
printFlags (void)
{
  int rows;
  int cols;
  if (mt_getscreensize (&rows, &cols) == -1)
    return;
  bc_box (1, 85, 3, 22, WHITE, BLACK, " Регистр флагов ",
          RED, BLACK);
  if (mt_gotoXY (2, 85 + 6) == -1)
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
  bc_box (4, 85, 3, 22, WHITE, BLACK, " Команда ", RED,
          BLACK);
  if (mt_gotoXY (5, 85 + 6) == -1)
    return;
  int x = value;
  int sign = 0;
  int command = 0;
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
      printf ("Команда!");
    }
}

void
printAccumulator (void)
{
  int rows;
  int cols;
  if (mt_getscreensize (&rows, &cols) == -1)
    return;
  bc_box (1, 63, 3, 22, WHITE, BLACK, " Аккумулятор ", RED,
          BLACK);
  if (mt_gotoXY (2, 63 + 1) == -1)
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
  bc_box (4, 63, 3, 22, WHITE, BLACK, " Счётчик команд ", RED,
          BLACK);
  if (mt_gotoXY (5, 63 + 1) == -1)
    return;
  int x;
  sc_icounterGet (&x);
  int y;
  sc_memoryGet (x, &y);
  printf ("IC:%x\n", x);
}

void
printEditableCell (void)
{
  int rows;
  int cols;
  if (mt_getscreensize (&rows, &cols) == -1)
    return;
  bc_box (16, 1, 3, 62, WHITE, BLACK, " Редактируемая ячейка (формат) ", RED, WHITE);
  if (mt_gotoXY (17, 2) == -1)
    return;
  int x = memory[command_counter];
  int sign = 0;
  int command = 0;
  int operand = 0;
  sc_commandDecode (x, &sign, &command, &operand);

  printf ("dec: %5d | oct: %5o | hex: %5x | bin: ", x, x, x);
  int bits = sizeof (x) * 4;

  for (int i = bits - 1; i >= 0; i--)
    {
      if ((x >> i) & 1)
        {
          printf ("1");
        }
      else
        {
          printf ("0");
        }
    }
}

void
printTerm (int address, int input)
{
  int rows;
  int cols;
  if (mt_getscreensize (&rows, &cols) == -1)
    return;
  bc_box (19, 63, 8, 11, WHITE,
          BLACK, "IN--OUT", GREEN, WHITE);
  mt_gotoXY (19 + 1, 63 + 1);
  mt_delline ();
  mt_setdefaultcolor ();
  printf ("\n");

  if (mt_gotoXY (19 + 1 + 4, 63 + 1) == -1)
    return;
  if (input == OUT)
    {
      int x;
      sc_memoryGet (address, &x);
      if ((x >> 14) == 1)
        printf ("    +%4x", x);
      else
        printf ("    -%4x", x);
    }
  else
    {
      printf ("%2d", address);
      printf (">        ");
    }
  printf ("\n");
}

int
main (int argc, char *argv[])
{

  int fd1;

  if (argc == 2)
    fd1 = open (argv[1], O_RDONLY);
  else
    fd1 = open ("font.bin", O_RDONLY);

  if (fd1 == -1)
    {
      fputs ("Не могу открыть файл :(", stdout);
      return 0;
    }

  int count = 0;

  bc_bigcharread (fd1, big2, 18 * 2, &count);

  close (fd1);

  if (count < 18 * 2)
    {
      printf ("чтение с потерями\ncount=%d", count);
      return 0;
    }
  printf ("\ncount=%d\n", count);

  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();
  sc_memoryInit ();

  sc_accumulatorSet (32767);

  int fd = STDOUT_FILENO;
  printf ("проверка потока вывода\n");
  if (!isatty (fd))
    {
      printf ("поток вывода не соответсвует терминалу");
      return -1;
    }
  printf ("УСПЕХ\n");

  int row = 0;
  int col = 0;
  printf ("row = %d, col = %d", row, col);
  if (mt_getscreensize (&row, &col) == -1)
    return -1;
  printf ("row = %d, col = %d", row, col);
  // getchar ();
  printf ("проверка терминала\n");
  if (row < 30 || col < 106)
    {
      printf ("терминал мал");
      return -1;
    }
  printf ("УСПЕХ\n");

  printf ("очистка терминала\n");
  mt_clrscr ();

  sc_memorySet (0, 32767);
  sc_memorySet (1, 32766);
  bc_box (1, 1, 15, 62, WHITE, BLACK, " Оперативная память ", RED, BLACK);
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
  int value = 0;
  sc_commandEncode (sign, command, operand, &value);
  // mt_delline();

  mt_setdefaultcolor ();

  sc_accumulatorSet (32767);
  printAccumulator ();
  printf ("\n");
  printf ("\n");
  // printf("\nOK0\n");
  printFlags ();
  printf ("\n");
  printCounters ();
  printf ("\n");
  printDecodedCommand (value);
  printf ("\n");

  sc_icounterSet (0);

  printBigCell ();
  printf ("\n");

  printEditableCell ();
  printf ("\n");

  sc_memorySet (6, 32766);

  for (size_t i = 0; i < 6; i++)
    {
      // bc_box((int)(row * 2 / 3)-1, (int)(col * 2 / 4)-1, 8, 11, WHITE,
      // BLACK, "IN--OUT", GREEN, WHITE);
      printf ("\n");
      mt_setdefaultcolor ();
      printTerm (i, OUT);
      sleep (1);
      printf ("\n");
    }
  mt_gotoXY (40, 0);

  return 0;
}