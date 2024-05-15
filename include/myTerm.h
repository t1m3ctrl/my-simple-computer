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
#include <sys/ioctl.h>
#include <time.h>

#define BASE_MEMORY_ADDRESS 10
#define MEMORY_BLOCK_WIDTH 10
#define CELL_WIDTH 6
#define MEMORY_BLOCK_START_ROW 1
#define MEMORY_BLOCK_START_COL 2

#define DEC_COMMAND_BLOCK_ROW 15
#define DEC_COMMAND_BLOCK_COL 2

#define FLAGS_BLOCK_ROW 1
#define FLAGS_BLOCK_COL 90

#define COUNTERS_BLOCK_ROW 3
#define COUNTERS_BLOCK_COL 65

#define ACCUMULATOR_BLOCK_ROW 1
#define ACCUMULATOR_BLOCK_COL 65

#define COMMAND_BLOCK_ROW 3
#define COMMAND_BLOCK_COL 90

#define IN_OUT_ROW 8
#define IN_OUT_COL 70

enum colors
{
  RED = 196,
  PEACH = 203,
  GREEN = 10,
  SOFT_GREEN = 192,
  INPUT = 39,
  BLUE = 20,
  BLACK = 16,
  GRAY = 240,
  WHITE = 15,
  DEFAULT = 0
};

typedef struct memBuffer
{
  int addr;
  int buf;
} memBuffer1;

int mt_clrscr (void);
int mt_gotoXY (int col, int row);
int mt_getscreensize (int *rows, int *cols);
int mt_setfgcolor (enum colors color);
int mt_setbgcolor (enum colors color);
int mt_setdefaultcolors (void);
int mt_setcursorvisible (int value);
int mt_delline (void);
void printTerm (int address, int input, memBuffer1 *);
void printCommand (void);