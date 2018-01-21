# 描述
主要功能：实现一种数据结构需具有以下两种功能：
>
1. 需具有链表的快速删除节点功能
2. 需具有数组的快速查找功能，如通过index查找数据节点 
3. 存储任意类型数据

# 实现
完成数据结构常用使用方法，需实现一下几种方法：
>
1. super_array 结构初始化方法
2. super_array 结构保存方法(从头插入和从尾插入)
3. super_array 结构查找方法(byName 和 byIndex)
4. super_array 结构删除方法
5. super_array 结构修改节点方法

# 使用
编译代码：
```
make super_array_test
```
编译并执行：
```
make all
```
清除：
```
make clean
```
单独执行测试用例：
```
cd ${src_dir}
./super_array_test.out
```

# 设计实现
super_array node 节点数据结构：
```
struct super_array_node {
    int next;//下一个node节点索引
    int previous;//上一个node节点索引
    int valid;//当前node是否有效
    void* data;//数据信息指针
} 
```
super_array header定义如下：
```
struct super_array_header {
    int first;//super_array 第一个 node 的索引
    int total_len;//总node节点个数
    int len;//已使用node节点个数
    int increase_len;
    p_super_array_node r_array;//super_array_node数组,malloc分配
    link_node freelist;//保存当前空闲节点索引 -> 在此链表中的节点都是空闲的
}
```
在 super_array_header数据结构中，super_array node数组负责存储数据信息，freelist链表记录当前所有空闲节点索引；

# 数据结构使用场景
在很情况下，我们存储空间节点的大小、空间、个数固定，就像一个数组。但是在数据处理时，有需要像链表一样将他们一个个的链接起来（节点的空间数据含义不同），如**内核中磁盘文件系统EXT的数据数据存储**。

