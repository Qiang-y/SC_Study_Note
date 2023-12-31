# SQL和MySQL是什么

- SQL（Structured Query Language，结构化查询语言）是一种用于管理和操作关系型数据库管理系统（RDBMS）的标准化语言。它是一种声明性的编程语言，用于定义数据库中的数据结构、查询数据、插入、更新和删除数据，以及管理数据库对象（如表、视图、索引等）。
- MySQL是一种关系型数据库管理系统（RDBMS）。它使用表格（表）来存储数据，数据以结构化的形式存储，并支持SQL查询语言。

# 一、MySQL常用命令

## docker安装运行mysql：
1. 拉取镜像：
   `docker pull mysql`
2. 运行容器：
   ` docker run -d -p 3306:3306 --name mysql-name -e MYSQL_ROOT_PASSWORD=password mysql`
- -d:设置为一直运行

- --name: 设置容器名字

- -p：设置主机与容器的端口映射

- -e: 设置root用户密码
3. 将终端链接到mysql数据库：
    ` docker exec -it <your_mysql_container_name> mysql -uroot -p<密码> `

## MySQL基本常用命令：

* MySQL操作数据库的命令都以分号结尾
* 不区分大小写也行

****

1. 登录：
    （显示密码）`mysql -uroot -p...密码`
    （隐藏密码）`mysql -uroot -p (p后面不跟参数)`

2. 退出MySQL：
    `exit`

3. 查看mysql中有哪些数据库：
    `show databases;` **分号结尾**

4. 使用mysql管理的数据库：
    `use <name>;`**分号结尾**

5. 创建数据库：
    `create database <name>;`**分号结尾**
   
   - 创建了名为name的数据库

6. 查看数据库中的表：
    `show tables;`

7. 导入数据文件：
    `source <路径>.sql`

    - 路径中不能有中文  

# 数据库中最基本的单元是表——**table**

- 什么是表：
    如同Exce中的表格就是一张表。有横有列，是一种数据的存储方式（但不是数据结构）
  
    如：
  
  ```
  姓名 性别 年龄
  张三 男   18
  李四 女   36
  ```
  
    这是一张表

- 为何使用表：
    因为表比较直观。

- 表的基本性质：
    任何一张表都有行和列
  
  + 行（row）：被称为数据/记录
  + 列（coolumn）：a被称为字段
    如：年龄字段、性别字段。。。。

*每一个字段都有：字段名、数据类型、约束等属性*

# SQL语言分类：

- 命令以分号为截止
- `\c` 可中断命令执行
- 所有数据库中，字符串统一用单引号`''`括起来，双引号在mysql中可用，但在oracle等数据库中不可用

## DQL：

    数据查询语言（凡是带有select关键字的）
    select..

****

### `select * form <table>;`:从table这张表中搜索所有，即列出表中所有元素

### `select version();` :查看数据库版本

### `select databases();` :查看目前使用的数据库

### 简单查询：

-

+ 查询一个字段：
  `select <字段> from <table>;` ：在table中查询一个字段（字段是某一列，不是某个数据）

+ 查询多个字段：
  `select <字段1>,<字段2>,<字段3> from <table>;` 用逗号隔开

+ 查询所有字段：
  `select * from <table>`
  缺点：
    1、效率低
    2、可读性差
    项目中不要用
  
  + `select <name1> as <name2> from <table>;` ：给查询的字段起别名, name1 为表中的字段名， name2 为起的别名。
    *起的别名只在显示中有用，表中原名不变
    *`as`可以省略
    *若别名中有空格，可用单引号把别名括起来
  
  + `select <字段>*num from <table>;` :将查询的字段乘一个数num

### 条件查询(`where`)

- `=`等于：
    `select <field1> from <table> where <field2> = <num>;` :在表table的filed1字段中查询filed2=num的元素（filed1、2不定向要求）
    *也可以查询字符串

- `<>`、`!=` 不等于：
  用法同上，只是a相反

- `<` 小于  |  `<=` 小于等于

- `>`大于 | `>=` 大于等于

- `between ... and ...`:在...和...之间
  `select <field1> from <table> where <field2> between <condition1> and <condition2>;`:在字段1中寻找字段2符合条件1和条件2的元素
  相当于：`select <field1> from <table> where <field2> > <condition1> and <field2> < <condition2>;`
  *__condition1 <= condition2__

- `is null` 查询某项为空的元素
  *用法和以上一样，但在数据库中null不是一个值，不能用等号进行衡量

