# #git是如何运行的

git的底层原理：

![git的底层原理](./resource/1-1.png)

教学视频：[[自制双语字幕] 计算机教育缺失的一课(2020) - 第6讲 - 版本控制(Git)_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1Wh4y1s7Lj/?spm_id_from=333.999.0.0&vd_source=db6d2203c2a862f2952bc7180d665d24)

参考文档：[一文讲透 Git 底层数据结构和原理 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/142289703)



# git的常用命令：

   `灵活运用用git help命令`

## 初始化空的git本地仓库：git init

![2-1](./resource/2-1.jpg "2-1")

此时若是输入`ls .git`会列出其中的文件，其中`object`和`refs`文件夹分别存储git树的“对象”和“引用”，即所有仓库数据会放在这两个文件下，十分重要。

![2-2](./resource/2-2.jpg)

## 查看仓库状态：git status

![status](./resource/2-3.jpg)
