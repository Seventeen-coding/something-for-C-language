#include "game_map.h"
#include "goble.h"
#include "key.h"   //以后替换为control
#include "debug.h"
//外后需要用handle处理更好扩展
int map_run(map_t *map)
{
    int status = GAME_RUNNING;
    status_set(status);
    map_begin(map);
    while(status  != GAME_MAP_FINISH && status != GAME_OVER)
    {
        map->_show();
        status = map->_select(get_key());   //这里写得不好
        status_set(status);
    }
    map_end(map);
    return status;
}
int map_begin(map_t *map)
{
    GAME_BASE_DEBUG("current  map : %0x\r\n",map);


    map->next_map = NULL;
    return 0;// GAME_BEGIN_FINISH;
}

int map_end(map_t *map)
{
    int status = status_get();
    status_set(status);

    if(status != GAME_MAP_FINISH)  return status;

    if(map->next_map == NULL)
    {
        GAME_BASE_DEBUG("<map>error : next_map : NULL");
        status = GAME_ERROR;
        return status;
    }
    map_set(map->next_map);
    //map->callback_map = NULL;
    return status;
}

