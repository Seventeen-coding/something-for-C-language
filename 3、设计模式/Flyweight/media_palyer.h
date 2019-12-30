#ifndef MEDIA_PALYER_H
#define MEDIA_PALYER_H


#include "media_theme.h"
#include "play_format.h"
#include <stdlib.h>
#include <string.h>

typedef enum _media_type{
    AVI,
    MKV,
    MP4,
    MP3,
    WMA,
    UNKNOW
}media_type;

typedef void (*play_func)(void *this_player,const char *path);
typedef void (*about_func)(void *this_player);

typedef struct _Flyweight {
    play_func play;
    about_func about;
    //更多复杂的共享元素
    char version[MAX_LEN];
}Flyweight;

typedef struct _Media_Player{
    Flyweight   * media_interface;
    Media_Theme * theme;
}Media_Player;



Media_Player *create_media_player(Media_Theme *theme);

#endif // MEDIA_PALYER_H
