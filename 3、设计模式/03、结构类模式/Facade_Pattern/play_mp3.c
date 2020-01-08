#include "play_mp3.h"

void play_mp3(const char *path)
{
    if(path == NULL)
    {
        return ;
    }
    printf("%s : play %s \n",__FUNCTION__,path);
    return ;
}