- `is not null` 相反，查询某项不为空

- `and` 并且，可进行多项条件查询：
  `select <field1> from <table> where <conditon1> and <conditon2>;`

- `or` 或者，用法和上面一样，但开集，只要满足一项条件即可

***```and 的优先级比 or 高，当and和ori同时出现时，先执行and 。当同时出现时应用 括号 确保执行顺序```

- `in` 包含,相当于多个 or（not in则相反，即不在这个范围中）：
  `select <field1> from <table> where <field2> in (<condition1> , <condition2>);`
  相当于：`select <field1> from <table> where <field2> <condition1> or <field2> <condition2>;`
  
    __`in`后面不是区间，而是具体的值__

- `no` 表示取反

### 模糊查询`like`

-
在where条件后加入like关键字可进行模糊查询（查看是否匹配），支持`%`或`_`匹配
`&`匹配任意多个字符
`_`匹配任意一个字符

- `select <field1> from <table> where <field2> like '%T%';` : 查找filed2字段中间有T的元素

- `select <field1> from <table> where <field2> like '%T';` : 查找filed2字段以T结尾的元素

- `select <field1> from <table> where <field2> like 'T%';` : 查找filed2字段以T开头的元素

- `select <field1> from <table> where <field2> like '_T%';` : 查找filed2字段第二个字母为T的元素

- `select <field1> from <table> where <field2> like '__R%';` : 查找filed2字段第三个字母为R的元素

- <span style="color:orange;"> 若是要找出字段中含有‘_’和‘%’的，要加 <span style="color:green;">转义字符 

### `order by` 以排序的方式查询

    - `select <field1> from <table> order by <field2>;` 以字段2为依据排序列出字段1（默认为升序）
    - `select <field1> from <table> order by <field2> desc;` ;指定降序排列
    - `select <field1> from <table> order by <field2> asc;` ;指定升序排列
    - 也可以按第几列来排序：
    `select <field1> from <table> order by 2;` ;按第二列来排序
    <span style="color:orange;">不建议这样用

### 按多个字段排序查询：在排序后面加逗号：

    - `select <field1> from <table> order by <field2>，<field3>, <field4>;` ;依次按顺序排列，先按field2排，当field2相同时按field3排，依次往下。
    默认为升序，可在具体字段后面添加控制符指定顺序

### **分组查询/分组

    'group by ..'

`select 列1, 列2, 聚合函数1(列), 聚合函数2(列), ...
from 表名
group by 列1, 列2, ...;`

- 列1, 列2, ...：用于分组的列。你可以指定一个或多个列名，决定按照哪些列的值进行分组。
- 聚合函数1(列), 聚合函数2(列), ...：对每个组进行聚合计算的函数，如COUNT()（计数）、SUM()（求和）、AVG()（平均值）、MAX()（最大值）、MIN()（最小值）等。这些函数用于计算分组后每个组内的值。

示例：

```sql
select job,sum(sal) 
from emp
group by job;
```

解读：

- 先从emp表中查询数据
- 再根据job字段进行分组
- 然后对每一组的数据进行求和sum（sal）

<span style="color:blue">注意:在一条select语句中，如有group by， select后面只能跟：参加分组的字段，以及分组函数，其它一律不能跟

**`group by`后面还可跟多个分组字段（用逗号隔开），进行多字段分组

### `having`：对分组的结果进行过滤

where 和 having： where是在分组前对数据进行过滤，having则是在分组后对每组中的数据在进行一次过滤

一般优先选用where，where的速度快，where无法完成时再考虑having

### `distinct` 查询结果去重

注：原表数据不会被修改，只是查询的结果去重
`select distinct <field> from <table>`

* `distinct`只能放在所有查找的字段前方
* `distinct`也能放在函数中的字段的前方，优先作用

****

### 单表查询综合用法：

```sql
    select 
        ...
    from 
        ...
    where 
        ...
    group by
        ...
    having
        ...
    order by
        ...

    **语句顺序不能变
```

### `join`连接查询

    表的链接越多，运行效率越低(笛卡尔积现象)，因此要减少表的链接个数

