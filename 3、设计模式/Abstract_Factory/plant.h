#ifndef PLANT_H
#define PLANT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*flower_func)(void *this_plant);
typedef void (*pea_func)(void *this_plant);

#define MAX_NAME_LEN 256

typedef struct _Plant{
    //member
    char  name[MAX_NAME_LEN];
    //method
    flower_func  pf_flower;
    pea_func     pf_pea;
}Plant;

int CreatePlant(Plant *plant);

#endif // PLANT_H
