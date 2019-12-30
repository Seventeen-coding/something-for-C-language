#include "pea.h"

static void _pea_func(Pea *this_pea);

int CreatePea(Pea *pea)
{
    //Pea *pea = (Pea *)malloc(sizeof(Pea));
    if(pea == NULL)
    {
        return -1;
    }
    memset(pea , 0, sizeof(Pea));
    do
    {
        Plant * plant =( Plant *) pea;
        if(CreatePlant(plant) != 0)
        {
            break;
        }
        plant->pf_pea =(pea_func) _pea_func;
        strcpy(plant->name,"Pea");

        return 0;
    }while(0);

    return -1;
}


static void _pea_func(Pea *this_pea)
{
    printf("%s : Pea \n",__FILE__);
}
