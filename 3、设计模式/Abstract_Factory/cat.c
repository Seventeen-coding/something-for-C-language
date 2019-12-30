#include "cat.h"

static void _jump_func(Cat *this_cat);

int CreateCat(Cat *cat)
{
    //Cat *cat = (Cat *)malloc(sizeof(Cat));
    if(cat == NULL)
    {
        return -1;
    }
    memset(cat , 0, sizeof(Cat));
    do
    {
        Animal * animal =( Animal *) cat;
        if(CreateAnimal(animal) != 0)
        {
            break;
        }
        animal->jump =(jump_func) _jump_func;
        strcpy(animal->name,"Cat");

        return 0;
    }while(0);

    return -1;
}


static void _jump_func(Cat *this_cat)
{
    printf("%s : cat jump \n",__FILE__);
}
