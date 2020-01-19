
#include "game_node_init.h"
#include "game/game_goble.h"
#include "game/game_debug.h"

#define GAME_NODE_INIT_DEBUG
#ifdef   GAME_NODE_INIT_DEBUG
//#define  NODE_INIT_DEBUG(msg...)   do{if(1)GAME_BASE_DEBUG("<node>"msg);}while(0)
#define  NODE_INIT_DEBUG(msg...)   GAME_BASE_DEBUG("<node init> "msg)
#define  NODE_INIT_ERROR(msg...)   GAME_BASE_DEBUG("<node init error> "msg)
#else
#define  NODE_INIT_DEBUG(...)
#endif


int game_node_init()
{
//    if(welcome_node_init() != 0)  NODE_INIT_ERROR("welcome_story_init\r\n");
//    NODE_INIT_DEBUG("game_node_init done\r\n");
//    return GAME_NODE_INIT_OK;
}
