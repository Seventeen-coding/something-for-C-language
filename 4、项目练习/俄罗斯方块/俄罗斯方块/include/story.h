#ifndef _GAME_STORY_H_
#define _GAME_STORY_H_

#include <stdlib.h>
#include "list.h"
#include "node.h"
#include "debug.h"
typedef struct{
    node_t *   current_node;
    node_list_node_t * node_head;
}story_t;

int story_begin(story_t *story);
int story_end(story_t *story);
int story_run(story_t *story);
int story_node_has_next(story_t *story);

#endif // GAME_STORY_H

