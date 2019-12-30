#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void *(*interpret_func)(void *data,int *interpret_result);

typedef struct _Expression_interface{
    int interpret_result;
    interpret_func  interpret;
}Expression_interface;


#endif // EXPRESSION_H
