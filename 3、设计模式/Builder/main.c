
#include "userbuilder.h"
#include <stdio.h>


int main(void)
{
    run();
    return 0;
}

//test
void run()
{
    //第一种
    printf("===============user1=============== \n");
    User user ;
    if(CreatUser(&user) != 0)
    {
        return;
    }
    user.age = 10;
    user.print_age(&user);
    //第二种
    printf("===============user2=============== \n");
    User user2;
    if(CreatUserbyNameAgePhoneAddress(&user2,"Seventeen",10,"110","world"));
    user2.print_address(&user2);
    user2.print_age(&user2);
    user2.print_name(&user2);
    user2.print_phone(&user2);
    //第三种
    printf("===============user3=============== \n");
    UserBuilder *builder = CreatUserBuilder();
    User *user3 = builder->address(builder,"world6")->age(builder,18)->phone(builder,"120")->name(builder,"seventeen")->build(builder);
    user3->print_address(user3);
    user3->print_age(user3);
    user3->print_name(user3);
    user3->print_phone(user3);

    return 0;
}
