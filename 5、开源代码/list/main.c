/*
	这里可以写相关文件描述 协议等等信息
	如：
	按照C语言的语法 规范编程
	一个良好的书写规范决定一个程序的好坏
	源代码不仅仅给自己看有可能给别人看
*/

/*1、头文件*/
#include <stdio.h>
#include <string.h>
#include "main.h"

/*2、宏定义
#define TEMPLATE	XXXXXX
*/

/*3、结构体声明
typedef struct{
	int  xxx_xxx;
	char *xxx_xxx;
}TEMPLATE_T;
*/

/*4、函数和变量声明
int Template(TEMPLATE_T xxx_xxx );
*/

/*5、函数实现区
int Template(TEMPLATE_T xxx_xxx )
{
	return 0;
}
*/
int main(void)
{
	list_t *langs = list_new();

	list_node_t *c = list_rpush(langs, list_node_new("c"));
	list_node_t *js = list_rpush(langs, list_node_new("js"));
	list_node_t *ruby = list_rpush(langs, list_node_new("ruby"));

	list_node_t *node;
	list_iterator_t *it = list_iterator_new(langs, LIST_HEAD);
	while ((node = list_iterator_next(it)))
	{
		const char *str = (char *)node->val;
		printf("%s\n", str);
	}

	list_iterator_destroy(it);
	list_destroy(langs);
}
