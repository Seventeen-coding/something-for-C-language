#ifndef GAME_GOBLE_H
#define GAME_GOBLE_H



#include "story.h"
#include "node.h"
#include "map.h"
#include "window.h"

typedef enum {

    GAME_EXIT = -2,// -2
    GAME_ERROR = -1,//-1
    GAME_OVER = 0,// 0
    GAME_START,   //1
    GAME_STOP,//  2
    GAME_RUNNING,//   3
    GAME_MAP_INIT_ERROR,// 4
    GAME_MAP_INIT_OK,// 5
    GAME_NODE_INIT_ERROR,//6
    GAME_NODE_INIT_OK,//7
    GAME_STORY_INIT_ERROR,//8
    GAME_STORY_INIT_OK,//9
    GAME_INIT_ERROR,//10
    GAME_INIT_FINISH,//11
    GAME_CONFIG_ERROR,//12
    GAME_CONFIG_FINISH,//13
    //由于在这里开始之前配置完毕 在这里以后都要确保是正确没有error
    GAME_MAP_FINISH,//    14
    GAME_NODE_FINISH,//15
    GAME_STORY_FINISH,//16
    GAME_STORY_LIST_FINISH,//17
    GAME_FINISH,//18
    GAME_TEST
}status_t;

typedef enum {
    GAME_RET_ERROR = -1,
    GAME_RET_OK
}ret_t;
/*动态最好用指针 */

struct {
    status_t current_status;
    TERMINAL_WINDOW_T *current_window ; //focus
    story_list_node_t  *story_list;

    /*以下部分只是为了方便调用*/
    map_t    *current_map;
    node_t  *current_node;
    story_t  *current_story;
}gobel_config;


int init();
int config();
int run();
int start();
int stop();
int end();

int  goble_get();

//status
int status_get();
int status_set();

//story node map set
int story_set(story_t *story);

//int next_story_set(map_t *story,map_t *story);

int node_set(node_t *node);

//int next_node_set(map_t *node,map_t *next_node);

int map_set(map_t *map);
int next_map_set(map_t *map, map_t *next_map);
int callback_map_set(map_t *map,map_t *callback_map);
#endif // GAME_GOBLE_H

