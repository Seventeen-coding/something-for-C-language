#include "terminal_window.h"
#include "terminal_block.h"
#include "terminal_text.h"
#include "terminal_point.h"
#include "terminal_util.h"
#include <stdio.h>
#include "util/log_util.h"
int main(void)
{
    HideTheCursor();
    ClearConsoleToColors(FOREGROUND_RED | FOREGROUND_GREEN, FOREGROUND_BLUE);
    ClearConsole();
    SetColorAndBackground(FOREGROUND_RED | FOREGROUND_GREEN, FOREGROUND_BLUE);

    TERMINAL_WINDOW_T *window = f_Create_Window(NULL, 10, 10, 100, 150, FOREGROUND_GREEN);
    if (window == NULL)
    {
        return -1;
    }

    int x = window->x, y = window->y;
    WINDOW_BLOCK_T *block = f_Create_Window_Block(window, 50, 20, 4, 4, FOREGROUND_RED);
    window->show(window);
    while (1)
    {
        char key = getch();
        switch (key)
        {
        case 'a':
        {
            TERMINAL_WINDOW_T *block_window = &block->window;
            block_window->set_position(block_window, block_window->x - 1, block_window->y);
        }
        break;
        case 'd':
        {
            TERMINAL_WINDOW_T *block_window = &block->window;
            block_window->set_position(block_window, block_window->x + 1, block_window->y);
        }
        break;
        case 's':
        {
            TERMINAL_WINDOW_T *block_window = &block->window;
            block_window->set_position(block_window, block_window->x, block_window->y + 1);
        }
        break;
        case 'w':
        {
            TERMINAL_WINDOW_T *block_window = &block->window;
            block_window->set_position(block_window, block_window->x, block_window->y - 1);
        }
        break;
        case 'q':
        {
            return 0;
        }
        break;
        default:
        {
        }
        break;
        }
    }
    return 0;
}