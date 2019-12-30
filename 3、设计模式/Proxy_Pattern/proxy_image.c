#include "proxy_image.h"


static int _display(Proxy_Image *this_proxy);

Proxy_Image *CreateProxy_Image(const char * file_path)
{
    Proxy_Image *proxy;
    if(file_path == NULL)
    {
        return NULL;
    }
    proxy = (Proxy_Image *)malloc(sizeof(Proxy_Image));
    if(proxy == NULL)
    {
        return NULL;
    }
    do{
        memset(proxy,0,sizeof(Proxy_Image));
        strcpy(proxy->file_path,file_path);
        //由于只代理display这项"业务" 所以不具备load
        proxy->display = _display;
        return proxy;
    }while(0);
    free(proxy);
    return NULL;
}


static int _display(Proxy_Image *this_proxy)
{
    if(this_proxy == NULL)
    {
        return -1;
    }

    if(this_proxy->image == NULL)
    {
        this_proxy->image = CreateImage(this_proxy->file_path);
        if(this_proxy->image == NULL)
        {
            return -2;
        }
    }

    this_proxy->image->display(this_proxy->image);
    return 0;
}
