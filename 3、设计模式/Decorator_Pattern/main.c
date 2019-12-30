
#include "decorator_pattern.h"
#include <stdio.h>

void run();

int main(void)
{
    run();
    return 0;
}

//test
//目的 在原有基础上扩展函数
void run()
{
    Person person;
    if(CreatePerson(&person,"seventeen",17,"master") != 0 )
    {
        return ;
    }
    person.about(&person);
    if(CreatePersonDecorator(&person) != 0)//重写 about
    {
        return;
    }
    person.about(&person);

    return;
}
