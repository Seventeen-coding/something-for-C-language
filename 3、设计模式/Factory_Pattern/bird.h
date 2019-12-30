#ifndef BIRD_H
#define BIRD_H
\
#include "animal.h"


typedef struct _Bird
{
    Animal animal;
}Bird;

int CreateBird(Bird *bird);

#endif // BIRD_H
