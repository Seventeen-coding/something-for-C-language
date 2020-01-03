 
/*
    C 标准库 - <stdarg.h>
    简介
    stdarg.h 头文件定义了一个变量类型 va_list 和三个宏，这三个宏可用于在参数个数未知（即参数个数可变）时获取函数中的参数。

    可变参数的函数通在参数列表的末尾是使用省略号(,...)定义的。
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void tLog(char *sInfo, ...);

int main(int argc, char *argv[])
{
    char str[4+1] = {0};
    strcpy(str,"INFO");
    tLog(str,argv[1],argv[2],argv[3]);
    return 0;
}
void tLog(char *sInfo, ...)
{
    char *str   = NULL;
    char *str1 = NULL;
    char *str2 = NULL;
    va_list sArgv;          // 申请参数列表变量
    va_start(sArgv, sInfo); // 申明最后一个传递给函数的已知的固定参数
    /* 依次读取固定参数 sInfo 后的 参数 */
    str   = va_arg(sArgv, char*);
    str1 = va_arg(sArgv, char*);
    str2 = va_arg(sArgv, char*);
    va_end(sArgv);
    printf("运行输出：[%s,%s%s%s]\n",sInfo,str,str1,str2);
}
