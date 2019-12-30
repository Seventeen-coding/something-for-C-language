#include "play_mp4.h"

int  play_mp4(const char *path)
{
    if(path == NULL)
    {
        return -1;
    }
    printf("play %s \n",path);
    return 0;
}
