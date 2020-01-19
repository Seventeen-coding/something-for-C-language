
#include "terminal_point.h"
#include <stdio.h>
#include "terminal_util.h"
#include "util/log_util.h"

static int msg(TERMINAL_WINDOW_T *this, char arg);
static int _select(TERMINAL_WINDOW_T *this, char arg);

WINDOW_POINT_T *f_Create_Window_Point(TERMINAL_WINDOW_T *parent, int x, int y, int color)
{
    WINDOW_POINT_T *point = (WINDOW_POINT_T *)malloc(sizeof(WINDOW_POINT_T));
    if (point == NULL)
    {
        return NULL;
    }
    memset(point, 0, sizeof(WINDOW_POINT_T));
    if (f_Create_Window_Point_ex(point, parent, x, y, color) != 0)
    {
        free(point);
        return NULL;
    }

    return (WINDOW_POINT_T *)point;
}

int f_Create_Window_Point_ex(WINDOW_POINT_T *point, TERMINAL_WINDOW_T *parent, int x, int y, int color)
{

    if (point == NULL || parent == NULL)
    {
        return -1;
    }
    {
        TERMINAL_WINDOW_T *window = &point->window;
        point->window.select = point->window.select == NULL ? _select : point->window.select;
        point->window.msg = point->window.msg == NULL ? msg : point->window.msg;
        if (f_Create_Window_ex(window, parent, x, y, 1, 1, color) != 0)
        {
            return -2;
        }
    }
    char data[1][1];
    data[0][0] = '#';
    memcpy(point->window.data, data, sizeof(data));
    return 0;
}
static int _select(TERMINAL_WINDOW_T *this, char arg)
{
    return 0;
}

static int msg(TERMINAL_WINDOW_T *this, char msg)
{

    return 0;
}
