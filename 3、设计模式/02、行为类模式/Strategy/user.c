#include "user.h"

extern int Upgrade_user(USER_T *this_user, Level level);

static int _cost_func(USER_T *this_user);

USER_T *Create_User(const char name[], const char account[], const char password[], Level level)
{

    if(name == NULL || account == NULL || password == NULL)
    {
        return NULL;
    }
    USER_T *user = (USER_T *)malloc(sizeof(USER_T));

    if(user == NULL)
    {
        return NULL;
    }
    do
    {
        strncpy(user->name,name,10);
        strncpy(user->account,account,10);
        strncpy(user->password,password,10);

        if(Upgrade_user(user,level) != 0)
        {
            break;
        }
        user->Cost = _cost_func;
        return user;
    }while(0);

    free(user);

    return NULL;
}

static int _cost_func(USER_T *this_user)
{
    if(this_user == NULL)
    {
        return -1;
    }
    int fee = 0;
    fee +=  this_user->sign_up_fee(this_user);
    fee +=  this_user->discounts(this_user);
    return  fee;
}
