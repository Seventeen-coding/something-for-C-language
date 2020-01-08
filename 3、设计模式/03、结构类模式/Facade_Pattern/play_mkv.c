#include "play_mkv.h"

void  play_mkv(const char *path)
{
    if(path == NULL)
    {
        return ;
    }
    printf("%s : play %s \n",__FUNCTION__,path);
    return ;
}
