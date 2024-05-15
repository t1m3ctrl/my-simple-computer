#pragma once
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define OUT_OF_MEMORY_BOUNDS 1
#define OVERFLOW_OPERATION 2
#define IGNORING_TACT_PULSES 3
#define INCORRECT_COMMAND_RECEIVED 4
#define DIVISION_ERR_BY_ZERO 5

#define CACHE_SIZE 5
#define CACHE_LINE_SIZE 10

typedef struct
{
  int address;
  int data[CACHE_LINE_SIZE];
  int lastAccessTime;
} CacheLine;

int sc_memoryInit (void);
int sc_memorySet (int address, int value);
int sc_memoryGet (int address, int *value);
int sc_memorySave (char *filename);
int sc_memoryLoad (char *filename);

int sc_regInit (void);
int sc_regSet (int regist, int value);
int sc_regGet (int regist, int *value);

int sc_commandEncode (int command, int operand, int *value);
int sc_commandDecode (int value, int *command, int *operand);
int sc_commandValidate (int command);

int sc_accumulatorInit (void);
int sc_accumulatorGet (int *value);
int sc_accumulatorSet (int value);

int sc_icounterInit (void);
int sc_icounterSet (int value);
int sc_icounterGet (int *value);

void printCell (void);
void printFlags (void);
void printDecodedCommand (int value);
void printAccumulator (void);
void printCounters (void);

void sc_initCache ();
void sc_updateCacheAfterSave (int memaddress, int cacheLine, int *value);
int sc_findLeastRecentlyUsedCacheEntry ();

bool initStatics (bool flag);
