#ifndef __W_POINT_H__
#define __W_POINT_H__

#include "terminal_window.h"

typedef struct WINDOW_POINT_T
{
    TERMINAL_WINDOW_T window;
} WINDOW_POINT_T;

WINDOW_POINT_T *f_Create_Window_Point(TERMINAL_WINDOW_T *parent, int x, int y, int color);
int f_Create_Window_Point_ex(WINDOW_POINT_T *point, TERMINAL_WINDOW_T *parent, int x, int y, int color);
#endif // __W_POINT_H__
