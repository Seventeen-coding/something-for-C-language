#ifndef _GAME_INFO_AREA_H_
#define _GAME_INFO_AREA_H_

#include "game_block.h"
#include "terminal_text.h"
typedef struct _GAME_INFO_AREA_T
{
    TERMINAL_WINDOW_T window;
    int x;
    int y;
    int w;
    int h;
    GAME_BLOCK_T block;
    WINDOW_TEXT_T text1;
    WINDOW_TEXT_T text2;
    WINDOW_TEXT_T sorce;
    WINDOW_TEXT_T level;
} GAME_INFO_AREA_T;

GAME_INFO_AREA_T *f_Create_Game_Info_Area(TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color);
int f_Create_Game_Info_Area_ex(GAME_INFO_AREA_T *background, TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color);

#endif // _GAME_INFO_AREA_H_
