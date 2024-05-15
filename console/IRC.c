#include <console.h>
#include <myBigChars.h>
#include <myReadKey.h>
#include <mySimpleComputer.h>
#include <myTerm.h>
#include <rk_structs.h>
#include <sc.h>

void
IRC (int signum)
{
  switch (signum)
    {
    case SIGALRM:
      if (ticks < 9999)
        {
          ticks++;
        }
      else
        {
          ticks = 0;
        }
      cell = count;
      uiAdd ();
      if (CU ())
        {
          sc_regSet (IGNORING_TACT_PULSES, 1);
          uiAdd ();
          alarm (0);
        }
      else
        {

          alarm (1);
        }

      rk_myTermRegime (0, 1, 1, 0, 0);
      break;

    case SIGUSR1:
      alarm (0);
      ticks = 0;
      count = 0;
      rk_myTermSave ();
      sc_icounterInit ();
      sc_memoryInit ();
      sc_initCache ();
      updateStatic = true;
      // sc_accumulatorInit ();
      accumulator &= (1 << 14);
      sc_regInit ();
      sc_regSet (IGNORING_TACT_PULSES, 1);
      break;
    default:
      break;
    }
}
