

#include "terminal_window.h"
#include <stdio.h>
#include <Stdlib.h>
#include <string.h>
#include "terminal_util.h"
#include "util/log_util.h"

static int msg(TERMINAL_WINDOW_T *this, char arg);
static int draw(TERMINAL_WINDOW_T *this);
static int erase(TERMINAL_WINDOW_T *this);
static int show(TERMINAL_WINDOW_T *this);
static int hide(TERMINAL_WINDOW_T *this);
static int _select(TERMINAL_WINDOW_T *this, char arg);
static int destory(TERMINAL_WINDOW_T *this);
static int set_pos(TERMINAL_WINDOW_T *this, int x, int y);
static int set_area(TERMINAL_WINDOW_T *this, int w, int h);
static int set_color(TERMINAL_WINDOW_T *this, int color);
static int set_data(TERMINAL_WINDOW_T *this, char *data);
//x y
TERMINAL_WINDOW_T *f_Create_Window(TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color)
{
    TERMINAL_WINDOW_T *window = (TERMINAL_WINDOW_T *)malloc(sizeof(TERMINAL_WINDOW_T));
    if (window == NULL)
    {
        return NULL;
    }
    memset(window, 0, sizeof(TERMINAL_WINDOW_T));
    if (f_Create_Window_ex(window, parent, x, y, w, h, color) != 0)
    {
        free(window);
        return NULL;
    }
    return window;
}

int f_Create_Window_ex(TERMINAL_WINDOW_T *window, TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color)
{
    if (window == NULL)
    {
        return -1;
    }
    if (x > 143 || y > 43)
    {
        return -2;
    }
    window->parent = parent;
    
    window->destory = window->destory == NULL ? destory : window->destory;
    window->show = window->show == NULL ? show : window->show;
    window->hide = window->hide == NULL ? hide : window->hide;
    window->set_position = window->set_position == NULL ? set_pos : window->set_position;
    window->select = window->select == NULL ? _select : window->select;
    window->msg = window->msg == NULL ? msg : window->msg;
    window->set_area = window->set_area == NULL ? set_area : window->set_area;
    window->set_color = window->set_color == NULL ? set_color : window->set_color;
    window->set_data = window->set_data == NULL ? set_data : window->set_data;
    window->data = (char *)malloc(sizeof(char) * w * h);
    
    if (window->data == NULL)
    {
        return -3;
    }
    memset(window->data, 0, sizeof(char) * w * h);
    window->children_list = list_create(NULL);

    //处理parent
    if (parent != NULL)
    {
        list_insert_end(parent->children_list, window);
        window->type = parent->type;
    }

    window->set_position(window, x, y);
    window->set_area(window, w, h);
    window->set_color(window, color);
    return 0;
}

static int msg(TERMINAL_WINDOW_T *this, char arg)
{
    return 0;
}

static int erase(TERMINAL_WINDOW_T *this)
{
    TERMINAL_WINDOW_T *window = (TERMINAL_WINDOW_T *)this;
    if (window->data == NULL)
    {
        return -1;
    }

    SetColor(window->color);
    for (int j = 0; j < window->h; j++)
        for (int i = 0; i < window->w; i++)
        {
            char buf[2] = {0};
            int pos = j * window->w + i;
            if (window->data[pos] == 0)
            {
                continue;
            }

            ConPrintAt(window->x + i, window->y + j, " ", strlen(" "));
        }
    return 0;
}

static int draw(TERMINAL_WINDOW_T *this)
{
    TERMINAL_WINDOW_T *window = (TERMINAL_WINDOW_T *)this;
    if (window->data == NULL)
    {
        return -1;
    }

    SetColor(window->color);
    for (int j = 0; j < window->h; j++)
        for (int i = 0; i < window->w; i++)
        {
            char buf[2] = {0};
            int pos = j * window->w + i;
            if (window->data[pos] == 0)
            {
                continue;
            }
            strncpy(buf, window->data + (pos), 1);
            ConPrintAt(window->x + i, window->y + j, buf, strlen(buf));
        }
    return 0;
}
static int show(TERMINAL_WINDOW_T *this)
{
    TERMINAL_WINDOW_T *window = (TERMINAL_WINDOW_T *)this;
    if (window == NULL)
    {
        return -1;
    }
    if (draw(window) != 0)
    {
        return -2;
    }
    CALLBACK_TO_CHILDREN(window->children_list, show, NULL);
    window->status = 1;
    return 0;
}

static int hide(TERMINAL_WINDOW_T *this)
{
    TERMINAL_WINDOW_T *window = (TERMINAL_WINDOW_T *)this;
    if (window == NULL)
    {
        return -1;
    }
    do
    {
        if (window->children_list->next == NULL)
        {
            break;
        }
        window_list_node_t *children_node = NULL;
        window_list_node_t *next_node = window->children_list->next;
        TERMINAL_WINDOW_T *w_child;
        while (next_node != NULL)
        {
            children_node = next_node;
            next_node = children_node->next;
            w_child = (TERMINAL_WINDOW_T *)children_node->data;
            w_child->hide(w_child);
        }
    } while (0);
    if (erase(window) != 0)
    {
        return -2;
    }

    window->status = 0;
    return 0;
}
static int _select(TERMINAL_WINDOW_T *this, char arg)
{
    return 0;
}
static int destory(TERMINAL_WINDOW_T *this)
{

    return 0;
}
static int set_data(TERMINAL_WINDOW_T *this, char *data)
{
    TERMINAL_WINDOW_T *window = (TERMINAL_WINDOW_T *)this;
    if (data == NULL || window == NULL)
    {
        return -1;
    }
    int status = window->status;
    if (status != 0)
    {
        window->hide(window);
    }
    memcpy(this->data, data, sizeof(char) * this->w * this->h);
    if (status != 0)
    {
        window->show(window);
    }
    return 0;
}
static int set_pos(TERMINAL_WINDOW_T *this, int x, int y)
{
    TERMINAL_WINDOW_T *window = (TERMINAL_WINDOW_T *)this;
    if (window == NULL)
    {
        return -1;
    }
    int status = window->status;
    if (status != 0)
    {
        window->hide(window);
    }
    window->x = x;
    window->y = y;
    if (status != 0)
    {
        window->show(window);
    }

    return 0;
}
static int set_color(TERMINAL_WINDOW_T *this, int color)
{
    TERMINAL_WINDOW_T *window = (TERMINAL_WINDOW_T *)this;
    if (window == NULL)
    {
        return -1;
    }
    window->color = color;
    return 0;
}
static int set_area(TERMINAL_WINDOW_T *this, int w, int h)
{
    TERMINAL_WINDOW_T *window = (TERMINAL_WINDOW_T *)this;
    if (window == NULL)
    {
        return -1;
    }
    window->w = w;
    window->h = h;
    return 0;
}
