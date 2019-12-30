#ifndef SUBJECT_H
#define SUBJECT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "observer.h"

typedef int   (*notify_func)(void * this_subject);
typedef int   (*setcontent_func)(void * this_subject,void *content);
typedef int   (*updatecontent_func)(void * this_subject,void *content);
typedef void *(*getcontent_func)(void * this_subject);
typedef int   (*register_func)(void * this_subject,Observer *observer);

typedef struct {
    Observer *observer_list[10];
    const void *content;
    setcontent_func setcontent;
    getcontent_func getcontent;
    updatecontent_func updatecontent;
    register_func   reg_observer;
    notify_func     notifyAllObservers;
}Subject;

int inherit_Subject(Subject *subject);

#endif // SUBJECT_H
