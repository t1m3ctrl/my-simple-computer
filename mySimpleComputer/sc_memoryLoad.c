#include <mySimpleComputer.h>
#include <sc.h>

int
sc_memoryLoad (char *filename)
{
  FILE *addressData = fopen (filename, "rb");
  if (addressData == NULL)
    {
      perror ("Error opening file");
      return -1;
    }

  if (fread (memory, sizeof (int), 128, addressData) != 128)
    {
      fprintf (stderr, "Error reading from file\n");
      fclose (addressData);
      return -1;
    }

  fclose (addressData);
  return 0;
}