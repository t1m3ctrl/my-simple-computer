#include <stdio.h>

#include "../include/sc.h"

void
printCell (int address)
{
  int value;
  sc_memoryGet (address, &value);
  printf ("Содержимое ячейки по адресу %d: %d\n", address, value);
}

void
printFlags (void)
{
  int value;
  sc_regGet (FLAG_OVERFLOW, &value);
  printf ("Overflow: %c ", value ? '1' : '0');
  sc_regGet (FLAG_ZERO, &value);
  printf ("Zero division: %c ", value ? '1' : '0');
  sc_regGet (FLAG_OUT_OF_MEMORY, &value);
  printf ("Out of memory: %c ", value ? '1' : '0');
  sc_regGet (FLAG_CLOCKING, &value);
  printf ("Clocking: %c ", value ? '1' : '0');
  sc_regGet (FLAG_INVALID_COMMAND, &value);
  printf ("Invalid command: %c ", value ? '1' : '0');
  printf ("\n");
}

void
printDecodedCommand (int value)
{
  printf ("Значение в десятичной системе: %d\n", value);
  printf ("Значение в восьмеричной системе: %o\n", value);
  printf ("Значение в шестнадцатеричной системе: %x\n", value);
  printf ("Значение в двоичной системе: ");
  for (int i = sizeof (int) * 8 - 1; i >= 0; --i)
    {
      printf ("%d", (value >> i) & 1);
    }
  printf ("\n");
}

void
printAccumulator (void)
{
  int value;
  sc_accumulatorGet (&value);
  printf ("Значение аккумулятора: %d\n", value);
}

void
printCounters (void)
{
  int value;
  sc_icounterGet (&value);
  printf ("Значение счетчика команд: %d\n", value);
}

int
main ()
{
  sc_memoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();

  for (int i = 0; i < 10; ++i)
    {
      sc_memorySet (i, i * 10);
    }

  printf ("Содержимое оперативной памяти (десятичное значение):\n");
  for (int i = 0; i < 100; ++i)
    {
      if (i % 10 == 0 && i != 0)
        printf ("\n");
      int value;
      sc_memoryGet (i, &value);
      printf ("%d ", value);
    }
  printf ("\n");

  int result = sc_memorySet (150, 1000);
  printf ("Статус установки недопустимого значения: %d\n", result);

  sc_regSet (FLAG_OVERFLOW, 1);
  sc_regSet (FLAG_ZERO, 0);
  printf ("Содержимое регистра флагов:\n");
  printFlags ();

  result = sc_regSet (10, 1);
  printf ("Статус установки недопустимого значения флага: %d\n", result);

  sc_accumulatorSet (123);
  printf ("Значение аккумулятора: ");
  printAccumulator ();

  result = sc_accumulatorSet (1000);
  printf ("Статус установки недопустимого значения аккумулятора: %d\n",
          result);

  sc_icounterSet (50);
  printf ("Значение счетчика команд: ");
  printCounters ();

  result = sc_icounterSet (150);
  printf ("Статус установки недопустимого значения счетчика команд: %d\n",
          result);

  int memoryValue;
  sc_memoryGet (0, &memoryValue);
  printf ("Декодированное значение ячейки памяти: ");
  printDecodedCommand (memoryValue);
  printf ("Декодированное значение аккумулятора: ");
  printDecodedCommand (123);

  int command = 513;
  printf ("Кодирование команды (в разных системах счисления):\n");
  printDecodedCommand (command);

  return 0;
}