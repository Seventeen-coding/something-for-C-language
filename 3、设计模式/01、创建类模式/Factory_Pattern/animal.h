#ifndef ANIMAL_H
#define ANIMAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 256

typedef struct _ANIMAL_T
{
    //member
    char name[MAX_NAME_LEN];
    //method
    void (*f_jump)(struct _ANIMAL_T *this_animal);
    void (*f_swim)(struct _ANIMAL_T *this_animal);
    void (*f_fly)(struct _ANIMAL_T *this_animal);
} ANIMAL_T;

ANIMAL_T *f_Create_ANIMAL_T(const char *name);
int f_Create_ANIMAL_T_ex(ANIMAL_T *animal, const char *name);
#endif // ANIMAL_H
