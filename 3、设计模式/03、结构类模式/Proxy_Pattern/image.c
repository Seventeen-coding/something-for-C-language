#include "image.h"

static int _display(Image *this_image);
static void _load(Image *this_image,const char *file_path);

Image *CreateImage(const char *file_path)
{
    if(file_path == NULL)
    {
        return NULL;
    }
    Image *image = (Image *)malloc(sizeof(Image));
    if(image == NULL)
    {
        return NULL;
    }
    do{
        memset(image,0,sizeof(Image));
        strcpy(image->file_path,file_path);
        image->load = _load;
        image->display = _display;
        //image->info = info;
        _load(image,image->file_path);

        return image;
    }while(0);
    free(image);
    return NULL;
}

static int _display(Image *this_image)
{
    if(this_image == NULL)
    {
        return -1;
    }
    printf("play %s\n",this_image->file_path);
    return 0;
}

static void _load(Image *this_image,const char *file_path)
{
    if(this_image == NULL)
    {
        return;
    }

    //加载文件
    //open(file_path);
    printf("loading %s\n",this_image->file_path);
}
