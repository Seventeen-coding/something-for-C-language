#ifndef MEDIA_H
#define MEDIA_H

#include <stdio.h>

#include "play_func.h"

typedef struct _Media{
    play_func play;
}Media;

int CreatMedia(Media *media,play_func play);

#endif // MEDIA_H
