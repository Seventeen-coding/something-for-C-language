#ifndef __BIRD_H__
#define __BIRD_H__

#include "animal.h"

typedef struct _BIRD_T
{
    ANIMAL_T animal;
} BIRD_T;

BIRD_T *f_Create_Bird(const char *name);
int f_Create_Bird_ex(BIRD_T *bird, const char *name);
#endif // __BIRD_H__
