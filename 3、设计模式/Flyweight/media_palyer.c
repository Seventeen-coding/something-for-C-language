#include "media_palyer.h"

static void _play(Media_Player *this_player,const char *path);

static void _about(Media_Player *this_player);

Media_Player *create_media_player(Media_Theme *theme)
{
    Media_Player *player = NULL;

    if(theme == NULL)
    {
        return NULL;
    }
    do
    {
        player = (Media_Player *)malloc(sizeof(Media_Player));
        if(player == NULL)
        {
            break;
        }
        player->theme = theme;
        //interface = (Media_Interface *)malloc(sizeof(Media_Interface));
        //以下是共享部分
        static Flyweight * media_interface = NULL;
        if(media_interface != NULL)
        {
            //共享部分无需再次创建
            player->media_interface = media_interface;
            return player;
        }

        media_interface = malloc(sizeof(Flyweight));
        if(media_interface == NULL)
        {
            break;
        }
        //第一次创建共享部分数据 （仅仅创建一次 给每一个创建media对象使用）
        //flyweight = create_flyweight();
        media_interface->play = (play_func) _play;
        media_interface->about = (about_func) _about;
        strcpy(media_interface->version,"1.0.0");
        player->media_interface = media_interface;
        return player;
    }while(0);
    //走到这里说明创建失败
    free(theme);
    return NULL;
}

static void _about(Media_Player *this_player)
{
    if(this_player == NULL)
    {
        return;
    }
    printf(" font :%s , skin :%s version: %s\n",this_player->theme->font,this_player->theme->skin,this_player->media_interface->version);
}

static void _play(Media_Player *this_player,const char *path)
{
    media_type type;
    if(path == NULL || this_player == NULL)
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


