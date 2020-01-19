
#include "game_story_list_init.h"

game_story_list_node_t *story_list = NULL;

int game_story_list_init()
{
//    game_story_t *story;
//    /*添加第一个情节welcome*/
//    story =  welcome_story_get();
//    if(story == NULL)   return GAME_INIT_ERROR;
//    /*有故事就开始创建表*/
//    story_list = list_create(story);
//    return GAME_INIT_FINISH;
}

game_story_list_node_t * game_story_list_get()
{
    int ret ;
    if(story_list == NULL)
    {
        ret = game_story_list_init();
        if(ret != GAME_INIT_FINISH)
            return NULL;
    }
    return story_list;
}
