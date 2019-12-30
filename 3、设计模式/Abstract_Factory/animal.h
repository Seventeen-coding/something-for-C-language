#ifndef ANIMAL_H
#define ANIMAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*jump_func)(void *this_animal);
typedef void (*swim_func)(void *this_animal);
typedef void (*fly_func)(void *this_animal);

#define MAX_NAME_LEN 256

typedef struct _Animal{
    //member
    char  name[MAX_NAME_LEN];
    //method
    jump_func  jump;
    swim_func  swim;
    fly_func   fly;
}Animal;


int CreateAnimal(Animal *animal);

#endif // ANIMAL_H
