#include "mt.h"

int
mt_getscreensize (int *rows, int *cols)
{
  char *columns_str = getenv ("COLUMNS");
  char *rows_str = getenv ("LINES");

  if (columns_str == NULL || rows_str == NULL)
    {
      return -1;
    }

  *cols = atoi (columns_str);
  *rows = atoi (rows_str);

  return 0;
}