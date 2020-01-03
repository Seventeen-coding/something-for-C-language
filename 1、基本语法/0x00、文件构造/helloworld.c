/*请用文档编辑器编辑此文件*/

/*
*	按照C语言的语法 规范编程
*	一个良好的书写规范决定一个程序的好坏
*	源代码不仅仅给自己看有可能给别人看
*/

/*1、头文件*/
#include <stdio.h>
#include <string.h>
/*2、宏定义*/
//规范：宏定义一律用大写XXXX_XXXX
#define HW_LEN	10

/*3、结构体声明 .h文件*/
//规范：机构体习惯用XXX_t
typedef struct{
	int  len;
	char *string;
}str_t;
/*4、函数和变量声明*/
//规范：函数命名习惯用 Xxx_xxx 或者 XxxXxx等等
//规范：变量命名习惯用 xxx_xxx 或者 xxxXxx等等
void Call_helloworld(str_t *hw_str);
char * str_helloworld = "helloworld";

/*5、函数实现区*/
//规范：main放在第一个 或者 最后一个 方便程序入口
int main(void)
{
	str_t str;
	str.string = str_helloworld;
	str.len = strlen(str_helloworld);
	Call_helloworld(&str);
	return 0;
}

void Call_helloworld(str_t *hw_str)
{
	if(hw_str == NULL)	return;
	printf("function:%s line:%d\r\n",__FUNCTION__,__LINE__);	
	printf("str:%s len:%d\r\n",hw_str->string,hw_str->len);	
}
