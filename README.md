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

### vscode 插件
https://github.com/xiazemin/golangCodeHelper
支持右键从json文件生成golang结构体，从curl生成golang http请求代码 

### golang：

#### 自动生成带gomock的table driving test 代码工具
源码：https://github.com/xiazemin/autotest
实例：https://github.com/xiazemin/tabel_drving_test_learn
安装：go get -u github.com/xiazemin/autotest/gotests
![自动生成带gomock的代码](https://github.com/xiazemin/autotest/blob/master/WechatIMG600.jpeg)

#### 支持in 和values 语法的 sqlc 
sqlc that support in syntax
```
-- name: GetAuthorsInCompany :many
SELECT * FROM authors where company_id in ( select id from company where id in (?) and name in (?) );
```
支持不定长values语法
```
/* name: BatchCreateAuthor :execresult */
INSERT INTO authors (
  id,name,bio,company_id
) VALUES (
  ?,?, ?,1 
),(
  ?,?, ?,1 
);
```
源码：https://github.com/xiazemin/sqlc
实例：https://github.com/xiazemin/sqlc_study
安装：go get -u github.com/xiazemin/sqlc 

#### 可视化golang语法树  

https://github.com/xiazemin/ast_graph  

![可视化语法树](https://github.com/xiazemin/ast_graph/blob/master/tree.svg) 


#### nacos sidecar服务自动注册
https://github.com/xiazemin/registrator-nacos

![nacos sidecar服务自动注册](https://github.com/xiazemin/registrator-nacos/blob/main/nacos.jpeg)

```
docker run -d \
    --name=registrator-nacos \
    --net=host \
    --volume=/var/run/docker.sock:/tmp/docker.sock \
    xiazemin/registrator-nacos:v0.0.1 \
      nacos://127.0.0.1
```
```
docker run  -p5678:5678 yourservice:yourport
```


#### json转golang结构体  

https://github.com/xiazemin/jsonToAll 

#### proto 生成xmind文件
https://github.com/xiazemin/proto2xmind

安装： go install github.com/xiazemin/proto2xmind
使用： proto2xmind gen -s ./example/sub.proto -s ./example/request.proto -d ./example/example.xmind

![example.xmind](https://github.com/xiazemin/proto2xmind/blob/main/example/root.proto.png)

#### json格式生成xmind文件
给定父子结构关系json，生成对应的xmind文件
https://github.com/xiazemin/xmind-go

#### mysql压测工具：
https://github.com/xiazemin/mysqlslap-go

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

