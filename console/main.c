#include <fcntl.h>
#include <myBigChars.h>
#include <myReadKey.h>
#include <mySimpleComputer.h>
#include <myTerm.h>
#include <unistd.h>

int bc[][2] = {
  { 0xE7E7FFFF, 0xFFFFE7E7 }, // 0  |
  { 0x1CDC7C3C, 0xFFFF1C1C }, // 1  |
  { 0xFF07FFFF, 0xFFFFE0FF }, // 2  |
  { 0xFF07FFFF, 0xFFFF07FF }, // 3  |
  { 0xFFE7E7E7, 0x070707FF }, // 4  |
  { 0xFFE0FFFF, 0xFFFF07FF }, // 5  |
  { 0xFFE0FFFF, 0xFFFFE7FF }, // 6  |
  { 0x1C0EFFFE, 0x3838FE38 }, // 7  |
  { 0x7EE7FF7E, 0x7EFFE77E }, // 8  |
  { 0xFFE7FFFF, 0xFFFF07FF }, // 9  |
  { 0xFFE7FF7E, 0xE7E7E7FF }, // A  |
  { 0xFEE7FFFE, 0xFEFFE7FE }, // B  |
  { 0xE0E7FF7E, 0x7EFFE7E0 }, // C  |
  { 0xE7E7FFF8, 0xF8FFE7E7 }, // D  |
  { 0xFFE0FFFF, 0xFFFFE0FF }, // E  |
  { 0xFFE0FFFF, 0xE0E0E0FF }, // F  |
  { 0x7E180000, 0x00000018 }, // +  |
  { 0x7E000000, 0x00000000 }, // -  |
  { 0x1CDC7C3C, 0xFFFF1C1C }  // 1  |
};

int drawingBoxes (void);
int drawingTexts (void);
int drawingMemory (void);
int drawingFlags (void);
int drawingBigChars (void);
int uiAdd (void);

int cell = 0;
memBuffer1 membuffer[4] = { 0 };
int ui_messageOutput (char *str, enum colors color);

int
main (void)
{
  int value;

  if (!isatty (fileno (stdout)))
    {
      fprintf (stderr, "Launch");
      return 1;
    }

  int col = 0, row = 0;
  mt_getscreensize (&col, &row);
  if (col < 30 || row < 30)
    {
      fprintf (stderr, "The terminal screen is too small");
      return 1;
    }
  mt_setbgcolor (DEFAULT);

  rk_myTermSave ();
  sc_memoryInit ();
  sc_regInit ();
  sc_icounterInit ();
  sc_accumulatorInit ();

  sc_memorySet (0, 0x3434);
  sc_memorySet (11, 0x1234);
  sc_memorySet (22, 0xABCD);
  sc_memorySet (123, 0x1F7F);
  sc_regSet (IGNORING_TACT_PULSES, 3);

  count = 0;
  int buffer;
  enum keys key;
  char name[20];
  char filename[128];

  int x, y;
  do
    {
      uiAdd ();
      rk_readKey (&key);

      switch (key)
        {
        case UP:
          if (cell < 128)
            {
              if (cell <= 9)
                {
                  cell = 120 + cell;
                }
              else
                {
                  cell -= 10;
                }
              if (cell == 128 || cell == 129)
                {
                  cell -= 10;
                }
            }
          break;
        case DOWN:
          if (cell < 128)
            {
              if (cell >= 120)
                {
                  cell = cell - 120;
                }
              else
                {
                  cell += 10;
                }
              if (cell == 128 || cell == 129)
                {
                  cell = cell - 120;
                }
            }
          break;
        case LEFT:
          if (cell < 128)
            {
              if (!(cell % 10))
                {
                  cell += 9;
                }
              else
                {
                  cell--;
                }
            }

          if (cell == 128 || cell == 129)
            {
              cell -= 2;
            }
          break;
        case RIGHT:
          if (cell < 128)
            {
              if (!((cell + 1) % 10))
                {
                  cell -= 9;
                }
              else
                {
                  cell++;
                }
            }

          if (cell == 128 || cell == 129)
            {
              cell -= 8;
            }
          break;
        case SAVE:
          printf ("Input file name for save: ");
          scanf ("%s", filename);
          sc_memorySave (filename);
          break;
        case LOAD:
          printf ("Input file name for load: ");
          scanf ("%s", filename);
          sc_memoryLoad (filename);
          break;
        case RUN:
          break;
        case STEP:
          break;
        case RESET:
          accumulator = 0;
          sc_accumulatorSet (accumulator);
          break;
        case ENTER:
          // x = cell % 10;
          // y = cell / 10;
          // mt_gotoXY ((x + 1) * 6 - 4, y + 2);
          printf ("Set the value of the cell under the number "
                  "\033[38;5;%dm0x%X\033[0m\n",
                  SOFT_GREEN, cell);
          printf ("Enter value in \033[38;5;%dmhex\033[0m > ", PEACH);
          scanf ("%X", &buffer);
          sc_memorySet (cell, buffer);
          printTerm (cell, 1, membuffer);
          break;
        case F5:
          printf ("Set accumulator: ");
          scanf ("%d", &accumulator);
          if (accumulator > 32767 || accumulator < -32767)
            {
              accumulator = 0;
              sc_regSet (OUT_OF_MEMORY_BOUNDS, 1);
            }
          break;
        case F6:
          printf ("Set instruction counter: ");
          scanf ("%d", &count);
          if (count < 0 || count > 128)
            {
              sc_regSet (OUT_OF_MEMORY_BOUNDS, 1);
              count = cell;
            }
          cell = count;
          break;
        default:
          break;
        }
    }
  while (key != EXIT);
  printf ("EXIT!\n");
  return 0;
}

