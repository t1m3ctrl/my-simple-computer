#include <myReadKey.h>
#include <rk_structs.h>

int
rk_readValue (int *value, int timeout)
{
  char input[100];
  clock_t start_time = clock ();
  bool input_complete = false;

  while (!input_complete
         && ((clock () - start_time) / CLOCKS_PER_SEC) < timeout)
    {
      printf ("Введите целое число: ");
      if (fgets (input, sizeof (input), stdin) != NULL)
        {
          input[strcspn (input, "\n")] = 0;
          if (sscanf (input, "%d", value) == 1)
            {
              input_complete = true;
            }
          else
            {
              printf ("Ошибка: введите корректное целое число\n");
            }
        }
      else
        {
          printf ("Ошибка при чтении ввода\n");
          return -1;
        }
    }

  if (input_complete)
    {
      return 0;
    }
  else
    {
      return 1;
    }
}