#include "game_block_data.h"
#include "terminal_util.h"

extern int game_block_color[] =
    {
        0,
        FOREGROUND_RED,
        FOREGROUND_GREEN,
        // FOREGROUND_BLUE,
        FOREGROUND_RED | FOREGROUND_GREEN,
        FOREGROUND_GREEN | FOREGROUND_BLUE,
        FOREGROUND_BLUE | FOREGROUND_RED};
extern char game_block_data[7][4][4] =
    {
        {{0, '#', 0, 0},
         {0, '#', 0, 0},
         {0, '#', 0, 0},
         {0, '#', 0, 0}},

        {{0, '#', 0, 0},
         {0, '#', '#', 0},
         {0, 0, '#', 0},
         {0, 0, 0, 0}},

        {{0, 0, '#', 0},
         {0, '#', '#', 0},
         {0, '#', 0, 0},
         {0, 0, 0, 0}},

        {{0, 0, 0, 0},
         {0, '#', '#', 0},
         {0, '#', '#', 0},
         {0, 0, 0, 0}},

        {{0, 0, '#', 0},
         {0, '#', '#', 0},
         {0, 0, '#', 0},
         {0, 0, 0, 0}},

        {{0, 0, 0, 0},
         {0, '#', '#', 0},
         {0, 0, '#', 0},
         {0, 0, '#', 0}},

        {{0, 0, 0, 0},
         {0, '#', '#', 0},
         {0, '#', 0, 0},
         {0, '#', 0, 0}},
};