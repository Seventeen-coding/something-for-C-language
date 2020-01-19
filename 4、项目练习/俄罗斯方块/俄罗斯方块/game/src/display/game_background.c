
#include "game_background.h"
#include "util/log_util.h"
#include "terminal_util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int msg(TERMINAL_WINDOW_T *this, char arg);
static int reset_play_area_block(GAME_BACKGROUND_T *background);
GAME_BACKGROUND_T *f_Create_Game_Background(void)
{
    GAME_BACKGROUND_T *block = (GAME_BACKGROUND_T *)malloc(sizeof(GAME_BACKGROUND_T));
    if (block == NULL)
    {
        return NULL;
    }
    memset(block, 0, sizeof(GAME_BACKGROUND_T));
    if (f_Create_Game_Background_ex(block) != 0)
    {
        free(block);
        return NULL;
    }
    return block;
}
int f_Create_Game_Background_ex(GAME_BACKGROUND_T *background)
{
    if (background == NULL)
    {
        return -1;
    }

    {
        TERMINAL_WINDOW_T *window = &background->window;
        background->window.msg = msg;
        if (f_Create_Window_ex(&background->window, NULL, 3, 3, 143, 43, FOREGROUND_GREEN | FOREGROUND_RED) != 0)
        {
            return -2;
        }

        {
            int w = 30;
            int h = 23;
            int x = background->window.x + 0;
            int y = background->window.y + 0;
            if (f_Create_Game_Play_Area_ex(&background->play_area, &background->window, x, y, w, h, FOREGROUND_GREEN | FOREGROUND_RED) != 0)
            {
                return -3;
            }
        }

        {
            int w = 30;
            int h = 23;
            int x = background->window.x + 30;
            int y = background->window.y + 0;
            if (f_Create_Game_Info_Area_ex(&background->info_area, &background->window, x, y, w, h, FOREGROUND_GREEN | FOREGROUND_RED) != 0)
            {
                return -4;
            }
        }
    }
    reset_play_area_block(background);

    return 0;
}
static int reset_play_area_block(GAME_BACKGROUND_T *background)
{
    TERMINAL_WINDOW_T *play_area = (TERMINAL_WINDOW_T *)&background->play_area.window;
    TERMINAL_WINDOW_T *info_block = (TERMINAL_WINDOW_T *)&background->info_area.block;
    TERMINAL_WINDOW_T *play_block = (TERMINAL_WINDOW_T *)&background->play_area.block;
    char *info_area_block_data = info_block->data;
    char *play_area_block_data = play_block->data;
    int w = play_block->w;
    int h = play_block->h;
    memcpy(play_area_block_data, info_area_block_data, sizeof(char) * w * h);
    play_block->set_position(play_block, play_area->x + 10, play_area->y + 2);
    return get_random_block_ex(info_block);
}

static int msg(TERMINAL_WINDOW_T *this, char arg)
{
    switch (arg)
    {
    case 'q':
    {
        return -1;
    }
    break;
    default:
        break;
    }
    CALLBACK_TO_CHILDREN(this->children_list, msg, NULL);

    return 0;
}
