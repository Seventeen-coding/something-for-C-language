#ifndef NUM_LIST_H
#define NUM_LIST_H

#include <stdio.h>

struct _number_list_node{
    int number;
    struct _number_list_node *next_number_node;
};
typedef struct _number_list_node number_list_node;

int add_node_to_list(number_list_node*head_node, number_list_node * node);

#endif // NUM_LIST_H
