
#include "strategy_pattern.h"

void run();

int main(void)
{
    run();
    return 0;
}

//策略模式：
//类似思维 ：重写  或者 继承概念 运行时决定具体策略
//同一个接口不同实现策略（方式）
//两种方法结算： 第一种： 根据类型判断具体价格， 判断部分就需要写在结算函数
//             第二种： 结算按照策略接口执行，该是多少就是多少，无需判断
//本程序围绕第二种结算方法实现
//好处：   结算只针对钱，因为创建时已经进行判断了（赋予不同结算策略）
//        如果某一天不需要这种类型 或者 新增了新类型 不需要在结算时额外对新类型进行修改
//例子： 用户         结算方式
//     普通用户      普通用户注册费用+无优惠
//     普通VIP用户   普通用户注册费用+VIP优惠
//     超级VIP用户   超级用户注册费用+VIP优惠
//因此只需要user + 注册策略 + 优惠策略 即可
void run()
{
    User *user = Create_User("seventeen","account","password",NORMAL_USER);
    if(user == NULL)
    {
        return ;
    }
    printf("normal user cost : %d\n",user->Cost(user));
    Upgrade_user(user,VIP_USER);
    printf("vip user cost : %d\n",user->Cost(user));
    Upgrade_user(user,SUPER_VIP_USER);
    printf("super vip user cost : %d\n",user->Cost(user));
    Upgrade_user(user,NORMAL_USER);
    printf("normal user cost : %d\n",user->Cost(user));
}
