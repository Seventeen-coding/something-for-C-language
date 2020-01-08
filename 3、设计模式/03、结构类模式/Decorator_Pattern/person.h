#ifndef PERSON_H
#define PERSON_H

#include <stdio.h>
#include <string.h>
#define MAX_LEN 256

typedef int (*about_func)(struct _Person *this_person);
typedef int (*add_func)(struct _Person *this_person,struct _Person *add_person);
typedef int (*remove_func)(struct _Person *this_person,struct _Person *remove_person);
typedef struct _Person **(*getSubordinates_func)(struct _Person *this_person);

typedef struct _Person{
    char name[MAX_LEN];
    unsigned char age;
    char department[MAX_LEN];

    about_func about;
    add_func add;
    remove_func remove;
    getSubordinates_func getSubordinates;
    struct _Person *subordinates[MAX_LEN];
}Person;

int CreatePerson(Person * person,const char *name , unsigned char age,const char *department);

#endif // PERSON_H
