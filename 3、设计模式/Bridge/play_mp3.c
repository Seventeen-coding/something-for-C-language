#include "play_mp3.h"


int play_mp3(const char *path)
{
    if( path == NULL)
    {
        return -1;
    }
    printf("play %s \n",path);
    return 0;
}
