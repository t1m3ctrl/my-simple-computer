#pragma once
#include "../mySimpleComputer/sc.h"
#include <mySimpleComputer.h>
#include <myTerm.h>
#include <unistd.h>

#define ACS_CKBOARD 'a'
#define ACS_ULCORNER 'l'
#define ACS_URCORNER 'k'
#define ACS_LRCORNER 'j'
#define ACS_LLCORNER 'm'
#define ACS_HLINE 'q'
#define ACS_VLINE 'x'

int bc_strlen (char *str);
int bc_printA (char str);
int bc_box (int x, int y, int width, int height);
int bc_setbigcharpos (int *big, int x, int y, int value);
int bc_getbigcharpos (int *big, int x, int y, int *value);
int bc_printbigchar (int *big, int x, int y, enum colors bg, enum colors fg);
int bc_bigcharwrite (int fd, int *big, int count);
int bc_bigcharread (int fd, int *big, int need_count, int *count);
void printBigCell (void);