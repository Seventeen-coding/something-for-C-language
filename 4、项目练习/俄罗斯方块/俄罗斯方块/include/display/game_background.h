#ifndef __GAME_BACKGROUND_H__
#define __GAME_BACKGROUND_H__

#include "game_info_area.h"
#include "game_play_area.h"

typedef struct _GAME_BACKGROUND_T
{
    TERMINAL_WINDOW_T window;
    GAME_PLAY_AREA_T play_area;
    GAME_INFO_AREA_T info_area;
    
} GAME_BACKGROUND_T;

GAME_BACKGROUND_T *f_Create_Game_Background(void);
int f_Create_Game_Background_ex(GAME_BACKGROUND_T *background);

#endif // GAME_BACKGROUND_H
