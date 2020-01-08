#include "user.h"

static const char *_getname(USER_T *this_user);
static int _setname(USER_T *this_user, char *name);

static int _sendmsg1(USER_T *this_user, USER_T *send_to_user, const char *msg);
static int _receivemsg1(USER_T *this_user, const char *msg);

USER_T *f_Create_User(const char *name)
{
    if (name == NULL)
    {
        return NULL;
    }
    USER_T *user = (USER_T *)malloc(sizeof(USER_T));

    if (user == NULL)
    {
        return NULL;
    }
    memset(user, 0, sizeof(USER_T));

    do
    {
        user->getname = _getname;
        user->setname = _setname;
        user->sendmsg1 = _sendmsg1;
        user->receivemsg1 = _receivemsg1;
        strcpy(user->name, name);
        return user;
    } while (0);
    free(user);
    return NULL;
}

static const char *_getname(USER_T *this_user)
{
    if (this_user == NULL)
    {
        return NULL;
    }
    return this_user->name;
}

static int _setname(USER_T *this_user, char *name)
{
    if (this_user == NULL)
    {
        return -1;
    }
    strcpy(this_user->name, name);
    return 0;
}

static int _sendmsg1(USER_T *this_user, USER_T *send_to_user, const char *msg)
{
    if (this_user == NULL || send_to_user == NULL || msg == NULL)
    {
        return -1;
    }
    return send_to_user->receivemsg1(send_to_user, msg);
}
static int _receivemsg1(USER_T *this_user, const char *msg)
{
    if (this_user == NULL || msg == NULL)
    {
        return -1;
    }
    printf("%s get msg:%s \n", this_user->name, msg);
    return 0;
}
