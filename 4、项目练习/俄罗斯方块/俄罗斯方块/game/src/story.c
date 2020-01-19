#include "story.h"
#include "goble.h"

story_list_node_t *story_list = NULL;

story_list_node_t *setup_config_story()
{
    story_list_node_t   *list_node = story_list;
    story_list_node_t  *next  = list_node->next;
    /*reload story*/
    while(next != NULL)
    {
        remove_story(list_node->data);
        list_node = next;
        next  = list_node->next;
    }
    return story_list;
}
#if 0
int story_init(story_list_node_t *list)
{
    if(list == NULL)    list = (story_list_node_t *)malloc(sizeof(story_list_node_t));

    /*最理想的做法就是用一个不需要语法的规则去设计每一个故事
            这样日后维护工作可以交给其他人了*/
    setup_config_story(list);
    return    0;
}
#endif

int  remove_story( story_t  * stoty)
{


}
int story_begin(story_t  * story)
{
    GAME_BASE_DEBUG("begin_story: %0x\r\n",story);

}
int story_end(story_t * story)
{
    GAME_BASE_DEBUG("end_story: %0x\r\n",story);
    node_t *next_node = story_node_has_next(story);
    //完成了所有故事 游戏结束
    if(next_node == NULL)  return GAME_STORY_FINISH;
    story->current_node = next_node;
    return GAME_RUNNING;
}

int story_node_has_next(story_t * story)
{
    node_list_node_t   *node =  list_find_by_data(story->node_head,story->current_node)->next;
    if(node == NULL) return GAME_STORY_FINISH;
    story->current_node = node->data;
    return GAME_RUNNING;
}

int story_run(story_t *story)
{
    int status = status_get();
    //story_begin(story);
    while(status != GAME_OVER &&  status != GAME_STORY_FINISH)
    {
        status = node_run(story->current_node);
        // if(status == GAME_OVER) break;
        //status = story_node_has_next(story) ;
        status_set(status);
    }
    //story_end(story);
    return status;
}

