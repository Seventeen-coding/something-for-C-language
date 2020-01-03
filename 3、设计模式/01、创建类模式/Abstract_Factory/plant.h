#ifndef PLANT_H
#define PLANT_H

#define MAX_NAME_LEN 256

typedef struct _PLANT_T
{
    //member
    char name[MAX_NAME_LEN];
    //method
    void (*f_flower)(struct _PLANT_T *this);
    void (*f_pea)(struct _PLANT_T *this);
} PLANT_T;

PLANT_T *f_Create_Plant(const char *name);
int f_Create_Plant_ex(PLANT_T *plant, const char *name);

#endif // PLANT_H
