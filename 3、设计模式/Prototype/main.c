
#include "prototype.h"
#include <stdio.h>


int main(void)
{
    run();
    return 0;
}

//test
void run()
{
    User user;
    if(CreatUserbyNameAgePhoneAddress(&user,"seventeen",17,"119","I don't know") != 0)
    {
        return;
    }
    user.print_address(&user);
    user.print_age(&user);
    user.print_name(&user);
    user.print_phone(&user);

    User *user2 = user.clone(&user);
    if(user2 == NULL)
    {
        return ;
    }
    user2->print_address(user2);
    user2->print_age(user2);
    user2->print_name(user2);
    user2->print_phone(user2);

}
