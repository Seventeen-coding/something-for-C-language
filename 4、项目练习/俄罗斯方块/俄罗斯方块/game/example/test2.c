#include "game_info_area.h"
#include "terminal_util.h"
#include <stdio.h>
#include "util/log_util.h"
int main(void)
{
    HideTheCursor();
    ClearConsoleToColors(FOREGROUND_RED | FOREGROUND_GREEN, FOREGROUND_BLUE);
    ClearConsole();
    SetColorAndBackground(FOREGROUND_RED | FOREGROUND_GREEN, FOREGROUND_BLUE);

    GAME_INFO_AREA_T *info_area = f_Create_Game_Info_Area(NULL, 50, 3, 20, 30, FOREGROUND_RED | FOREGROUND_GREEN);

    if (info_area == NULL)
    {
        log_error("info_area == NULL");
        return -1;
    }

    TERMINAL_WINDOW_T *window = &info_area->window;
    window->show(window);
    while (1)
    {
        /* code */
    }

    return 0;
}