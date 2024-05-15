#include <console.h>

void
uiCommand1 ()
{
  mt_gotoXY (1, 28);
  mt_setbgcolor (BLUE);
  mt_setfgcolor (WHITE);
  mt_setbgcolor (DEFAULT);
}