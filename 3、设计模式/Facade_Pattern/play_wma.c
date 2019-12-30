#include "play_wma.h"


void play_wma(const char *path)
{
    if(path == NULL)
    {
        return ;
    }
    printf("%s : play %s \n",__FUNCTION__,path);
    return ;
}
