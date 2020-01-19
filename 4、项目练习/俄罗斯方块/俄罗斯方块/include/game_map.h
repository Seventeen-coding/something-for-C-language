#ifndef _GAME_MAP_H_
#define _GAME_MAP_H_

//这里只是作为一种操作流程的设计
//例如进入一个画面先 init 然后show 然后select等等
//具体是看游戏的操作模式

typedef int (*m_handle)(void);
typedef int (*m_init_handle)(void);
typedef int (*m_show_handle)(void);
typedef int (*m_select_handle)(char);

typedef struct map_t
{
    m_handle map_handle;
    m_init_handle _init;
    m_show_handle _show;
    m_select_handle _select;

    struct map_t *callback_map;
    struct map_t *next_map;
} map_t;

int map_begin(map_t *map);
int map_end(map_t *map);
int map_run(map_t *map);

///int map_result();

#endif // GAME_MAP_H
