
#include "game_story_init.h"
#include "game/game_debug.h"
#include "game/game_goble.h"
#include "story/game_story_config.h"

#define GAME_STORY_INIT_DEBUG
#ifdef   GAME_STORY_INIT_DEBUG
//#define  STORY_INIT_DEBUG(msg...)   do{if(1)GAME_BASE_DEBUG("<story>"msg);}while(0)
#define  STORY_INIT_DEBUG(msg...)   GAME_BASE_DEBUG("<story init> "msg)
#define   STORY_INIT_ERROR(msg...)   GAME_BASE_DEBUG("<story init error> "msg)
#else
#define  STORY_INIT_DEBUG(...)
#endif


int game_story_init()
{
//    if(welcome_story_init() != 0)  STORY_INIT_ERROR("welcome_story_init\r\n");
//    STORY_INIT_DEBUG("game_story_init done\r\n");
//    return GAME_STORY_INIT_OK;
}
