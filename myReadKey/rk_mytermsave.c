#include <myReadKey.h>
#include <rk_structs.h>

int
rk_myTermSave (void)
{
  FILE *file;

  if (tcgetattr (STDIN_FILENO, &options) != 0)
    return -1;
  if ((file = fopen ("termsettings", "wb")) == NULL)
    return -1;

  fwrite (&options, sizeof (options), 1, file);
  fclose (file);

  return 0;
}