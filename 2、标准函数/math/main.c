/*
    math.h 头文件定义了各种数学函数和一个宏。
    在这个库中所有可用的功能都带有一个 double 类型的参数，
    且都返回 double 类型的结果。
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main(void)
{
    //   1	double acos(double x)
    //   返回以弧度表示的 x 的反余弦。
    {
        double x, ret, val;

        x = 0.9;
        val = 180.0 / PI;

        ret = acos(x) * val;
        printf("%lf 的反余弦是 %lf 度", x, ret);
    }
    //   2	double asin(double x)
    //   返回以弧度表示的 x 的反正弦。
    {
        double x, ret, val;
        x = 0.9;
        val = 180.0 / PI;

        ret = asin(x) * val;
        printf("%lf 的反正弦是 %lf 度", x, ret);

    }
    //   3	double atan(double x)
    //   返回以弧度表示的 x 的反正切。
    {
        double x, ret, val;
        x = 1.0;
        val = 180.0 / PI;

        ret = atan(x) * val;
        printf("%lf 的反正切是 %lf 度", x, ret);

    }
    //   4	double atan2(double y, double x)
    //   返回以弧度表示的 y / x 的反正切。y 和 x 的值的符号决定了正确的象限。
    {
        double x, y, ret, val;

        x = -7.0;
        y = 7.0;
        val = 180.0 / PI;

        ret = atan2(y, x) * val;
        printf("x = %lf, y = %lf 的反正切", x, y);
        printf("是 %lf 度\n", ret);
    }
    //   5	double cos(double x)
    //   返回弧度角 x 的余弦。
    {
        double x, ret, val;

        x = 60.0;
        val = PI / 180.0;
        ret = cos(x*val);
        printf("%lf 的余弦是 %lf 度\n", x, ret);

        x = 90.0;
        val = PI / 180.0;
        ret = cos(x*val);
        printf("%lf 的余弦是 %lf 度\n", x, ret);
    }
    //   6	double cosh(double x)
    //   返回 x 的双曲余弦。
    {
        double x;

        x = 0.5;
        printf("%lf 的双曲余弦是 %lf\n", x, cosh(x));

        x = 1.0;
        printf("%lf 的双曲余弦是 %lf\n", x, cosh(x));

        x = 1.5;
        printf("%lf 的双曲余弦是 %lf\n", x, cosh(x));
    }
    //   7	double sin(double x)
    //   返回弧度角 x 的正弦。
    {
        double x, ret, val;

        x = 45.0;
        val = PI / 180;
        ret = sin(x*val);
        printf("%lf 的正弦是 %lf 度", x, ret);

    }
    //   8	double sinh(double x)
    //   返回 x 的双曲正弦。
    {
        double x, ret;
        x = 0.5;

        ret = sinh(x);
        printf("%lf 的双曲正弦是 %lf 度", x, ret);

    }
    //   9	double tanh(double x)
    //   返回 x 的双曲正切。
    {
        double x, ret;
        x = 0.5;

        ret = tanh(x);
        printf("%lf 的双曲正切是 %lf 度", x, ret);

    }
    //   10	double exp(double x)
    //   返回 e 的 x 次幂的值。
    {
        double x = 0;

        printf("e 的 %lf 次幂是 %lf\n", x, exp(x));
        printf("e 的 %lf 次幂是 %lf\n", x + 1, exp(x + 1));
        printf("e 的 %lf 次幂是 %lf\n", x + 2, exp(x + 2));

    }
    //   11	double frexp(double x, int *exponent)
    //   把浮点数 x 分解成尾数和指数。返回值是尾数，并将指数存入 exponent 中。所得的值是 x = mantissa * 2 ^ exponent。
    {
        double x = 1024, fraction;
        int e;

        fraction = frexp(x, &e);
        printf("x = %.2lf = %.2lf * 2^%d\n", x, fraction, e);

    }
    //   12	double ldexp(double x, int exponent)
    //   返回 x 乘以 2 的 exponent 次幂。
    {
        double x, ret;
        int n;

        x = 0.65;
        n = 3;
        ret = ldexp(x, n);
        printf("%f * 2^%d = %f\n", x, n, ret);

    }
    //   13	double log(double x)
    //   返回 x 的自然对数（基数为 e 的对数）。
    {
        double x, ret;
        x = 2.7;

        /* 计算 log(2.7) */
        ret = log(x);
        printf("log(%lf) = %lf", x, ret);

    }
    //   14	double log10(double x)
    //   返回 x 的常用对数（基数为 10 的对数）。
    {
        double x, ret;
        x = 10000;

        /* 计算 log10(10000) */
        ret = log10(x);
        printf("log10(%lf) = %lf\n", x, ret);

    }
    //   15	double modf(double x, double *integer)
    //   返回值为小数部分（小数点后的部分），并设置 integer 为整数部分。
    {
        double x, fractpart, intpart;

        x = 8.123456;
        fractpart = modf(x, &intpart);

        printf("整数部分 = %lf\n", intpart);
        printf("小数部分 = %lf \n", fractpart);
    }
    //   16	double pow(double x, double y)
    //   返回 x 的 y 次幂。
    {
        printf("值 8.0 ^ 3 = %lf\n", pow(8.0, 3));

        printf("值 3.05 ^ 1.98 = %lf", pow(3.05, 1.98));
    }
    //   17	double sqrt(double x)
    //   返回 x 的平方根。
    {

        printf("%lf 的平方根是 %lf\n", 4.0, sqrt(4.0));
        printf("%lf 的平方根是 %lf\n", 5.0, sqrt(5.0));

    }
    //   18	double ceil(double x)
    //   返回大于或等于 x 的最小的整数值。
    {
        float val1, val2, val3, val4;

        val1 = 1.6;
        val2 = 1.2;
        val3 = 2.8;
        val4 = 2.3;

        printf("value1 = %.1lf\n", ceil(val1));
        printf("value2 = %.1lf\n", ceil(val2));
        printf("value3 = %.1lf\n", ceil(val3));
        printf("value4 = %.1lf\n", ceil(val4));
    }
    //   19	double fabs(double x)
    //   返回 x 的绝对值。
    {
        int a, b;
        a = 1234;
        b = -344;

        printf("%d 的绝对值是 %lf\n", a, fabs(a));
        printf("%d 的绝对值是 %lf\n", b, fabs(b));
    }
    //   20	double floor(double x)
    //   返回小于或等于 x 的最大的整数值。
    {
        float val1, val2, val3, val4;

        val1 = 1.6;
        val2 = 1.2;
        val3 = 2.8;
        val4 = 2.3;

        printf("Value1 = %.1lf\n", floor(val1));
        printf("Value2 = %.1lf\n", floor(val2));
        printf("Value3 = %.1lf\n", floor(val3));
        printf("Value4 = %.1lf\n", floor(val4));
    }
    //   21	double fmod(double x, double y)
    //   返回 x 除以 y 的余数。
    {
        float a, b;
        int c;
        a = 9.2;
        b = 3.7;
        c = 2;
        printf("%f / %d 的余数是 %lf\n", a, c, fmod(a, c));
        printf("%f / %f 的余数是 %lf\n", a, b, fmod(a, b));
    }
    return 0;
}