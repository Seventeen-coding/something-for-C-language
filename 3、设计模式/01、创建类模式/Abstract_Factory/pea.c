#include "pea.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void f_pea_func(PLANT_T *this);

int f_Create_Pea_ex(PEA_T *pea, const char *name)
{
    if (pea == NULL)
    {
        return -1;
    }
    memset(pea, 0, sizeof(PEA_T));

    PLANT_T *plant = (PLANT_T *)&pea->plant;
    if (f_Create_Plant_ex(plant,name) != 0)
    {
        return -2;
    }
    plant->f_pea = f_pea_func;
    strcpy(plant->name, "PEA_T");

    return 0;
}
PEA_T *f_Create_Pea(const char *name)
{
    int ret = 0;
    PEA_T *pea = (PEA_T *)malloc(sizeof(PEA_T));
    if (pea == NULL)
    {
        return NULL;
    }
    ret = f_Create_Pea_ex(pea, name);
    if (ret != 0)
    {
        free(pea);
        return NULL;
    }

    return pea;
}

static void f_pea_func(PLANT_T *this)
{
    printf("%s : PEA_T \n", __FILE__);
}
