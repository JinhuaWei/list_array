# 描述
此程序为练习使用，主要功能：实现一种数据结构需具有以下两种功能：
>
1. 需具有链表的快速删除节点功能
2. 需具有数组的快速查找功能，如通过index查找数据节点 

#实现#
完成数据结构常用使用方法，需实现一下几种方法：
>
1. super_array 结构初始化方法
2. super_array 结构保存方法(从头插入和从尾插入)
3. super_array 结构查找方法(byName 和 byIndex)
4. super_array 结构删除方法
5. super_array 结构修改节点方法

#设计实现#
文档待完成

#数据结构使用场景#
在很情况下，我们存储空间节点的大小、空间、个数固定，就像一个数组。但是在数据处理时，有需要像链表一样将他们一个个的链接起来（节点的空间数据含义不同），如**内核中磁盘文件系统EXT的数据数据存储**。

#待改进#
1. 现在设计中，存储数据类型只能为int型，后期计划使用**通用数据类型void**
