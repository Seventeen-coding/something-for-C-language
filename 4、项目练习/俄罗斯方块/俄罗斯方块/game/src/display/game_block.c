
#include "game_block.h"
// #include "block_type.h"
#include "game_block_data.h"
#include "util/log_util.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static int msg(GAME_BLOCK_T *this, char arg);
static int turn(GAME_BLOCK_T *this);

GAME_BLOCK_T *f_Create_Game_Block(TERMINAL_WINDOW_T *parent, int x, int y, int color);
int f_Create_Game_Block_ex(GAME_BLOCK_T *block, TERMINAL_WINDOW_T *parent, int x, int y, int color);

GAME_BLOCK_T *f_Create_Game_Block(TERMINAL_WINDOW_T *parent, int x, int y, int color)
{
    GAME_BLOCK_T *block = (GAME_BLOCK_T *)malloc(sizeof(GAME_BLOCK_T));
    if (block == NULL)
    {
        return NULL;
    }
    memset(block, 0, sizeof(GAME_BLOCK_T));
    if (f_Create_Game_Block_ex(block, parent, x, y, color) != 0)
    {
        free(block);
        return NULL;
    }
    return block;
}
int f_Create_Game_Block_ex(GAME_BLOCK_T *block, TERMINAL_WINDOW_T *parent, int x, int y, int color)
{
    if (block == NULL || parent == NULL)
    {
        return -1;
    }
    block->turn = block->turn == NULL ? turn : block->turn;
    block->msg = block->msg == NULL ? msg : block->msg;
    {
        WINDOW_BLOCK_T *window_block = &block->window;
        // window_block->select = (block->select == NULL ? _select : block->select);
        window_block->msg = (block->msg == NULL ? msg : block->msg);
        if (f_Create_Window_Block_ex(window_block, parent, x, y, 4, 4, color) != 0)
        {
            return -2;
        }
    }
    return 0;
}
static char *get_block_data(int index)
{
    extern char game_block_data[7][4][4];

    char *block_data = (char *)&game_block_data[index][0][0];

    return (char *)(block_data);
}
static int get_random(int range)
{
    static int count = 0;
    count = count % 1000;
    count++;
    srand(time(0) + count);
    return rand() % range;
}
static int get_random_block_color(void)
{
    extern int game_block_color[6];
    return game_block_color[get_random(sizeof(game_block_color) / sizeof(int))];
}

static char *get_random_block_data(void)
{
    return get_block_data(get_random(7));
}
GAME_BLOCK_T *get_random_block(TERMINAL_WINDOW_T *parent, int x, int y)
{
    GAME_BLOCK_T *block = f_Create_Game_Block(parent, x, y, get_random_block_color());
    if (block == NULL)
    {
        return NULL;
    }
    if (get_random_block_ex(block) != 0)
    {
        free(block);
        return NULL;
    }
    return block;
}
int get_random_block_ex(GAME_BLOCK_T *block)
{
    if (block == NULL)
    {
        return -1;
    }

    TERMINAL_WINDOW_T *window = &block->window.window;
    if (f_Create_Game_Block_ex(block, window->parent, window->x, window->y, get_random_block_color()) != 0)
    {
        return -2;
    }

    {
        TERMINAL_WINDOW_T *window = (TERMINAL_WINDOW_T *)&block->window.window;
        char *data = get_random_block_data();
        memcpy(window->data, data, sizeof(char) * 4 * 4);
    }
    return 0;
}
static int msg(GAME_BLOCK_T *this, char arg)
{
    return 0;
}

static int turn(GAME_BLOCK_T *this)
{
    TERMINAL_WINDOW_T *block = &this->window;
    char tmp_data[4][4];

    for (int j = 0; j < block->h; j++)
        for (int i = 0; i < block->w; i++)
        {
            tmp_data[i][block->w - 1 - j] = block->data[j * block->w + i];
        }
    block->set_data(block, tmp_data);
    return 0;
}