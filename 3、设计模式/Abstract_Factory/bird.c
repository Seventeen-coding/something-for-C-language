#include "bird.h"

static void _fly_func(Bird *this_bird);

int CreateBird(Bird *bird)
{
    //Bird *Bird = (Bird *)malloc(sizeof(Bird));
    if(bird == NULL)
    {
        return -1;
    }
    memset(bird , 0, sizeof(Bird));
    do
    {
        Animal * animal =( Animal *) bird;
        if(CreateAnimal(animal) != 0)
        {
            break;
        }
        animal->fly =(fly_func) _fly_func;
        strcpy(animal->name,"Bird");

        return 0;
    }while(0);

    return -1;
}


static void _fly_func(Bird *this_bird)
{
    printf("%s : Bird fly \n",__FILE__);
}
