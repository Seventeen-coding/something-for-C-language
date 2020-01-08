#include "play_avi.h"


void play_avi(const char *path)
{
    if(path == NULL)
    {
        return ;
    }
    printf("%s : play %s \n",__FUNCTION__,path);
    return ;
}
