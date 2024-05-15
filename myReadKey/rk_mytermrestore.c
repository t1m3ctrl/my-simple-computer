#include <myReadKey.h>
#include <rk_structs.h>

int
rk_myTermRestore ()
{
  return tcsetattr (0, TCSANOW, &termTemp);
}