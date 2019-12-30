#include "plant.h"

static void _flower_func(Plant *this_plant);
static void _pea_func(Plant *this_plant);

int CreatePlant(Plant *plant)
{
    //Plant *plant = (Plant *)malloc(sizeof(Plant));
    if(plant == NULL)
    {
        return -1;
    }
    memset(plant,0,sizeof(Plant));
    plant->pf_flower = (flower_func)_flower_func;
    plant->pf_pea = (pea_func)_pea_func;
    strcpy(plant->name ,"undefine");
    return 0;
}


static void _flower_func(Plant *this_plant)
{
    printf("%s : plant name is %s \n",__FILE__,this_plant->name);
}

static void _pea_func(Plant *this_plant)
{
    printf("%s : plant name is %s \n",__FILE__,this_plant->name);
}
