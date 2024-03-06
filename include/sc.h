#ifndef SC_H
#define SC_H

#include <stdio.h>

#define MEMORY_SIZE 128

#define FLAG_OVERFLOW 1
#define FLAG_ZERO 2
#define FLAG_OUT_OF_MEMORY 3
#define FLAG_CLOCKING 4
#define FLAG_INVALID_COMMAND 5

#define SC_COMMAND_BITS 7
#define SC_COMMAND_MASK ((1 << SC_COMMAND_BITS) - 1) // 127

#define SC_SIGN_BIT 6
#define SC_SIGN_MASK (1 << SC_SIGN_BIT)

#define SC_OPERAND_BITS 7
#define SC_OPERAND_MASK ((1 << SC_OPERAND_BITS) - 1) // 127

extern int
    memory[MEMORY_SIZE]; // хранит 2^15 разрядов в каждой ячейке (0..32767)

extern int accumulator;     // используемый для временного хранения данных и
                            // результатов операций, имеет разрядность 15 бит
extern int command_counter; // указывающий на адрес ячейки памяти, в которой
                            // хранится текущая выполняемая команда,
                            // разрядность регистра – 15 бит
extern int flag_register;   // содержит 5 разрядов, каждый из которых показывает
                            // находится ли процессор в соответствующем состоянии

int sc_memoryInit (void);
int sc_memoryGet (int address, int *value);
int sc_memorySet (int address, int value);
int sc_memorySave (char *filename);
int sc_memoryLoad (char *filename);

int sc_regInit (void);
int sc_regSet (int reg, int value);
int sc_regGet (int reg, int *value);
int sc_accumulatorInit (void);
int sc_accumulatorSet (int value);
int sc_accumulatorGet (int *value);
int sc_icounterInit (void);
int sc_icounterSet (int value);
int sc_icounterGet (int *value);

int sc_commandEncode (int sign, int command, int operand, int *value);
int sc_commandDecode (int value, int *sign, int *command, int *operand);
int sc_commandValidate (int command);

#endif