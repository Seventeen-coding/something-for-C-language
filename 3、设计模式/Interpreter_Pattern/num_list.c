#include "num_list.h"

int add_node_to_list(number_list_node * head_node, number_list_node * node)
{
    if(node == NULL)
    {
        return -1;
    }

    if(head_node == NULL)
    {
        node->next_number_node = NULL;
        head_node = node;
        return 0;
    }

    number_list_node * tmp_node = head_node;
    while(tmp_node->next_number_node != NULL)
    {
        tmp_node = tmp_node->next_number_node;
    }
    node->next_number_node = NULL;
    tmp_node->next_number_node = node;

    return 0;
}