以上内容都是在一张表中对同一张表中的数据进行查询操作，但现实中需要进行查询的数据分布在不同的多张表格中，此时就需要多表连接查询

    按语法分类：
    - SQL92： 1992年
    - SQL99： 1999年（重点学习）
    
    按连接方式分类：
    - 内连接：内连接是最常见的连接类型之一。分为：等值链接、非等值链接 和 自链接
            它只返回两个表之间满足连接条件的行。
            内连接只保留两个表中共有的记录，即连接列值在两个表中都存在的记录。
            如果连接列在某个表中没有对应的匹配值，该将被忽略。
    
    - 外连接：分为：左外连接 和 右外连接
            外连接返回被链接表中的所有记录以及链接表中满足连接条件的记录。
            如果链接表中没有匹配的记录，仍然会保留被连接表中的记录，而对应的链接表部分将填充为NULL。
    
    - 全连接：全外连接返回两个表中的所有记录，无论是否有匹配的记录。
            如果某个表中没有匹配的记录，对应的部分将填充为NULL。

#### `join ..on .. `/ `inner join ..on ..`内连接

#####`=`等值链接:

```sql
select <table1>.<field1>, <table2>.<field2> 
from <table1> join <table2> 
on <table1>.<field3>=<table2>.<field4>
```

解释：在表1和表2中符合字段3=子段4的数据中搜索表1的字段1和表2的字段2

例子：

```sql
select f.fname, s.sname 
from first_ as f
join second_ as s
on f.deptno = s.deptno
```

- 先将表first_ 和表second_ 分别区别名f和s，然后将f和s中deptno相同的项连接在一起，在连接的项目中查找表f和表s的name项目。

##### 非等值链接

`on`后面的条件不是等值关系，则称为非等值链接。
如：join .. on .. between .. and ..

##### 自连接

<span style="color:orange">一张表看做两张表

将一个表视为两个逻辑表，并在该表内部进行连接。通过使用表中的关联字段来关联这些记录。

示例：
 Employees 表包含员工的信息，其中有一个 employee_id 列用于表示员工的上级经理。manager_id 是对应员工的上级经理的员工ID。现在，要获取每个员工的名字以及他们对应的上级经理的名字则可将Employs表取a，b两个别名，看成两张表，用a表的employ_id = manager_id 的项链接，链接得的名字即为输出

```sql
Employees 表：
----------------------------------
| employee_id | name        | manager_id |
----------------------------------
| 1          | John        | 3          |
| 2          | Mary        | 3          |
| 3          | Mike        | 4          |
| 4          | Sarah       | NULL       |
| 5          | Alex        | 4          |
----------------------------------

代码：
SELECT e1.name AS EmployeeName, e2.name AS ManagerName
FROM Employees e1
JOIN Employees e2 
ON e1.manager_id = e2.employee_id;

结果：
----------------------------------
| EmployeeName | ManagerName |
----------------------------------
| John         | Mike        |
| Mary         | Mike        |
| Mike         | Sarah       |
| Alex         | Sarah       |
----------------------------------
```

#### 外链接：

`outer join`和`join`一样，即outer可省略

##### 左外连接（左连）

```sql
select *
from 左表
left join 右表 on 左表.列 = 右表.列;
```

（左表为主表）
这种连接类型将返回**左表中所有的行**，以及**与右表中匹配的行**。如果右表中没有匹配的行，则返回的结果中相关列的值将为**NULL**。左外连接使用**LEFT JOIN**关键字来表示。

##### 右外连接（右连）

```sql
select *
from 左表
right join 右表 on 左表.列 = 右表.列;
```

（右表为主表）
这种连接类型将返回**右表中所有的行**，以及**与左表中匹配的行**。如果左表中没有匹配的行，则返回的结果中相关列的值将为**NULL**。右外连接使用**RIGHT JOIN**关键字来表示。

#### 全外连接：

```sql
select *
from 左表
left join 右表 on 左表.列 = 右表.列
union
select *
from 左表
right join 右表 on  左表.列 = 右表.列;
```

这种连接类型**返回左表和右表中所有的行，并将它们组合在一起**。如果某个表中没有匹配的行，则返回的结果中相关列的值将为**NULL**。注意：MySQL本身不直接支持全外连接，但可以通过使用**union**操作符+**外连接**来模拟实现全外连接的效果。

<span style="color:orange">查询结果条数：外连接 > 内连接

#### 多张表链接

```sql
select 
    ...
from
    a
join 
    b
on
    a 和 b 的链接条件
join 
    c
on 
    a 和 c 的链接a条件
join
    d
on
    a 和 d 的链接a条件
...
```

其中链接方式可替换成外连接

#### union合并查询结果集

UNION是一种用于合并两个或多个SELECT查询结果的操作符。它用于将两个或多个查询的结果集合并为一个结果集，并**自动去除重复的行**。要使用UNION，**查询的列数和数据类型必须匹配**

