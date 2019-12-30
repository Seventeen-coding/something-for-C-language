#include "play_mp3_adapter.h"


int play_mp3_adaper(void *this_media, const char *path)
{
    if( this_media == NULL || path == NULL)
    {
        return -1;
    }
    return play_mp3(path);
}
