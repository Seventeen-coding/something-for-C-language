#include "game_background.h"
#include "terminal_util.h"
#include <stdio.h>
#include "util/log_util.h"
int main(void)
{
    HideTheCursor();
    ClearConsoleToColors(FOREGROUND_RED | FOREGROUND_GREEN, FOREGROUND_BLUE);
    ClearConsole();
    SetColorAndBackground(FOREGROUND_RED | FOREGROUND_GREEN, FOREGROUND_BLUE);

    GAME_BACKGROUND_T *background = f_Create_Game_Background();
    TERMINAL_WINDOW_T *window = &background->window;

    window->show(window);
    while (1)
    {
    }
    return 0;
}