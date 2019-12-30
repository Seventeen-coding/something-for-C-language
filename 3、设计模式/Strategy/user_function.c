#include "user_function.h"

#include "normal_discounts_strategy.h"
#include "normal_sign_up_strategy.h"
#include "super_sign_up_strategy.h"
#include "vip_discounts_strategy.h"


int Upgrade_user(User *this_user, Level level)
{
    if(this_user == NULL)
    {
        return -1;
    }
    switch(level)
    {
    case NORMAL_USER:
        this_user->sign_up_fee = normal_Sign_up_fee_func;
        this_user->discounts = normal_Discounts_func;
        break;
    case VIP_USER:
        this_user->sign_up_fee = normal_Sign_up_fee_func;
        this_user->discounts = vip_Discounts_func;
        break;
    case SUPER_VIP_USER:
        this_user->sign_up_fee = super_Sign_up_fee_func;
        this_user->discounts = vip_Discounts_func;
        break;
    default:
        return -2;
    }
    return 0;
}
