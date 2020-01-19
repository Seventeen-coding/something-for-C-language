#ifndef _GAME_H_
#define _GAME_H_

#include "display/game_background.h"
#include "config/game_config.h"
#include "util/game_util.h"
typedef struct _GAME_T
{
    GAME_CONFIG_T *config;
    GAME_BACKGROUND_T *background;
    GAME_UTIL_T *game_util;
    TERMINAL_WINDOW_T *focus;
    int (*load)(struct _GAME_T *this, GAME_CONFIG_T *config, GAME_BACKGROUND_T *background);
    int (*run)(struct _GAME_T *this);
    int (*stop)(struct _GAME_T *this);
    int (*exit)(struct _GAME_T *this);
} GAME_T;

GAME_T *Get_Game(void);

#endif // _GAME_H_
