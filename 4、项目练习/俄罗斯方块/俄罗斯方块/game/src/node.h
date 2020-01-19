#ifndef GAME_NODE_H
#define GAME_NODE_H

#include "list.h"
#include "map.h"

typedef struct{
    map_list_node_t  *map_head;
    map_t*  current_map;
}node_t;

int node_begin(node_t *node);
int node_end(node_t *node);
int node_run(node_t *node);
int node_map_has_next(node_t *node);


#endif // GAME_NODE_H

