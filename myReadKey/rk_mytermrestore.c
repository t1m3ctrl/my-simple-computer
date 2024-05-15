#include <myReadKey.h>
#include <rk_structs.h>

int
rk_myTermRestore (void)
{
  FILE *file;

  if ((file = fopen ("termsettings", "rb")) == NULL)
    return -1;
  if (fread (&options, sizeof (options), 1, file) > 0)
    {
      if (tcsetattr (STDIN_FILENO, TCSAFLUSH, &options) != 0)
        return -1;
    }
  else
    {
      return -1;
    }

  return 0;
}