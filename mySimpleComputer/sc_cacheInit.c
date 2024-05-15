#include <mySimpleComputer.h>
#include <sc.h>

void
sc_initCache ()
{
  cache = (CacheLine *)malloc (CACHE_SIZE * sizeof (CacheLine));
  if (cache == NULL)
    {
      return;
    }

  for (int i = 0; i < CACHE_SIZE; ++i)
    {
      cache[i].address = -1;
      cache[i].lastAccessTime = 0;
      for (int j = 0; j < CACHE_LINE_SIZE; j++)
        {
          cache[i].data[j] = 0;
        }
    }
}