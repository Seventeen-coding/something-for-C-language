#include "animal.h"

static void f_jump_func(ANIMAL_T *this);
static void f_swim_func(ANIMAL_T *this);
static void f_fly_func(ANIMAL_T *this);

ANIMAL_T *f_Create_ANIMAL_T(const char *name)
{
    int ret = 0;
    ANIMAL_T *animal = (ANIMAL_T *)malloc(sizeof(ANIMAL_T));
    if (animal == NULL)
    {
        return NULL;
    }
    ret = f_Create_ANIMAL_T_ex(animal, name);
    if (ret != 0)
    {
        free(animal);
        return NULL;
    }
    return animal;
}
int f_Create_ANIMAL_T_ex(ANIMAL_T *animal, const char *name)
{
    if (animal == NULL)
    {
        return -1;
    }
    if (name == NULL)
    {
        return -2;
    }
    memset(animal, 0, sizeof(ANIMAL_T));
    animal->f_swim = f_swim_func;
    animal->f_jump = f_jump_func;
    animal->f_fly = f_fly_func;
    strcpy(animal->name, name);
    return 0;
}

static void f_jump_func(ANIMAL_T *this)
{
    printf("%s : %s can't jump \n", __FILE__, this->name);
}

static void f_swim_func(ANIMAL_T *this)
{
    printf("%s : %s can't swim \n", __FILE__, this->name);
}

static void f_fly_func(ANIMAL_T *this)
{
    printf("%s : %s can't fly \n", __FILE__, this->name);
}
