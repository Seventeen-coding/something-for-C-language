/*
    C 标准库的 float.h 头文件包含了一组与浮点值相关的依赖于平台的常量。
    这些常量是由 ANSI C 提出的，这让程序更具有可移植性。
    在讲解这些常量之前，最好先弄清楚浮点数是由下面四个元素组成的
    S	符号 ( +/- )
    b	指数表示的基数，2 表示二进制，10 表示十进制，16 表示十六进制，等等...
    e	指数，一个介于最小值 emin 和最大值 emax 之间的整数。
    p	精度，基数 b 的有效位数
    floating-point = ( S ) p * b^e
*/
#include <stdio.h>
#include <float.h>
int main(void)
{
    printf("The maximum value of float = %.10e\n", FLT_MAX);
    printf("The minimum value of float = %.10e\n", FLT_MIN);

    printf("The number of digits in the number = %.10e\n", FLT_MANT_DIG);
}
