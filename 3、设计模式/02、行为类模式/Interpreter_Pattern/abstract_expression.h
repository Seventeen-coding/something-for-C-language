#ifndef ABSTRACT_EXPRESSION_H
#define ABSTRACT_EXPRESSION_H
#include "log_util.h"
typedef int (*F_INTERPRET_T)(void *this, const char *context, int *interpret_result);
typedef struct _ABSTRACT_EXPRESSION_T
{
    int interpret_result;
    F_INTERPRET_T f_interpret;
} ABSTRACT_EXPRESSION_T;

int f_Create_Abstract_Expression_ex(ABSTRACT_EXPRESSION_T *expression);
#endif // ABSTRACT_EXPRESSION_H
