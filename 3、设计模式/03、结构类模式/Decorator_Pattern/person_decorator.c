#include "person_decorator.h"

static int _decorator_about(Person *this_person);
static int (*_about)(Person *this_person);

int CreatePersonDecorator(Person *person)
{
    if(person == NULL)
    {
        return -1;
    }

    _about = person->about;
    person->about = _decorator_about;
    return 0;
}

static int _decorator_about(Person *this_person)
{
    printf("------------------------\n");
    _about(this_person);
    printf("_decorator_about \n");
    printf("------------------------\n");
}


