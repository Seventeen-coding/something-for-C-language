
/*
    C 标准库 - <stddef.h>
    简介
        stddef .h 头文件定义了各种变量类型和宏。这些定义中的大部分也出现在其它头文件中。
 */
#include <stddef.h>
#include <stdio.h>

struct address {
    char name[50];
    char street[50];
    int phone;
};

int main(void)
{
    printf("address 结构中的 name 偏移 = %d 字节。\n",
           offsetof(struct address, name));

    printf("address 结构中的 street 偏移 = %d 字节。\n",
           offsetof(struct address, street));

    printf("address 结构中的 phone 偏移 = %d 字节。\n",
           offsetof(struct address, phone));

    return(0);
}
