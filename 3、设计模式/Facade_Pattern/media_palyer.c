#include "media_palyer.h"

static void _play(const char *path);

Media_Interface *get_media_interface()
{
    static Media_Interface *interface = NULL;

    if(interface != NULL)
    {
        return interface;
    }

    interface = (Media_Interface *)malloc(sizeof(Media_Interface));
    interface->play = _play;
    return interface;
}

static void _play(const char *path)
{
    media_type type;
    if(path == NULL)
    {
        return;
    }
    if(strstr(path,"avi") != NULL)
    {
        type = AVI;
    }
    else if(strstr(path,"mp3") != NULL)
    {
        type = MP3;
    }
    else if(strstr(path,"mkv") != NULL)
    {
        type = MKV;
    }
    else if(strstr(path,"mp4") != NULL)
    {
        type = MP4;
    }
    else if(strstr(path,"wma") != NULL)
    {
        type = WMA;
    }
    else
    {
        type = UNKNOW;
    }


    switch (type) {
    case AVI:
        play_avi(path);
        break;
    case MKV:
        play_mkv(path);
        break;
    case MP4:
        play_mp4(path);
        break;
    case MP3:
        play_mp3(path);
        break;
    case WMA:
        play_wma(path);
        break;
    case UNKNOW:
    default:
        printf("unknow type \n");
        break;
    }

}

