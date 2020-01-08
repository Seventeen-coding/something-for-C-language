#ifndef NUMBER_EXPRESSION_H
#define NUMBER_EXPRESSION_H

#include "expression.h"

typedef struct _number_expression{
    int number;
    Expression_interface exp;
}number_expression;

number_expression *Create_number_expression(void);

#endif // NUMBER_EXPRESSION_H
