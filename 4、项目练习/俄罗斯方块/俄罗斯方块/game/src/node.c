
#include "node.h"
#include "goble.h"

int node_run(node_t *node)
{
    int status = status_get();
    node_begin(node);
    while(status  != GAME_NODE_FINISH && status != GAME_OVER)
    {
        status =  map_run(node->current_map);
       //if(status == GAME_OVER) break;
        //status = node_map_has_next(node) ;
        status_set(status);
    }
    node_end(node);
    return status;      //finish or game over
}

int node_begin(node_t *node)
{
    GAME_BASE_DEBUG("current_node : %0x\r\n",node);
    return GAME_RUNNING;
}

int node_end(node_t *node)
{
    return GAME_RUNNING;
}

int node_map_has_next(node_t *node)
{
    map_list_node_t   *map_node =  list_find_by_data(node->map_head,node->current_map);
    if(map_node->next == NULL) return GAME_NODE_FINISH;
    node->current_map = map_node->next->data;
    return GAME_RUNNING;
}
