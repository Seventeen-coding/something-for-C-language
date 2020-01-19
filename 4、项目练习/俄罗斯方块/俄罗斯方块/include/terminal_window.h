#ifndef TERMINAL_WINDOW_H
#define TERMINAL_WINDOW_H

#include "terminal_window.h"
#include "list.h"

typedef list_node window_list_node_t;
typedef struct TERMINAL_WINDOW_T
{
    // window_function_t function;
    int (*msg)(struct TERMINAL_WINDOW_T *this, char arg);
    int (*show)(struct TERMINAL_WINDOW_T *this);
    int (*hide)(struct TERMINAL_WINDOW_T *this);
    int (*select)(struct TERMINAL_WINDOW_T *this, char arg);
    int (*destory)(struct TERMINAL_WINDOW_T *this);
    int (*set_position)(struct TERMINAL_WINDOW_T *this, int x, int y);
    int (*set_area)(struct TERMINAL_WINDOW_T *this, int x, int y);
    int (*set_color)(struct TERMINAL_WINDOW_T *this, int color);
    int (*set_data)(struct TERMINAL_WINDOW_T *this, char *data);
    char *data;
    struct TERMINAL_WINDOW_T *parent;
    window_list_node_t *children_list;
    char *type;
    //Relative Position
    int x;
    int y;
    int w;
    int h;
    int color;
    int status; // 0 hide other show
} TERMINAL_WINDOW_T;
typedef int (*window_msg_func)(TERMINAL_WINDOW_T *this, char arg);
typedef int (*window_select_func)(TERMINAL_WINDOW_T *this, char arg);

#define CALLBACK_TO_CHILDREN(list, callback, arg)                                    \
    do                                                                               \
    {                                                                                \
        if (list->next == NULL)                                                      \
        {                                                                            \
            break;                                                                   \
        }                                                                            \
        window_list_node_t *children_node = NULL;                                    \
        window_list_node_t *next_node = list->next;                                  \
        TERMINAL_WINDOW_T *w_child;                                                  \
        while (next_node != NULL)                                                    \
        {                                                                            \
            children_node = next_node;                                               \
            next_node = children_node->next;                                         \
            w_child = (TERMINAL_WINDOW_T *)children_node->data;                      \
            if (w_child == NULL)                                                     \
            {                                                                        \
                continue;                                                            \
            }                                                                        \
            void *callback_arg = arg;                                                \
            if (callback_arg == NULL)                                                \
            {                                                                        \
                int (*callback_func)(TERMINAL_WINDOW_T *) = w_child->callback;       \
                callback_func(w_child);                                              \
            }                                                                        \
            else                                                                     \
            {                                                                        \
                int (*callback_func)(TERMINAL_WINDOW_T *, char) = w_child->callback; \
                callback_func(w_child, callback_arg);                                \
            }                                                                        \
        }                                                                            \
    } while (0)

TERMINAL_WINDOW_T *f_Create_Window(TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color);
int f_Create_Window_ex(TERMINAL_WINDOW_T *window, TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color);
int focus_window(TERMINAL_WINDOW_T *window);

#endif // TERMINAL_WINDOW_H
