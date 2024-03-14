#include "../include/mt.h"

int
mt_getscreensize (int *rows, int *cols)
{
  struct winsize ws;
  if (!ioctl (STDOUT_FILENO, TIOCGWINSZ, &ws))
    {
      *rows = ws.ws_row;
      *cols = ws.ws_col;
      return 0;
    }
  else
    return -1;
}