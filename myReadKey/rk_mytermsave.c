#include <rk.h>
#include <rk_structs.h>

int
rk_myTermSave ()
{
  if (tcgetattr (0, &termTemp))
    return -1;
  return 0;
}