```sql
SELECT column1, column2, ...
FROM table1
WHERE condition
UNION
SELECT column1, column2, ...
FROM table2
WHERE condition;

两个select语句的结果将会合并为一个结果集，并在结果中去除重复的行
如果想保留重复的行，可以使用union all操作符。
```

```sql
示例
select employee_name
from employees
union
select contractor_name
from contractors;

上面的查询将返回一个包含所有员工和合同工姓名的列表，并且会自动去除重复的姓名
```

相对于表连接，union的效率要高一些
union可以减少匹配的次数，在减少匹配次数的情况下，依然可以完成两个结果集的拼接

### 子查询

定义：select语句中嵌套select语句，被嵌套的select语句称为子查询

```sql
select 
    ...
from 
    ...(select).
where 
    ...(select).
```

#### where 中的子查询

```sql
select 
    ENAME,SAL 
from 
    EMP 
where 
    SAL>(select min(SAL) from EMP);

//查询所有比最低工资高的员工的名字和薪资
```

#### from中的子查询

**from后面的子查询，可以将子查询的查询结果当做一张临时表**

```sql
SELECT column1, column2
FROM (SELECT column1, column2 FROM table1 WHERE condition) AS subquery;
```

示例：

```sql
设有EMP和SALGRADE两表分别存储员工信息和薪资等级的薪资范围
为求每个工作岗位的薪资平均值所处的等级：

select t.*,s.GRADE 
from 
    (select JOB,avg(SAL) as a from EMP group by JOB) as t 
    join 
        SALGRADE s 
    on 
        t.a between s.LOSAL and s.HISAL;
```

解读：

- 先将在EMP表中搜索岗位和岗位薪资平均值`(select JOB,avg(SAL) as a from EMP group by JOB)`,形成一张临时表取名t
- 再将t临时表和SALGRADE表连接查询t表中的平均薪资在SALGRADE表中所处的等级

**临时表和临时变量都必须取别名保存下来，即本例中的临时表取名t，临时表中的`avg(SAL)`取别名a**
否则会报错，因为SQL服务端语句解析句每次都会重新解析函数关键字

#### select后面的子查询（略微了解即可）

SELECT语句的后面的子查询，作为一个额外的列或计算结果。这种子查询被称为“*标量子查询*”，因为它返回单个值而不是一组记录。

```sql
select 
    e.ENAME, e.DEPTNO, (select 
                            d.DNAME 
                        from 
                            DEPT d 
                        where 
                            e.DEPTNO = d.DEPTNO) as dname 

from 
    EMP e;

结果：
+--------+--------+------------+
| ENAME  | DEPTNO | dname      |
+--------+--------+------------+
| SMITH  |     20 | RESEARCH   |
| ALLEN  |     30 | SALES      |
| WARD   |     30 | SALES      |
| JONES  |     20 | RESEARCH   |
| MARTIN |     30 | SALES      |
| BLAKE  |     30 | SALES      |
| CLARK  |     10 | ACCOUNTING |
| SCOTT  |     20 | RESEARCH   |
| KING   |     10 | ACCOUNTING |
| TURNER |     30 | SALES      |
| ADAMS  |     20 | RESEARCH   |
| JAMES  |     30 | SALES      |
| FORD   |     20 | RESEARCH   |
| MILLER |     10 | ACCOUNTING |
+--------+--------+------------+

注：此处不需要用到表连接
```

<span style="color:red">*select后面的子查询只能一次返回一条查询结果，若结果多于一条则会报错

### limit 取出查询结果的一部分(重要)

limit可以限制返回结果的条数，在分页查询和限制结果集大小方面起很大作用

<span style="color:orange">MySQL中limit在order by之后执行

```sql
不指定开始行数：
select column1, column2, ...
from table_name
where condition
limit length;
```

- `length`: 指定要返回的行数。它表示要从查询结果中返回多少行数据。

```sql
指定开始行数：
select column1, column2, ...
from table_name
where condition
limit startIndex, length;
```

- `startIndex` ：指定截取开始行数的下标（起始下标为0）
- `length`: 指定要返回的行数。它表示要从查询结果中返回多少行数据。

#### `limit`和`offset`连用

效果和limit后面两个参数一样

- `offset`: 指定查询结果开始的行数偏移量。它表示从查询结果中的哪一行开始返回数据。通常，第一行的偏移量是0
  
  ```sql
  select * 
  from employees 
  limit 5 offset 6;
  ```

