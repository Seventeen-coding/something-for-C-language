
#include "wechat_official_account.h"
#include "wechat_user.h"


void run();


int main(void)
{
    run();
    return 0;
}

//test
void run()
{
    Wechat_content edu_content = {EDUCATION, "this is education content"};
    Wechat_content mil_content = {MILITARY, "this is militry content"};
    Wechat_content rec_content = {RECREATION, "this is recreation content"};

    Official_account *education = Create_Official_account(&edu_content);
    Official_account *militry = Create_Official_account(&edu_content);
    Official_account *recreation = Create_Official_account(&edu_content);

    Wechat_user *user = Create_Wechat_user("seventeen");
    Wechat_user *teacher = Create_Wechat_user("teacher");
    Wechat_user *soldier = Create_Wechat_user("soldier");


    //teacher like education
    education->subject.reg_observer(education,&user->observer);
    education->subject.reg_observer(education,&teacher->observer);
    //soldier like militry
    militry->subject.reg_observer(militry,&soldier->observer);
    militry->subject.reg_observer(militry,&user->observer);

    recreation->subject.reg_observer(recreation,&user->observer);

    Wechat_content rec_content2 = {RECREATION, "this is another recreation content"};
    recreation->subject.setcontent(recreation,&rec_content2);

    Wechat_content mil_content2 = {MILITARY, "this is another militry content"};
    militry->subject.setcontent(militry,&mil_content2);

    Wechat_content edu_content2 = {EDUCATION, "this is another education content"};
    education->subject.setcontent(education,&edu_content2);
}
