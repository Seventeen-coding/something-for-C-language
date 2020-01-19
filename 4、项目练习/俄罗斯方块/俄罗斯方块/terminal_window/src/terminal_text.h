#ifndef __W_TEXT_H__
#define __W_TEXT_H__

#include "terminal_window.h"

typedef struct WINDOW_TEXT_T
{
    TERMINAL_WINDOW_T window;
    int (*msg)(struct _WINDOW_BLOCK_T *this, char arg);
    int (*select)(struct _WINDOW_BLOCK_T *this, char arg);

    int (*set_text)(struct _WINDOW_BLOCK_T *this, char *str);
} WINDOW_TEXT_T;

WINDOW_TEXT_T *f_Create_Window_Text(TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color, char *str);
int f_Create_Window_Text_ex(WINDOW_TEXT_T *point, TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color, char *str);
#endif // __W_TEXT_H__
