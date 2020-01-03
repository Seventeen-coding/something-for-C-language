/*
    <assert.h>	条件编译宏，将参数与零比较
*/
#include <assert.h>

int main(void)
{
    int a = 10;
    assert(a >= 10);

    char *str = "hello" ;
    assert(str == 0);

    return 0;
}
