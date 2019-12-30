#include "duck.h"


static void _swim_func(Duck *this_duck);

int CreateDuck(Duck *duck)
{
    //Duck *Duck = (Duck *)malloc(sizeof(Duck));
    if(duck == NULL)
    {
        return -1;
    }
    memset(duck , 0, sizeof(Duck));
    do
    {
        Animal * animal =( Animal *) duck;
        if(CreateAnimal(animal) != 0)
        {
            break;
        }
        animal->swim =(swim_func) _swim_func;
        strcpy(animal->name,"Duck");

        return 0;
    }while(0);

    return -1;
}


static void _swim_func(Duck *this_duck)
{
    Animal *animal = (Animal *)this_duck;
    //printf("%s : %s swim \n",__FILE__,this_duck->animal.name);
    printf("%s : %s swim \n",__FILE__,animal->name);
}
