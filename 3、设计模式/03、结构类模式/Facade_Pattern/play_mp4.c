#include "play_mp4.h"

void  play_mp4(const char *path)
{
    if(path == NULL)
    {
        return ;
    }
    printf("%s : play %s \n",__FUNCTION__,path);
    return ;
}
