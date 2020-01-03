#ifndef PEA_H
#define PEA_H

#include "plant.h"

typedef struct _PEA_T
{
    PLANT_T plant;
} PEA_T;

PEA_T *f_Create_Pea(const char * name);
int f_Create_Pea_ex(PEA_T *pea,const char * name);

#endif // PEA_H
