#ifndef WECHAT_OFFICIAL_ACCOUNT_H
#define WECHAT_OFFICIAL_ACCOUNT_H

#include "subject.h"
#include "wechat_content.h"


typedef struct _Official_account{
    Subject subject;
    //content
    Wechat_content content;
}Official_account;


Official_account *Create_Official_account(Wechat_content *content);

#endif // WECHAT_OFFICIAL_ACCOUNT_H
