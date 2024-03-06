#ifndef SC_H
#define SC_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum colors {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

int mt_clrscr (void);
int mt_gotoXY (int x, int y);
int mt_getscreensize (int *rows, int *cols);
int mt_setfgcolor (enum colors color);
int mt_setbgcolor (enum colors color);
int mt_setdefaultcolor (void);
int mt_setcursorvisible (int value);
int mt_delline (void);


#endif
