#include "wechat_official_account.h"

static int   _updatecontent(Subject * this_subject,void *content);

Official_account *Create_Official_account(Wechat_content *content)
{
    if(content == NULL)
    {
        return NULL;
    }
    Official_account *account =(Official_account *)malloc(sizeof(Official_account));
    if(account == NULL)
    {
        return NULL;
    }
    memset(account,0 ,sizeof(Official_account));
    do{
        if(inherit_Subject(&account->subject) != 0)
        {
            break;
        }
        memcpy(&account->content,content,sizeof(Wechat_content));

        account->subject.content = &account->content;
        account->subject.updatecontent = _updatecontent;
        return account;
    }while(0);

    free(account);
    return NULL;
}

static int   _updatecontent(Subject * this_subject,void *content)
{
    if(this_subject == NULL || content == NULL)
    {
        return -1;
    }
    Official_account tmp ;
    Official_account *account = (void *)this_subject - ((unsigned int)&tmp.subject - (unsigned int )&tmp);
    memcpy(&account->content,content,sizeof(Wechat_content));
    return 0;
}
