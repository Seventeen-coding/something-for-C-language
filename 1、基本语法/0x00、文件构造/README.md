## 前言

语言 ： C
中心思想 ：学习C语言整个构造 
目的：  规范化写程序

### 更多

前期工作本来以为是一个很简单的事情，当你文件越来越多的时候，你需要有一个规范去管理你的程序，前期的工作显得尤其重要。 
好比：
1）写程序对应的位置需要写什么（区域化）
2）命名变量和函数需要注意什么（规范化）

## 过程

> 
>
>  声明、结构体声明 变量声明  函数声明 函数实现

#### 头文件

##### 关键词

> #include 头文件 标准头文件 自定义头文文件 

##### 意义

XXX头文件能调用 XXX、包括声明类型、变量、函数（函数需要依赖函数实现，即库或者.c文件）

例如：

标准头文件：stdio.h 文件里面实现了printf函数，linux实现在libc.a（依赖），我们需要用到printf函数就必须引用（#include <stdio.h>）找到printf入口,才能调用打印功能。

自定义头文件：我需要header的struct类型的结构体，我需要#include "header.h".

第三方头文件: 如CJSON.h（github地址：https://github.com/faycheng/cJSON.git）即可实现json解释等功能

#### 总结

- 标准头文件调用标准C语言库
- 自定义头文件，能调用你自己的写代码。
- 第三方头文件，能调用别人开源代码写的代码或库。

### 宏定义

##### 关键词

> #define  #ifdef  #ifndef

##### 意义

在编译前约定的规则,减少重复工作 便于阅读理解





## 例子

还是以source.c header.h 为例子，介绍一个C语言文件常用基本结构， 可以尝试用自己写得例子

```c
/*请用文档编辑器编辑source.c文件*/

/*
*	按照C语言的语法 规范编程
*	一个良好的书写规范决定一个程序的好坏
*	源代码不仅仅给自己看有可能给别人看
*/

/*1、头文件*/
/*1.1、标准头文件*/
#include <stdio.h>
#include <string.h>
/*1.2、自定义头文件*/

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
//规范：函数命名习惯用 Yxx_xxx 或者 YxxYxx等等
//规范：变量命名习惯用 xxx_xxx 或者 xxxYxx等等
char * str_helloworld = "helloworld";
void Call_helloworld(str_t *hw_str);

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
```









