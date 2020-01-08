
#include "strategy_pattern.h"

void run();

int main(void)
{
    run();
    return 0;
}

void run()
{
    USER_T *user = Create_User("seventeen","account","password",NORMAL_USER);
    if(user == NULL)
    {
        return ;
    }
    printf("normal user cost : %d\n",user->Cost(user));
    Upgrade_user(user,VIP_USER);
    printf("vip user cost : %d\n",user->Cost(user));
    Upgrade_user(user,SUPER_VIP_USER);
    printf("super vip user cost : %d\n",user->Cost(user));
    Upgrade_user(user,NORMAL_USER);
    printf("normal user cost : %d\n",user->Cost(user));
}
