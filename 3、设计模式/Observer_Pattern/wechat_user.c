#include "wechat_user.h"

//private
#include "wechat_content.h"

static int _update(Observer *this_observer, Wechat_content * content);

Wechat_user *Create_Wechat_user(const char *name)
{
    if(name == NULL)
    {
        return NULL;
    }

    Wechat_user *user = (Wechat_user *) malloc(sizeof(Wechat_user));

    if(user == NULL)
    {
        return NULL;
    }
    memset(user,0,sizeof(Wechat_user));
    do{
        inherit_Oberver(&user->observer);
        strcpy(user->name,name);
        user->observer.update = _update;
        return user;
    }while(0);

    free(user);
    return NULL;
}



static int _update(Observer *this_observer, Wechat_content * content)
{
    if(this_observer == NULL)
    {
        return -1;
    }
    if(content == NULL)
    {
        return 0;
    }
    Wechat_user tmp;

    Wechat_user *this_user = (void *)this_observer - ((unsigned int)&(tmp.observer) - (unsigned int )&tmp);

    printf("%s %d %s\n",this_user->name,content->type,content->content);

    return 0;
}
