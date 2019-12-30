#include "animal.h"


static void _jump_func(Animal *this_animal);
static void _swim_func(Animal *this_animal);
static void _fly_func(Animal *this_animal);

int CreateAnimal(Animal *animal)
{
    //Animal *animal = (Animal *)malloc(sizeof(Animal));
    if(animal == NULL)
    {
        return -1;
    }
    memset(animal,0,sizeof(Animal));
    animal->swim = (swim_func)_swim_func;
    animal->jump = (jump_func)_jump_func;
    animal->fly = (fly_func)_fly_func;
    strcpy(animal->name ,"undefine");
    return 0;
}

static void _jump_func(Animal *this_animal)
{
    printf("%s : %s can't jump \n",__FILE__,this_animal->name);
}

static void _swim_func(Animal *this_animal)
{
    printf("%s : %s can't swim \n",__FILE__,this_animal->name);
}

static void _fly_func(Animal *this_animal)
{
    printf("%s : %s can't fly \n",__FILE__,this_animal->name);
}

