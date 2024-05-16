#include <console.h>
#include <myBigChars.h>
#include <myReadKey.h>
#include <mySimpleComputer.h>
#include <myTerm.h>
#include <rk_structs.h>

int
textsUI (void)
{
  mt_gotoXY (20, 1);
  mt_setfgcolor (RED);
  printf (" Оперативная память ");
  mt_gotoXY (69, 1);
  printf (" Аккумулятор ");
  mt_gotoXY (67, 4);
  printf (" Счётчик команд ");
  mt_gotoXY (98, 4);
  printf (" Команда ");
  mt_gotoXY (94, 1);
  printf (" Регистр флагов ");
  mt_gotoXY (71, 7);
  mt_setbgcolor (WHITE);
  printf (" Редактируемая ячейка (увеличено) ");
  mt_gotoXY (17, 16);
  printf (" Редактируемая ячейка (формат) ");

  mt_setfgcolor (GREEN);
  mt_setbgcolor (WHITE);
  mt_gotoXY (23, 19);
  printf (" Кеш процессора ");

  mt_gotoXY (72, 19);
  printf (" IN--OUT ");

  mt_gotoXY (95, 19);

  printf (" Клавиши ");
  mt_setfgcolor (WHITE);
  mt_setbgcolor (DEFAULT);

  mt_gotoXY (85, 20);
  printf ("l - Load");
  mt_gotoXY (95, 20);
  printf ("s - Save");
  mt_gotoXY (105, 20);
  printf ("i - Reset");
  mt_gotoXY (85, 21);
  printf ("r  - Run");
  mt_gotoXY (95, 21);
  printf ("t  - Step");
  mt_gotoXY (85, 22);
  printf ("ESC - Выход");
  mt_gotoXY (85, 23);
  printf ("F5 - Аккумулятор");
  mt_gotoXY (85, 24);
  printf ("F6 - Счетчик команд");
  mt_setfgcolor (DEFAULT);
  return 0;
}
