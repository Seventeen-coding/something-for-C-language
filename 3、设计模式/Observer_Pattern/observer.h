#ifndef OBSERVER_H
#define OBSERVER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int (*update_func)(void *this_observer, void * content);

typedef struct {
    update_func update;
}Observer;

int inherit_Oberver(Observer * observer);

#endif // OBSERVER_H
