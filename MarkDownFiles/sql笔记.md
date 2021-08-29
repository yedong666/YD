#                                  SQL笔记

## MySql 与SQL

MySql是一个数据库管理系统

sql是一门结构化查询语言，可以用之访问和处理数据库，包括数据插入、查询、更新、和删除



## SQL的分类



### DQL：数据查询语言，查找 select

#### 简单查询

（1）查询一个字段：select 字段名 form 表名；

（2）查询多个字段：select 字段名1，字段名2 from 表名；

（3）查询全部字段：select * from 表名;（效率低）

（4）给字段起别名：select 字段名 as 别名 from 表名；（仅是在显示时用别名替代字段名，并未		  真正修改字段名， 别名为中文是需用单引号括起来；as关键字也可以省略不写）

（5）字段可以使用数学表达式，如 select 字段名 * 10 from 表名；

#### 条件查询

（1）基本语法：select 字段 from 表名 where 条件；

​		  条件有：=（等于号）、<>(不等号)、<=、>=、between 值1 and 值2、>= and <=

​		   is null、and(并且)、or或者、in(包含)、not not(取非)

​           例子：select name,ID from city where ID >= 3000 and ID <= 2000;

#### 模糊查询

（1）基本语法：like like（模糊查询，支持%或下划线匹配）、%匹配任意个字符、_（一个下划线只匹配一个字符）；

例子：含有（%字符%），以某字符开头（字符%）， 以某字符结尾（%字符），第n(下划线个数)个字符为a(%__a%)；

  \_表示下划线；



#### 分组查询

1、定义：先分组，再操作

2、语法：group by 字段（字段值相同的分为一组）

3、特点：若一条sql语句中含有group by 关键字，则select 关键字之后只能跟分组字段与分组函			      数，因为跟其他的无意义。





#### 查询并有序显示

select 字段1,字段2 from 表名 order by 排序字段 desc/asc(降序或升序，默认为升序)；

order by 排序字段1 desc/asc，排序字段2 desc/asc; (后面的排序字段只有当其前面的字段数据相等时才执行)；

#### 处理函数

1、单行处理函数

特点：多行输入对应多行输出

单行处理函数种类较多

2、分组函数

特点：多行输入对应一行输出，需先分组在操作，若没有分组，则默认整张表为一组

共有五种：count 计数；sum求和；avg求平均值；max求最大值；min求最小值

3、注意事项：分组函数自动忽略null;



综合例子：select name, ID from city where ID between 1000 and 3000 order name desc;

(在city表中查询ID在1000到3000的name和ID，以名字降序排列)



关键字书写顺序：from...where...group by...orderby

关键字执行顺序：from---where---group by---select---order by



### DML：数据操作语言，增insert、删delete、改update，主要是对表中数据进行操作



### DDL：数据定义语言，新建create, 删除drop，修改alter，主要是对表结构进行操作	



### TCL：事务控制语言，任务提交commit，事务回滚rollback



### DCL：数据控制语言，授权grant，撤销权限revoke





## SQL常用命令

1、mysql -uroot -p		登入mysql

2、show databases; 	展示所有数据库

3、use 数据库名称；	操作该数据库

4、*代表全部

5、show tables;		展示数据库中的表信息

6、select * from 表名;		从某表中查询全部数据

7、desc 表名；		查看表结构		

8、select database();		查看当前数据库

9、select version();		查看数据库版本信息

9、\c用来终止一条语句

10、；表示一条语句结束

11、字符串用单引号