从7行始返回5条记录

```
实际用法：
分页显示——将结果分成几页进行显示，提高用户体验

#### 通用分页方法
```sql
```

**** 

## DML：

    数据操作语言（凡是对表中数据进行增删改的）
    insert 增 | delete 删 |update 改
    DML主要操作表中数据

***

***

## DDL：

    数据定义语言（凡是带有create、drop、alter的）
    DDL主要操作的是表的结构， 不是表中的数据

***

1. `desc <table>;`  查看表的结构(describe)

***

## TCl：

    事务控制语言
    包括：
        事务提交：commit
        事务回滚：rollback

## DCL：

    数据控制语言
    如：授权grant、 撤销权限revoke.... 

# MySQL函数

    *MySQL函数不同于SQL语言

## 数据处理函数（单行处理函数）

<span style="color:orange"> 单行是指数据库中的单行数据。每次只执行u数据库中的一行

    特点：一个输入对应一个输出

| 函数                                                   | 作用                                                                                                      | 示例                                                                                                                        |
| ---------------------------------------------------- | ------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------- |
| lower()                                              | 将某个字段大写转小写                                                                                              | `select lower(<field>) from <table>;` 将table中field的大写转换为小写显示                                                              |
| upper()                                              | 大写转小写                                                                                                   |                                                                                                                           |
| substr(str, begin, length)                           | 取子串                                                                                                     | substr(被截取字符串， 起始下标， 截取长度)***字符串下标从1开始，而不是0                                                                               |
| length(< field>)                                     | 获取某一列的每个元素各自的长度                                                                                         |                                                                                                                           |
| trim（< field>）                                       | 去空格、也可去除前后空白                                                                                            |                                                                                                                           |
| <span style="color:green">============               | <span style="color:green">============                                                                  | <span style="color:green">============                                                                                    |
| *str_to_date()                                       | 将字符串转换为日期                                                                                               |                                                                                                                           |
| *date_format()                                       | 格式化日期                                                                                                   |                                                                                                                           |
| *format()                                            | 设置千分位                                                                                                   |                                                                                                                           |
| <span style="color:green">============               | <span style="color:green">============                                                                  | <span style="color:green">============                                                                                    |
| round()                                              | 四舍五入(对小数)                                                                                               | `round(float a)`：将小数a四舍五入为整数    `round(float a, int b)` : 指定四舍五入的位数，如b=0为四舍五入到整数位，b=1为四舍五入到小数点后一位，b=-1为十位                 |
| rand()                                               | 生成随机数                                                                                                   | `select rand() from <table>;`：生成随机0到1之间的随机浮点数*也可以和round()合用生成指定位数的随机数：`select round(rand()*N) from <table>;`:生成0-N的随机整数   |
| ifnull(< field>, num)                                | *空处理函数 ， 可以将table中null转换成一个具体数值num <span style="color:orange"> 有NULL参与运算的，最终结果都会是null，所以要做运算前要先把null变成0 | `select ifnull(<field>, 10) from <table>` 将field字段中的所有null换成10                                                            |
| case .. when .. then .. when .. then .. else .. end; | 条件判断执行语句                                                                                                | `select ENAME,JOB,SAL ,(case JOB when 'MANAGER' then SAL*10 when 'SALESMAN' then SAL*5 else SAL end) as newsal from EMP;` |

## 分组函数/多行处理函数

<span style="color:orange"> 多行是指数据库中的多行数据。对数据库中多行数据进行操作，然后输出一个结果

    特点： 多个输入对应一个输出
    注意：
    1. 分组函数在使用前要进行分组，然后再使用
        若未分组，则将整张表看做一组
    2. 分组函数自动忽略null
    3. 分组u函数不能够直接使用在where子句中
    4. 所有的分组函数可以组合起来一起用

| 函数      | 作用  | 示例                                                                                                                |
| ------- | --- | ----------------------------------------------------------------------------------------------------------------- |
| count() | 计数  | `select count(<field>) from <table>;` 计算table中的field字段所有不为NULL的元素个数                                               |
| sum()   | 求和  | `select sum(<field>) from <table>;` 将table中的field字段所有元素相加求和再输出       `select JOB,sum(SAL) from EMP group by JOB;` |
| avg()   | 平均值 |                                                                                                                   |
| max()   | 最大值 |                                                                                                                   |
| min()   | 最小值 |                                                                                                                   |
