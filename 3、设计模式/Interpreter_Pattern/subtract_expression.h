#ifndef SUBTRACT_EXPRESSION_H
#define SUBTRACT_EXPRESSION_H


#include "number_expression.h"

typedef struct _subtract_expression{
    int other_data;
    Expression_interface exp;
}subtract_expression;

subtract_expression *Create_subtract_expression(void);


#endif // SUBTRACT_EXPRESSION_H
