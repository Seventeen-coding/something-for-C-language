#include "media.h"

int CreatMedia(Media *media, play_func play)
{
    if(media == NULL || play == NULL)
    {
        return -1;
    }

    media->play = play;

    return 0;
}
