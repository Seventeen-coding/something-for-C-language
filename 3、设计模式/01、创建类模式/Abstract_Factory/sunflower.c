#include "sunflower.h"
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

static void f_sunflower_func(PLANT_T *this);

SUNFLOWER_T *f_Create_SunFlower(const char *name)
{
    int ret = 0;
    SUNFLOWER_T *sunflower = (SUNFLOWER_T *)malloc(sizeof(SUNFLOWER_T));
    if (sunflower == NULL)
    {
        return NULL;
    }
    ret = f_Create_SunFlower_ex(sunflower, name);
    if (ret != 0)
    {
        free(sunflower);
        return NULL;
    }

    return sunflower;
}
int f_Create_SunFlower_ex(SUNFLOWER_T *sunflower, const char *name)
{
    int ret = 0;
    if (sunflower == NULL)
    {
        return -1;
    }
    memset(sunflower, 0, sizeof(SUNFLOWER_T));
    PLANT_T *plant = &sunflower->plant;
    ret = f_Create_Plant_ex(plant, name);
    if (ret != 0)
    {
        return -2;
    }
    plant->f_flower = f_sunflower_func;
    strcpy(plant->name, "Sunflower");

    return 0;
}

static void f_sunflower_func(PLANT_T *this)
{
    printf("%s : sunflower \n", __FILE__);
}
