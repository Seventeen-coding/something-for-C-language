## 适配器模式 Adapter Pattern

> 通过转换适配函数接口

### 解决问题

函数接口一般是固定参数的， 当函数无法改变（存在其他依赖）无法满足函数参数需求，可通过一层转换配置该接口，而这个函数可以叫做适配器。

例如 

伪代码：

play(A, B, C)  、play_mkv（B,A ) 存在参数无法统一

解决办法

play(A, B, C) ->play_mkv_adapter(A,B,C) {  play_mkv(this->B, this->A); }