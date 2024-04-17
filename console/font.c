#include "../include/bc.h"

#define DEFAULT_FONT_FILE "font.bin"

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
      fputs ("Не могу открыть файл :(\n", stdout);
      return 0;
    }

  int big[2 * 18];

  bc_bigcharwrite (fd1, big, 18 * 2);

  printf ("all completed\n");

  close (fd1);
  return 0;
}