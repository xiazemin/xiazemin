## 我的技术博客 👋
https://xiazemin.github.io/MyBlog/index.html

<!--
**xiazemin/xiazemin** is a ✨ _special_ ✨ repository because its `README.md` (this file) appears on your GitHub profile.

Here are some ideas to get you started:

- 🔭 I’m currently working on ...
- 🌱 I’m currently learning ...
- 👯 I’m looking to collaborate on ...
- 🤔 I’m looking for help with ...
- 💬 Ask me about ...
- 📫 How to reach me: ...
- 😄 Pronouns: ...
- ⚡ Fun fact: ...
-->

## 最近的轮子项目  

### golang：

#### 自动生成带gomock的table driving test 代码工具
源码：https://github.com/xiazemin/autotest
实例：https://github.com/xiazemin/tabel_drving_test_learn

#### 支持in 语法的 sqlc 
sqlc that support in syntax
```
-- name: GetAuthorsInCompany :many
SELECT * FROM authors where company_id in ( select id from company where id in (?) and name in (?) );
```
源码：https://github.com/xiazemin/sqlc
实例：https://github.com/xiazemin/sqlc_study
安装：go get -u github.com/xiazemin/sqlc 

#### 可视化golang语法树  

https://github.com/xiazemin/ast_graph  

![可视化语法树](https://github.com/xiazemin/ast_graph/blob/master/tree.svg) 

#### json转golang结构体  

https://github.com/xiazemin/jsonToAll   

### php扩展：

#### 排查超时函数

https://github.com/xiazemin/slowLog  
#### 实现扩展类 
https://github.com/xiazemin/php_ext_class

### php代码工具
#### 查找import指定目录以外的包
php项目改造的时候，快速查找非指定目录内部的namespace，快速排错
https://github.com/xiazemin/php_imports

####  可视化php调用链路
https://github.com/xiazemin/PhpParserEngine
![可视化调用链路](https://github.com/xiazemin/PhpParserEngine/blob/master/Execute/test.png) 

#### nginx模块开发
https://github.com/xiazemin/nginx_mod

## 我的公众号
![关注我](https://mp.weixin.qq.com/mp/qrcode?scene=10000004&size=102&__biz=MzUxMDk3MTczMA==&mid=2247484879&idx=1&sn=00a04ae673f875071cd611445a9dc1b2&send_time=)

