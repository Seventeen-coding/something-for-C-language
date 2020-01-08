#ifndef ADD_EXPRESSION_H
#define ADD_EXPRESSION_H

#include "number_expression.h"

typedef struct _add_expression{
    int other_data;
    Expression_interface exp;
}add_expression;

add_expression *Create_add_expression(void);



#endif // ADD_EXPRESSION_H
