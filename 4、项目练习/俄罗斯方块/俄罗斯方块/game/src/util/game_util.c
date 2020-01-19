
#include "game_util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <conio.h>
#include "list.h"
#include "terminal_util.h"
#include "util/log_util.h"

static KEY_REGISTER_NODE_T *key_register_callback_list = NULL;

static int run_key_monitor(GAME_UTIL_T *this);
static int f_Create_Game_Util_ex(GAME_UTIL_T *game_util);
static GAME_UTIL_T *f_Create_Game_Util(void);
static int register_key_callback(struct _GAME_UTIL_T *this, KEY_CALLBACK_FUNC callback);

static int register_key_callback(struct _GAME_UTIL_T *this, KEY_CALLBACK_FUNC callback)
{
    if (key_register_callback_list == NULL)
    {
        key_register_callback_list = list_create(NULL);
    }

    list_insert_end(key_register_callback_list, callback);

    return 0;
}

static int f_Create_Game_Util_ex(GAME_UTIL_T *game_util)
{
    if (game_util == NULL)
    {
        return -1;
    }
    game_util->run_key_monitor = run_key_monitor;
    game_util->register_key_callback = register_key_callback;
    return 0;
}
static GAME_UTIL_T *f_Create_Game_Util(void)
{
    GAME_UTIL_T *util = (GAME_UTIL_T *)malloc(sizeof(GAME_UTIL_T));
    if (util == NULL)
    {
        return NULL;
    }
    memset(util, 0, sizeof(GAME_UTIL_T));
    if (f_Create_Game_Util_ex(util) != 0)
    {
        free(util);
        return NULL;
    }
    return util;
}
GAME_UTIL_T *Get_Game_Util(void)
{
    static GAME_UTIL_T *util = NULL;

    if (util != NULL)
    {
        return util;
    }

    util = f_Create_Game_Util();
    if (util == NULL)
    {
        return NULL;
    }

    util->run_key_monitor(util);

    return util;
}
void *key_monitor_thread(void *arg)
{
    int ret = 0;
    char key = 0;
    GAME_UTIL_T *util = (GAME_UTIL_T *)arg;
    printf("key_monitor_thread is running\n");
    do
    {
        key = getch();
        {
            KEY_REGISTER_NODE_T *children_node = NULL;
            KEY_REGISTER_NODE_T *next_node = key_register_callback_list->next;
            KEY_CALLBACK_FUNC key_callback = NULL;
            while (next_node != NULL)
            {
                children_node = next_node;
                next_node = children_node->next;
                key_callback = (KEY_CALLBACK_FUNC)children_node->data;
                ret = key_callback(key);
                if (ret != 0)
                {
                    // log_error("ret %d\n", ret);
                    return NULL;
                }
            }
        }

    } while (1);
    return NULL;
}
static int run_key_monitor(GAME_UTIL_T *this)
{

    if (this == NULL)
    {
        return -1;
    }
    {
        static pthread_t *thread = NULL;
        if (thread != NULL)
        {
            // pthread_join(*thread, NULL);
            return 0;
        }

        int ret = 0;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        ret = pthread_create(thread, &attr, key_monitor_thread, (void *)this);
        if (ret != 0)
        {
            return -2;
        }
    }
    return 0;
}

int draw_point(int x, int y)
{
    return 0;
}
int draw_line(int x1, int y1, int x2, int y2)
{
    return 0;
}
int draw_rect(int x1, int y1, int x2, int y2)
{
    return 0;
}
int draw_line_ex(int x, int y, int w, int h)
{
    return 0;
}
int draw_rect_ex(int x, int y, int w, int h)
{
    return 0;
}
int print_text(int x, int y, const char *str)
{
    if (str == NULL)
    {
        return -1;
    }
    gotoXY(x, y);
    // SetColor(14);
    printf("%s", str);
    return 0;
}
