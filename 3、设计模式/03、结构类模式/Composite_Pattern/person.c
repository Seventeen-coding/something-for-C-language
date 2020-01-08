#include "person.h"


static int _about(Person *this_person);
static int _add(Person *this_person, Person *add_person);
static int _remove(Person *this_person, Person *remove_person);
Person ** _getSubordinates(struct _Person *this_person);

int CreatPerson(Person *person, const char *name, unsigned char age, const char *department)
{
    if(person == NULL  || department == NULL || name == NULL)
    {
        return -1;
    }
    memset(person,0, sizeof(Person));

    strcpy(person->name,name);
    strcpy(person->department,department);
    person->age = age;

    person->add = _add;
    person->about = _about;
    person->remove = _remove;
    person->getSubordinates = _getSubordinates;
}
static int _about(Person *this_person)
{
    if(this_person == NULL )
    {
        return -1;
    }
    printf("about %s | ",this_person->name);
    printf("age : %d | ",this_person->age);
    printf("department : %s\n",this_person->department);
    return 0;
}

static int _add(Person *this_person, Person *add_person)
{
    int i;
    for(i = 0 ; i < MAX_LEN;i++ )
    {
        if(this_person->subordinates[i] == NULL )
        {
            this_person->subordinates[i] = add_person;
            return 0;
        }
    }
    return -1;
}

static int _remove(Person *this_person, Person *remove_person)
{
    int i;
    for(i = 0 ; i < MAX_LEN;i++ )
    {
        if(this_person->subordinates[i] == remove_person )
        {
            this_person->subordinates[i] = NULL;
            return 0;
        }
    }
    return -1;
}
Person ** _getSubordinates(struct _Person *this_person)
{
    return this_person->subordinates;
}
