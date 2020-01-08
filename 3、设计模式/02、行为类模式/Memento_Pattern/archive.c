#include "archive.h"

static int *_getdata(ARCHIVE_T *this_archive);

ARCHIVE_T *f_Create_Archive(int data)
{
    ARCHIVE_T *arch = (ARCHIVE_T *)malloc(sizeof(ARCHIVE_T));
    if (arch == NULL)
    {
        return NULL;
    }
    memset(arch, 0, sizeof(ARCHIVE_T));
    do
    {
        memcpy(&arch->data, &data, sizeof(int)); //data如果是一个结构体就不能用等号
        arch->get = _getdata;
        return arch;
    } while (0);
    free(arch);
    return NULL;
}

static int *_getdata(ARCHIVE_T *this_archive)
{
    if (this_archive == NULL)
    {
        return NULL;
    }

    return &this_archive->data;
}
