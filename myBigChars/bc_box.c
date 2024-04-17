#include "../include/bc.h"

int
bc_box (int x1, int y1, int x2, int y2, enum colors box_fg, enum colors box_bg, char *header, enum colors header_fg, enum colors header_bg)
{
  int fd = STDOUT_FILENO;

  char cmd1[] = "\033(0";
  char cmd2[] = "\033(B";

  int result = write (fd, cmd1, sizeof (cmd1) - 1);
  printf ("\n");

  if (result != -1)
    {
      mt_setbgcolor (box_bg);
      mt_setfgcolor (box_fg);
      mt_gotoXY (x1, y1);

      printf ("l");
      for (size_t i = 0; (int) i < y2 - 2; i++)
        printf ("q");
      printf ("k");
      printf ("\n");
      for (size_t i = 0; (int) i < x2 - 2; i++)
        {
          mt_gotoXY (x1 + i + 1, y1);
          printf ("x");
          printf ("\n");
          // printf("\n");
          // for (size_t k = 0; (int)k < y2-2; k++)
          //     printf(" ");
          mt_gotoXY (x1 + i + 1, y1 + y2 - 1);
          printf ("x");
          printf ("\n");
        }
      printf ("\n");
      mt_gotoXY (x1 + x2 - 1, y1);
      printf ("m");
      for (size_t i = 0; (int) i < y2 - 2; i++)
        printf ("q");
      printf ("j");
      printf ("\n");

      result = write (fd, cmd2, sizeof (cmd2) - 1);
      printf ("\n");
    }
  mt_setdefaultcolor ();
  printf ("\n");
  if (header != NULL && bc_strlen (header) != 0)
    {
      mt_setbgcolor (header_bg);
      mt_setfgcolor (header_fg);
      mt_gotoXY (x1, y1 + y2 / 2 - bc_strlen (header) / 2);
      printf ("%s", header);
      printf ("\n");
    }
  else
    return -1;

  mt_setdefaultcolor ();
  printf ("\n");
  // mt_clrscr();
  // printf("\nOK\n");
  if (result != -1)
    return 0;
  else
    return -1;
}