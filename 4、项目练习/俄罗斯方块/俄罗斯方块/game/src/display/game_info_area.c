
#include "game_info_area.h"
#include "terminal_util.h"
#include "util/log_util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int msg(TERMINAL_WINDOW_T *this, char arg);

GAME_INFO_AREA_T *f_Create_Game_Info_Area(TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color)
{
    GAME_INFO_AREA_T *info_area = (GAME_INFO_AREA_T *)malloc(sizeof(GAME_INFO_AREA_T));
    if (info_area == NULL)
    {
        return NULL;
    }
    memset(info_area, 0, sizeof(GAME_INFO_AREA_T));
    if (f_Create_Game_Info_Area_ex(info_area, parent, x, y, w, h, color) != 0)
    {
        free(info_area);
        return NULL;
    }

    return info_area;
}
int f_Create_Game_Info_Area_ex(GAME_INFO_AREA_T *info_area, TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color)
{
    if (info_area == NULL)
    {
        return -1;
    }
    
    {
        TERMINAL_WINDOW_T *window = &info_area->window;
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
                    if (i == 0 || j == 0 || i == w - 1 || j == h - 1)
                    {
                        int pos = j * w + i;
                        data[pos] = '*';
                    }
                }
        }
        
        {
            if (f_Create_Game_Block_ex(&info_area->block, window, x + 10, y + 2, FOREGROUND_GREEN | FOREGROUND_RED) != 0)
            {
                return -2;
            }
            if (get_random_block_ex(&info_area->block) != 0)
            {
                return -3;
            }
        }
        {
            char *str = "sorce:";
            if (f_Create_Window_Text_ex(&info_area->text1, window, x + 4, y + 9, strlen(str), 1, FOREGROUND_GREEN | FOREGROUND_RED, str) != 0)
            {
                return -4;
            }
        }
        {
            char *str = "level:";
            if (f_Create_Window_Text_ex(&info_area->text2, window, x + 4, y + 10, strlen(str), 1, FOREGROUND_GREEN | FOREGROUND_RED, str) != 0)
            {
                return -5;
            }
        }
        {
            char *str = "unknow";
            if (f_Create_Window_Text_ex(&info_area->sorce, window, x + 11, y + 9, strlen(str), 1, FOREGROUND_GREEN | FOREGROUND_RED, "unknow") != 0)
            {
                return -6;
            }
        }
        {
            char *str = "unknow";
            if (f_Create_Window_Text_ex(&info_area->level, window, x + 11, y + 10, strlen(str), 1, FOREGROUND_GREEN | FOREGROUND_RED, "unknow") != 0)
            {
                return -7;
            }
        }
        
    }

    return 0;
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
