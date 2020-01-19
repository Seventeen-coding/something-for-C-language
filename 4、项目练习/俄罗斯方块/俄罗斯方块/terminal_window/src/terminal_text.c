
#include "terminal_text.h"
#include <stdio.h>
#include <String.h>
#include <stdlib.h>
#include "util/log_util.h"

static int msg(TERMINAL_WINDOW_T *this, char arg);
static int _select(TERMINAL_WINDOW_T *this, char arg);

int _set_text(WINDOW_TEXT_T *this, char *str);

WINDOW_TEXT_T *f_Create_Window_Text(TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color, char *str)
{
    WINDOW_TEXT_T *text = (WINDOW_TEXT_T *)malloc(sizeof(WINDOW_TEXT_T));
    if (text == NULL)
    {
        return NULL;
    }
    memset(text, 0, sizeof(WINDOW_TEXT_T));
    if (f_Create_Window_Text_ex(text, parent, x, y, w, h, color, str) != 0)
    {
        free(text);
        return NULL;
    }
    return text;
}
int f_Create_Window_Text_ex(WINDOW_TEXT_T *text, TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color, char *str)
{
    if (text == NULL)
    {
        return -1;
    }

    text->select = text->select == NULL ? _select : text->select;

    text->msg = text->msg == NULL ? msg : text->msg;

    {
        TERMINAL_WINDOW_T *window = &text->window;
        text->window.select = text->select == NULL ? _select : text->select;
        text->window.msg = text->msg == NULL ? msg : text->msg;
        if (f_Create_Window_ex(window, parent, x, y, w, h, color) != 0)
        {
            return -2;
        }
    }
    text->set_text = _set_text;
    if (str != NULL)
    {
        text->set_text(text, str);
    }

    return 0;
}

static int msg(TERMINAL_WINDOW_T *this, char arg)
{
    return 0;
}

static int _select(TERMINAL_WINDOW_T *this, char arg)
{
    return 0;
}

int _set_text(WINDOW_TEXT_T *this, char *str)
{
    TERMINAL_WINDOW_T *window = (TERMINAL_WINDOW_T *)this;
    if (window == NULL || str == NULL)
    {
        return -1;
    }

    if (window->data == NULL)
    {
        return -2;
    }

    memset(window->data, 0, strlen(window->data));
    memcpy(window->data, str, strlen(str));
    return 0;
}