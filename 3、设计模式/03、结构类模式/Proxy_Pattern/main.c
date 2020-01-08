
#include "proxy.h"
#include <stdio.h>

void run();

//例如原厂手机不但可以销售还了解构造手机等过程
//代理商不清楚手机怎么生产 它只针对销售这个业务做更多扩展
int main(void)
{
    run();
    return 0;
}

//test
void run()
{
    //这种缺陷是生成出来以后必须要加载文件 浪费资源
    Image *image = CreateImage("./helloworld.jpg");
    Proxy_Image * proxy = CreateProxy_Image("./Proxy_helloworld.jpg");
    if(proxy == NULL)
    {
        return;
    }
    if(image == NULL)
    {
        return;
    }
    image->display(image);
    //对image进行代理 扩展了display业务 和 装饰者模式很像
    //装饰者是重写了业务 函数指针未改变
    //代理是利用新的接口
    proxy->display(proxy);

}
