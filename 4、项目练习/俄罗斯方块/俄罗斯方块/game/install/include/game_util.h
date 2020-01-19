#ifndef _GAME_UTIL_H_
#define _GAME_UTIL_H_


#include "list.h"

typedef int (*KEY_CALLBACK_FUNC)(char arg);
typedef list_node KEY_REGISTER_NODE_T;

typedef struct _GAME_UTIL_T
{
    int (*run_key_monitor)(struct _GAME_UTIL_T *this);
    int (*register_key_callback)(struct _GAME_UTIL_T *this, KEY_CALLBACK_FUNC callback);
} GAME_UTIL_T;

GAME_UTIL_T *Get_Game_Util(void);
// int draw_point(int x, int y);
// int draw_line(int x1, int y1, int x2, int y2);
// int draw_rect(int x1, int y1, int x2, int y2);
// int draw_line_ex(int x, int y, int w, int h);
// int draw_rect_ex(int x, int y, int w, int h);
// int print_text(int x, int y, const char *str);

#endif //_GAME_UTIL_H_