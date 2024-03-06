#include "mt.h"

int
mt_setbgcolor (enum colors color)
{
  char seq[16];
  int color_num;
  switch (color)
    {
    case BLACK:
      color_num = 0;
      break;
    case RED:
      color_num = 1;
      break;
    case GREEN:
      color_num = 2;
      break;
    case YELLOW:
      color_num = 3;
      break;
    case BLUE:
      color_num = 4;
      break;
    case MAGENTA:
      color_num = 5;
      break;
    case CYAN:
      color_num = 6;
      break;
    case WHITE:
      color_num = 7;
      break;
    default:
      return -1;
    }
  int len = snprintf (seq, sizeof (seq), "\033[4%dm", color_num);
  if (write (STDOUT_FILENO, seq, len) == -1)
    return -1;

  return 0;
}