int
drawingBoxes ()
{
  if (bc_box (1, 1, 61, 15))
    return -1;
  if (bc_box (62, 1, 27, 3))
    return -1;
  if (bc_box (62, 4, 27, 3))
    return -1;
  if (bc_box (89, 4, 27, 3))
    return -1;
  if (bc_box (89, 1, 27, 3))
    return -1;
  if (bc_box (62, 7, 54, 13))
    return -1;
  if (bc_box (84, 20, 32, 7))
    return -1;
  if (bc_box (1, 16, 61, 4))
    return -1;
  if (bc_box (1, 20, 68, 7))
    return -1;
  if (bc_box (69, 20, 15, 7))
    return -1;

  return 0;
}

int
drawingTexts ()
{
  mt_gotoXY (21, 1);
  mt_setfgcolor (RED);
  printf (" Оперативная память ");
  mt_gotoXY (69, 1);
  printf (" Аккумулятор ");
  mt_gotoXY (67, 4);
  printf (" Счетчик команд ");
  mt_gotoXY (98, 4);
  printf (" Команда ");
  mt_gotoXY (95, 1);
  printf (" Регистр флагов ");
  mt_gotoXY (76, 7);
  mt_setbgcolor (WHITE);
  printf (" Редактируемая ячейка (увеличенно) ");
  mt_gotoXY (20, 16);
  printf (" Редактируемая ячейка (формат) ");

  mt_setbgcolor (WHITE);
  mt_setfgcolor (GREEN);

  mt_gotoXY (25, 20);
  printf (" Кэш процессора ");

  mt_gotoXY (73, 20);
  printf (" IN--OUT ");

  mt_gotoXY (95, 20);
  printf (" Клавиши ");

  mt_setfgcolor (WHITE);
  mt_setbgcolor (DEFAULT);
  mt_gotoXY (85, 21);
  printf ("l - load");
  mt_gotoXY (95, 21);
  printf ("s - save");
  mt_gotoXY (105, 21);
  printf ("i - reset");
  mt_gotoXY (85, 22);
  printf ("r  - run");
  mt_gotoXY (95, 22);
  printf ("t  - step");
  mt_gotoXY (85, 23);
  printf ("ESC - выход");
  mt_gotoXY (85, 24);
  printf ("F5 - accumulator");
  mt_gotoXY (85, 25);
  printf ("F6 - instruction counter");
  mt_setfgcolor (DEFAULT);
  return 0;
}

int
drawingCell ()
{
  mt_gotoXY (63, 18);
  mt_setfgcolor (BLUE);
  mt_setbgcolor (DEFAULT);
  printf (" Номер редактируемой ячейки: %d ", cell);
  mt_setfgcolor (DEFAULT);
  return 0;
}

int
drawingMemory ()
{
  for (int i = 0; i < 13; ++i)
    {
      for (int j = 0; j < 10; ++j)
        {
          int cellIndex = i * 10 + j;

          if (cellIndex < 128)
            {

              mt_gotoXY (2 + (5 * j + j), 2 + i);
              int tmp;
              sc_memoryGet (cellIndex, &tmp);

              if (cellIndex == cell)
                {
                  mt_setbgcolor (WHITE);
                }
              else
                {
                  mt_setbgcolor (BLACK);
                }
              if (cellIndex == cell)
                {

                  mt_setfgcolor (BLACK);
                }
              else
                {
                  mt_setfgcolor (WHITE);
                }

              if ((tmp >> 14) & 1)
                {
                  printf ("+%04X", tmp & (~(1 << 14)));
                }
              else
                {
                  printf ("+%04X", tmp);
                }

              mt_setdefaultcolors ();
            }
        }
    }
  return 0;
}

int
drawingBigChars ()
{
  int tmp = memory[cell];
  if (!((tmp >> 14) & 1))
    bc_printbigchar (bc[16], 63, 9, WHITE, DEFAULT);

  for (int i = 0; i < 4; ++i)
    {
      int ch = (tmp & (0b1111 << (4 * (3 - i)))) >> (4 * (3 - i));

      mt_setbgcolor (DEFAULT);
      bc_printbigchar (bc[ch], 62 + 8 * (i + 1) + 2 * (i + 1), 9, WHITE,
                       DEFAULT);
    }

  return 0;
}

int
drawingMiniCell ()
{
  int value;
  sc_memoryGet (cell, &value);
  printDecodedCommand (value);
  return 0;
}

int
uiAdd ()
{
  mt_setbgcolor (DEFAULT);

  mt_clrscr ();
  drawingBoxes ();
  drawingTexts ();
  drawingMemory ();
  printFlags ();
  drawingCell ();
  drawingMiniCell ();
  printAccumulator ();
  printCommand ();
  printCounters ();
  drawingBigChars ();
  printTerm (cell, 0, membuffer);
  mt_gotoXY (1, 27);
  printf ("Input:\n");
  return 0;
}

int
ui_messageOutput (char *str, enum colors color)
{
  printf ("\033[38;5;%dm%s\033[0m", color, str);
  return 0;
}