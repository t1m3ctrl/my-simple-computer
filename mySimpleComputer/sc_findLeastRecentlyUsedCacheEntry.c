#include <mySimpleComputer.h>
#include <sc.h>

int
sc_findLeastRecentlyUsedCacheEntry ()
{
  int leastRecentlyUsedIndex = 0;
  time_t leastRecentTime = cache[0].lastAccessTime;
  for (int i = 1; i < CACHE_SIZE; ++i)
    {
      if (cache[i].lastAccessTime < leastRecentTime)
        {
          leastRecentTime = cache[i].lastAccessTime;
          leastRecentlyUsedIndex = i;
        }
    }
  return leastRecentlyUsedIndex;
}
