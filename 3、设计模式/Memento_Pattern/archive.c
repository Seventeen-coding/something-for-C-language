#include "archive.h"

static  int * _getdata(Archive *this_archive);

Archive *Create_archive(int data)
{
    Archive *arch = (Archive *)malloc(sizeof(Archive));
    if(arch == NULL)
    {
        return NULL;
    }
    memset(arch , 0 , sizeof(Archive));
    do{
        memcpy(&arch->data,&data,sizeof(int)); //data如果是一个结构体就不能用等号
        arch->get = _getdata;
        return arch;
    }while(0);
    free(arch);
    return NULL;
}

static int * _getdata(Archive *this_archive)
{
    if(this_archive == NULL)
    {
        return NULL;
    }

    return &this_archive->data;
}
