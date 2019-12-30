#include "play_mp4_adapter.h"


int play_mp4_adaper(void *this_media, const char *path)
{
    if( this_media == NULL || path == NULL)
    {
        return -1;
    }
    return play_mp4(path);
}
