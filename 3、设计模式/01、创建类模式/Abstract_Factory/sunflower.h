#ifndef __SUNFLOWER_H__
#define __SUNFLOWER_H__

#include "plant.h"

typedef struct _SUNFLOWER_T
{
       PLANT_T plant;
} SUNFLOWER_T;

SUNFLOWER_T *f_Create_SunFlower(const char *name);
int f_Create_SunFlower_ex(SUNFLOWER_T *sunflower, const char *name);

#endif // __SUNFLOWER_H__
