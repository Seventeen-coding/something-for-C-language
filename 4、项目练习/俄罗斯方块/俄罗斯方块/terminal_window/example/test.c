#include "terminal_window.h"
#include "terminal_block.h"
#include "terminal_util.h"
#include <stdio.h>
#include "util/log_util.h"
int main(void)
{

    {
        HideTheCursor();
        ClearConsoleToColors(FOREGROUND_BLUE, FOREGROUND_GREEN);
        ClearConsole();
        SetColor(FOREGROUND_BLUE);
        SetColorAndBackground(FOREGROUND_BLUE, FOREGROUND_GREEN);
    }

    TERMINAL_WINDOW_T *window = f_Create_Window(NULL, 10, 10, 100, 150, FOREGROUND_GREEN);
    if (window == NULL)
    {
        return -1;
    }

    int x = window->x, y = window->y;
    WINDOW_BLOCK_T *block = f_Create_Window_Block(window, 50, 20, 4, 4, FOREGROUND_RED);
    if (block == NULL)
    {
        return -1;
    }

    window->show(window);
    Sleep(1000);
    window->hide(window);

    do
    {

    } while (1);
    return 0;
}