#include "observer.h"

int inherit_Oberver(Observer *observer)
{
    if(observer == NULL)
    {
        return -1;
    }

    observer->update = NULL;
    return 0;
}
