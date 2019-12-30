#include "chatroom.h"

static int _join(Chatroom *this_Chatroom,USER *user);

static int _notify(Chatroom *this_Chatroom, USER *user, const char *msg);

Chatroom *Create_Chatroom(void)
{
    Chatroom *chatroom = (Chatroom * ) malloc(sizeof(Chatroom));

    if(chatroom == NULL)
    {
        return NULL;
    }
    memset(chatroom,0,sizeof(USER));

    do{
        chatroom->join = _join;
        chatroom->notify = _notify;
        return chatroom;
    }while(0);
    free(chatroom);
    return NULL;
}

static int _join(Chatroom *this_Chatroom,USER *user)
{
    if(this_Chatroom == NULL || user == NULL)
    {
        return -1;
    }
    int i;

    for(i = 0 ; i < 10; i++)
    {
        if(this_Chatroom->user_list[i] == NULL)
        {
            this_Chatroom->user_list[i] = user;
            return 0;
        }
        else if(this_Chatroom->user_list[i] == user)
        {
            return -2;
        }
    }
    return -3;
}

static int _notify(Chatroom *this_Chatroom,USER *user,const char *msg)
{
    if(this_Chatroom == NULL || user == NULL)
    {
        return -1;
    }
    int i = 0;
    USER *tmp_user;
    for(i = 0 ; i < 10; i++)
    {
        tmp_user = this_Chatroom->user_list[i] ;
        if( tmp_user != NULL && this_Chatroom->user_list[i] != user)
        {
                user->sendmsg1(user,tmp_user,msg);
        }
    }
    return 0;
}
