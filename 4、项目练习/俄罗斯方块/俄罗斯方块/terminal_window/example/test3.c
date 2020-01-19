#include "terminal_text.h"
#include "terminal_util.h"
#include <stdio.h>
#include "util/log_util.h"
int main(void)
{
    system("chcp 65001"); //设置终端编码格式为utf-8
    HideTheCursor();
    ClearConsoleToColors(FOREGROUND_RED | FOREGROUND_GREEN, FOREGROUND_BLUE);
    ClearConsole();
    SetColorAndBackground(FOREGROUND_RED | FOREGROUND_GREEN, FOREGROUND_BLUE);

    {
        WINDOW_TEXT_T *text = f_Create_Window_Text(NULL, 10, 2, 8, 7, FOREGROUND_GREEN, "hello world");

        if (text == NULL)
        {
            return -1;
        }
        TERMINAL_WINDOW_T *window = &text->window;
        window->show(window);
        Sleep(1000);
        window->hide(window);
        text->set_text(text, "中文测试");
        window->show(window);
    }
    while (1)
    {
    }
    return 0;
}