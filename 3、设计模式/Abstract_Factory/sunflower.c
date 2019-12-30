#include "sunflower.h"

static void _sunflower_func(SunFlower *this_sunflower);

int CreateSunFlower(SunFlower *sunflower)
{
    //sunflower *sunflower = (sunflower *)malloc(sizeof(sunflower));
    if(sunflower == NULL)
    {
        return -1;
    }
    memset(sunflower , 0, sizeof(SunFlower));
    do
    {
        Plant * plant =( Plant *) sunflower;
        if(CreatePlant(plant) != 0)
        {
            break;
        }
        plant->pf_flower =(flower_func) _sunflower_func;
        strcpy(plant->name,"Sunflower");

        return 0;
    }while(0);

    return -1;
}


static void _sunflower_func(SunFlower *this_sunflower)
{
    printf("%s : sunflower \n",__FILE__);
}

