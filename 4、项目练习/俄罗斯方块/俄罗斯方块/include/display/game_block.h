#ifndef _GAME_BLOCK_H_
#define _GAME_BLOCK_H_

#include "terminal_block.h"

typedef struct _GAME_BLOCK_T
{
    WINDOW_BLOCK_T window;
    int (*msg)(struct _GAME_BLOCK_T *this, char arg);
    int (*turn)(struct _GAME_BLOCK_T *this);
} GAME_BLOCK_T;

GAME_BLOCK_T *get_random_block(TERMINAL_WINDOW_T *parent, int x, int y);
int get_random_block_ex(GAME_BLOCK_T *block);
GAME_BLOCK_T *f_Create_Game_Block(TERMINAL_WINDOW_T *parent, int x, int y, int color);
int f_Create_Game_Block_ex(GAME_BLOCK_T *block, TERMINAL_WINDOW_T *parent, int x, int y, int color);
#endif // _GAME_BLOCK_H_
