#ifndef _TERMINAL_BLOCK_H_
#define _TERMINAL_BLOCK_H_

#include "terminal_point.h"

typedef struct _WINDOW_BLOCK_T
{
    TERMINAL_WINDOW_T window;

    int (*msg)(struct _WINDOW_BLOCK_T *this, char arg);
    int (*select)(struct _WINDOW_BLOCK_T *this, char arg);
} WINDOW_BLOCK_T;

WINDOW_BLOCK_T *f_Create_Window_Block(TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color);
int f_Create_Window_Block_ex(WINDOW_BLOCK_T *block, TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color);
#endif // _TERMINAL_BLOCK_H_
