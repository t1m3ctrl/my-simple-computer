#include <console.h>

int
font (char *filename)
{
  FILE *file;
  file = fopen (filename, "wb");
  if (file == NULL)
    {
      printf ("Open error.\n");
      return -1;
    }
  // for (int i = 0; i < sizeof(int) / sizeof(bc[0]); i++) {
  //     fwrite(&bc[i], sizeof(int), 2, file);
  // }
  if (fwrite (bc, sizeof (int), 19, file) != 19)
    {
      fprintf (stderr, "Error writing to file\n");
      fclose (file);
      return -1;
    }
  fclose (file);
  return 0;
}