#ifndef __GAME_PLAY_AREA_H__
#define __GAME_PLAY_AREA_H__

#include "game_block.h"
#include <windows.h>
typedef struct _GAME_PLAY_AREA_T
{
    TERMINAL_WINDOW_T window;
    GAME_BLOCK_T block;
    DWORD_PTR dwUser;
} GAME_PLAY_AREA_T;

GAME_PLAY_AREA_T *f_Create_Game_Play_Area(TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color);
int f_Create_Game_Play_Area_ex(GAME_PLAY_AREA_T *play_area, TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color);

#endif // __GAME_PLAY_AREA_H__
