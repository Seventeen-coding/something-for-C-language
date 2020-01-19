
#include "game/game_debug.h"
#include "game/game_goble.h"
#include "map/game_map_init.h"
#include "map/game_map_config.h"

#define GAME_MAP_INIT_DEBUG
#ifdef GAME_MAP_INIT_DEBUG
//#define  MAP_INIT_DEBUG(msg...)   do{if(1)GAME_BASE_DEBUG("<map>"msg);}while(0)
#define MAP_INIT_DEBUG(msg...) GAME_BASE_DEBUG("<map init> " msg)
#define MAP_INIT_ERROR(msg...) GAME_BASE_DEBUG("<map init error> " msg)
#else
#define MAP_INIT_DEBUG(...)
#endif

int game_map_init()
{
    // if (welcome_map_init() != 0)
    //     MAP_INIT_ERROR("game_map_init\r\n");
    // if (welcome_movie_map_init() != 0)
    //     MAP_INIT_ERROR("welcome_movie_map_init\r\n");
    MAP_INIT_DEBUG("game_map_init  done\r\n");
    return 0;
}
