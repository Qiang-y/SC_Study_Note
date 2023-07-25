#6.2 语法特性介绍
+ 基本语法格式:指令(参数 1 参数 2...)
```
    参数使用括弧括起
```
        参数之间使用空格或分号分开
指令是大小写无关的,参数和变量是大小写相关的
1. set(HELLO hello.cpp)
2. add_executable(hello main.cpp hello.cpp)
3. ADD_EXECUTABLE(hello IF main.cpp 控制语句中是直接使用变量名
 xiao${HELLO})

==变量使用${}方式取值,但是在IF控制语句中直接使用变量的名字==

#6.3  重要指令和CMake常用变量
 

#6.4 CMake编译工程
CMake目录结构:项目主目录存在一个==CMakeLists.txt==文件

**两种方式设置编译规则:**

1. 包含源文件的子文件夹包含CMakeLists.txt文件,主目录的CMakeLists.txt通过add_subdirectory 添加子目录即可;
2. 包含源文件的子文件夹未包含CMakeLists.txt文件,子目录编译规则体现在主目录的
CMakeLists.txt中;

##6.4.1 编译流程
__在 linux 平台下使用 CMake 构建C/C++工程的流程如下:__
- 手动编写 CMakeLists.txt。
- 执行命令 cmake PATH 生成 Makefile ( PATH 是顶层CMakeLists.txt 所在的目录 )。
- 执行命令 make 进行编译。

```
 # important tips
2 .     # 表示当前目录
3 ./    # 表示当前目录
4
5 ..    # 表示上级目录
6 ../   # 表示上级目录
```

##6.4.2 两种构建方式
- __内部构建(in-source  build)__:不推荐使用
内部构建会在同级目录下产生一大堆中间文件,这些中间文件并不是我们最终所需要的,和工程源文件放在一起会显得杂乱无章。


```
1 ## 内部构建
2
3 # 在当前目录下,编译本目录的CMakeLists.txt,生成Makefile和其他文件
4 cmake .
5 # 执行make命令,生成target
6 make
```

- __外部构建(out-of-source build)__: ==推荐使用==
将编译输出文件和源文件放在不同的目录
```
1 ## 外部构建
2
3 # 1. 在当前目录下,创建build文件夹
4 mkdir build
5 # 2. 进入到build文件夹
6 cd build
7 # 3. 编译上级目录的CMakeLists.txt,生成Makefile和其他文件
8 cmake ..
9 # 4. 执行make命令,生成target
10 make
```