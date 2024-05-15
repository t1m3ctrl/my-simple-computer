#include <mySimpleComputer.h>
#include <sc.h>

int
sc_memoryInit (void)
{
  if (memory == NULL)
    {
      memory = (int *)malloc (128 * sizeof (int));
    }
  for (int i = 0; i < 128; i++)
    memory[i] = 0;
  return 0;
}
