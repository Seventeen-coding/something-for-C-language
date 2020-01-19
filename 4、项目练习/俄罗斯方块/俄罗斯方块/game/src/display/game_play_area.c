
#include "game_play_area.h"
#include "util/log_util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static int msg(TERMINAL_WINDOW_T *this, char arg);
static int block_move(GAME_PLAY_AREA_T *play_area, int x, int y);
static int block_turn(GAME_PLAY_AREA_T *play_area);
static int block_reset(GAME_PLAY_AREA_T *play_area);
static int check_window_line(GAME_PLAY_AREA_T *play_area);
//定时器的回调函数
void WINAPI TimerCallback(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2)
{
    // static int check_flag = 0;
    // if (check_flag != 0)
    // {
    //     return;
    // }
    GAME_PLAY_AREA_T *play_area = (GAME_PLAY_AREA_T *)dwUser;
    TERMINAL_WINDOW_T *block = &play_area->block.window;
    TERMINAL_WINDOW_T *window = &play_area->window;
    int ret = block_move(play_area, block->x, block->y + 1);
    if (ret == 0)
    {
        return;
    }

    // check_flag = 1;
    block_reset(play_area);
    check_window_line(play_area);
    window->set_position(window, window->x, window->y);
    // check_flag = 0;
}

GAME_PLAY_AREA_T *f_Create_Game_Play_Area(TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color)
{
    GAME_PLAY_AREA_T *play_area = (GAME_PLAY_AREA_T *)malloc(sizeof(GAME_PLAY_AREA_T));

    if (play_area == NULL)
    {
        return NULL;
    }
    if (f_Create_Game_Play_Area_ex(play_area, parent, x, y, w, h, color))
    {
        free(play_area);
        return NULL;
    }

    return play_area;
}
int f_Create_Game_Play_Area_ex(GAME_PLAY_AREA_T *play_area, TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color)
{
    if (play_area == NULL)
    {
        return -1;
    }

    {
        TERMINAL_WINDOW_T *window = &play_area->window;
        window->msg = msg;
        if (f_Create_Window_ex(window, parent, x, y, w, h, color) != 0)
        {
            return -2;
        }

        {
            int w = window->w, h = window->h;
            char *data = window->data;

            for (int i = 0; i < w; i++)
                for (int j = 0; j < h; j++)
                {
                    int pos = j * w + i;
                    if (i == 0 || j == 0 || i == w - 1 || j == h - 1)
                    {
                        data[pos] = '*';
                    }
                    else
                    {
                        data[pos] = ' ';
                    }
                }
        }

        if (f_Create_Game_Block_ex(&play_area->block, window, x + 10, y + 2, color) != 0)
        {
            return -3;
        }
    }

    // 设置定时器
    int timerID = timeSetEvent(1000, 1, (LPTIMECALLBACK)TimerCallback, play_area, TIME_PERIODIC);
    if (timerID == NULL)
    {
        return -4;
    }

    return 0;
}

static int msg(TERMINAL_WINDOW_T *this, char arg)
{
    GAME_PLAY_AREA_T *play_area = this;
    TERMINAL_WINDOW_T *block = &play_area->block.window;
    TERMINAL_WINDOW_T *window = &play_area->window;
    switch (arg)
    {
    case 'a':
    {
        block_move(play_area, block->x - 1, block->y);
    }
    break;
    case 'd':
    {
        block_move(play_area, block->x + 1, block->y);
    }
    break;
    case 's':
    {
        for (int i = 0; i < window->h; i++)
        {
            int ret = block_move(play_area, block->x, block->y + 1);
            if (ret != 0)
            {
                break;
            }
        }
    }
    break;
    case 'w':
    {
        block_turn(play_area);
    }
    break;
    default:
    {
    }
    break;
    }
    CALLBACK_TO_CHILDREN(this->children_list, msg, NULL);
    return 0;
}
static int block_turn(GAME_PLAY_AREA_T *play_area)
{
    GAME_BLOCK_T *block = &play_area->block;
    TERMINAL_WINDOW_T *block_window = &block->window;
    TERMINAL_WINDOW_T *window = &play_area->window;

    for (int j = 0; j < block_window->h; j++)
        for (int i = 0; i < block_window->w; i++)
        {
            int pos = (block_window->y - window->y + j) * window->w + block_window->x - window->x + i;

            if (window->data[pos] == ' ')
            {
                continue;
            }

            int pos2 = (block_window->w - 1 - i) * block_window->w + j;
            if (block_window->data[pos2] == 0)
            {
                continue;
            }

            return -1;
        }
    block->turn(block);
    return 0;
}
static int block_move(GAME_PLAY_AREA_T *play_area, int x, int y)
{
    TERMINAL_WINDOW_T *block = &play_area->block.window;
    TERMINAL_WINDOW_T *window = &play_area->window;

    for (int j = 0; j < block->h; j++)
        for (int i = 0; i < block->w; i++)
        {
            int pos = (y - window->y + j) * window->w + x - window->x + i;
            if (window->data[pos] == ' ')
            {
                continue;
            }
            int pos2 = j * block->w + i;
            if (block->data[pos2] == 0)
            {
                continue;
            }

            return -1;
        }

    block->set_position(block, x, y);
    return 0;
}

static int block_reset(GAME_PLAY_AREA_T *play_area)
{
    TERMINAL_WINDOW_T *block = &play_area->block.window;
    TERMINAL_WINDOW_T *window = &play_area->window;

    for (int j = 0; j < block->h; j++)
        for (int i = 0; i < block->w; i++)
        {
            int pos = (block->y - window->y + j) * window->w + block->x - window->x + i;
            // int pos = (j)*window->w + i;
            int pos2 = (j)*block->w + i;
            if (block->data[pos2] == 0)
            {
                continue;
            }
            window->data[pos] = block->data[pos2];
        }
    block->set_position(block, window->x + 10, window->y + 2);
    return 0;
}

static int check_window_line(GAME_PLAY_AREA_T *play_area)
{
    TERMINAL_WINDOW_T *window = &play_area->window;

    for (int j = window->h - 2; j > 1; j--)
    {
        int i = 1;
        for (; i < window->w - 1; i++)
        {
            int pos = j * window->w + i;
            if (window->data[pos] == ' ')
            {
                break;
            }
        }

        if (i != window->w - 1)
        {
            continue;
        }
        for (int n = j; n > 1; n--)
        {
            int pos = n * window->w;
            int pos2 = (n - 1) * window->w;
            memcpy(window->data[pos], window->data[pos2], sizeof(char) * window->w);
        }
        j++;
    }
    return 0;
}