#include "subject.h"


static int   _notify(Subject * this_subject);
static int   _setcontent(Subject * this_subject,void *content);
static void  *_getcontent(Subject * this_subject);
static int   _register(Subject * this_subject,Observer *observer);

int inherit_Subject(Subject *subject)
{
    if(subject == NULL)
    {
        return -1;
    }
    memset(subject,0 , sizeof(Subject));
    subject->content = NULL;
    subject->updatecontent = NULL;
    subject->setcontent = _setcontent;
    subject->getcontent = _getcontent;
    subject->reg_observer = _register;
    subject->notifyAllObservers = _notify;
    return 0;
}



static int   _notify(Subject * this_subject)
{
    if(this_subject == NULL)
    {
        return -1;
    }
    int i;
    Observer *observer;
    for(i = 0 ; i < 10 ; i++)
    {
        observer = this_subject->observer_list[i];
        if(observer == NULL)
        {
            continue;
        }
        if(observer->update == NULL)
        {
            continue;
        }
        observer->update(observer,this_subject->content);
    }

    return 0;
}

static int   _setcontent(Subject * this_subject,void *content)
{
    if(this_subject == NULL)
    {
        return -1;
    }
    if(this_subject->updatecontent == NULL)
    {
        return -2;
    }
    this_subject->updatecontent(this_subject,content);
    this_subject->notifyAllObservers(this_subject);
    return 0;
}

static void  *_getcontent(Subject * this_subject)
{
    if(this_subject == NULL)
    {
        return NULL;
    }
    return this_subject->content;
}

static int   _register(Subject * this_subject,Observer *observer)
{
    if(this_subject == NULL)
    {
        return -1;
    }
    int i;
    for(i = 0 ; i < 10 ; i++)
    {
        if(this_subject->observer_list[i] == NULL)
        {
            this_subject->observer_list[i]  = observer;
            return 0;
        }
        else if(this_subject->observer_list[i] == observer)
        {
            return -2;
        }

    }

    return -3;
}
