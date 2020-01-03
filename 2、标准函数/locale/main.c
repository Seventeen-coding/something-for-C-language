/*
locale.h 头文件定义了特定地域的设置，
比如日期格式和货币符号。
接下来我们将介绍一些宏，
以及一个重要的结构 struct lconv 和两个重要的函数。
*/

#include <stdio.h>
#include <locale.h>
#include <time.h>
int main(void)
{
    time_t currtime;
    struct tm *timer;
    char buffer[80];

    time(&currtime);
    timer = localtime(&currtime);

    printf("Locale is: %s\n", setlocale(LC_ALL, "en_GB.UTF-8"));
    strftime(buffer, 80, "%c", timer);
    printf("Date is: %s\n", buffer);


    printf("Locale is: %s\n", setlocale(LC_ALL, "C"));
    strftime(buffer, 80, "%c", timer);
    printf("Date is: %s\n", buffer);


    struct lconv * lc;

    setlocale(LC_MONETARY, "it_IT");
    lc = localeconv();
    printf("Local Currency Symbol: %s\n", lc->currency_symbol);
    printf("International Currency Symbol: %s\n", lc->int_curr_symbol);

    setlocale(LC_MONETARY, "en_US");
    lc = localeconv();
    printf("Local Currency Symbol: %s\n", lc->currency_symbol);
    printf("International Currency Symbol: %s\n", lc->int_curr_symbol);

    setlocale(LC_MONETARY, "en_GB");
    lc = localeconv();
    printf("Local Currency Symbol: %s\n", lc->currency_symbol);
    printf("International Currency Symbol: %s\n", lc->int_curr_symbol);

    printf("Decimal Point = %s\n", lc->decimal_point);


    return 0;
}
