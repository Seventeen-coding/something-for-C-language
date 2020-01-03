#include "plant.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void f_flower(PLANT_T *this);
static void f_pea(PLANT_T *this);

PLANT_T *f_Create_Plant(const char *name)
{
    int ret = 0;
    PLANT_T *plant = (PLANT_T *)malloc(sizeof(PLANT_T));
    if (plant == NULL)
    {
        return NULL;
    }
    ret = f_Create_Plant_ex(plant, name);
    if (ret != 0)
    {
        free(plant);
        return NULL;
    }
    return plant;
}
int f_Create_Plant_ex(PLANT_T *plant, const char *name)
{
    int ret = 0;
    if (plant == NULL)
    {
        return -1;
    }
    memset(plant, 0, sizeof(PLANT_T));
    ret = f_Create_Plant_ex(plant, name);
    if (ret != 0)
    {
        return -2;
    }
    plant->f_flower = f_flower;
    plant->f_pea = f_pea;
    strcpy(plant->name, name);
    return 0;
}

static void f_flower(PLANT_T *this)
{
    printf("%s : plant name is %s \n", __FILE__, this->name);
}

static void f_pea(PLANT_T *this)
{
    printf("%s : plant name is %s \n", __FILE__, this->name);
}
