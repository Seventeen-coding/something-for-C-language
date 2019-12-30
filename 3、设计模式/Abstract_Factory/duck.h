#ifndef DUCK_H
#define DUCK_H

#include "animal.h"


typedef struct _Duck
{
    Animal animal;
}Duck;

int CreateDuck(Duck *duck);

#endif // DUCK_H
