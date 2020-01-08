#include "default_discounts_strategy.h"
#include "normal_discounts_strategy.h"


int default_Discounts_func(USER_T *this_user)
{
    return normal_Discounts_func(this_user);
}
