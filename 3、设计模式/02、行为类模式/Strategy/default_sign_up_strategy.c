#include "default_sign_up_strategy.h"

#include "normal_sign_up_strategy.h"

int default_Sign_up_fee_func(USER_T *this_user)
{
    return normal_Sign_up_fee_func(this_user);
}
