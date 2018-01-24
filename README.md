# 描述
主要功能：实现一种数据结构需具有以下三种功能：
>
1. 具有链表的快速删除节点功能
2. 具有数组的快速查找功能，如通过index查找数据节点 
3. 存储任意类型数据

# 实现接口方法
根据链表和数组常用使用方法，实现一下几种方法：（曾、删、改、查）
>
1. 实现super_array 结构初始化方法；
2. 实现super_array 结构插入数据方法(从头插入数据节点)；
3. 实现super_array 结构查找方法(byName match);
4. 实现super_array 结构删除方法(byName match);
5. 实现super_array 结构修改节点方法(byName match 和 byIndex match)；

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

# 设计
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

**具有以下特性：** 
1. **使用数组实现链表功能，使其具有链表的快速删除和数组的快速查找功能;**
2. freelist 链表保存空闲节点索引信息，需使用空闲节点时，从此链表获取索引直接定位空闲节点;
3. void* 为通用数据类型，可自由定义保存的数据;
4. 根据当前使用，动态生长内存空间；
5. 提供回调函数，方便扩展；


# 使用场景
在磁盘空间中，我们存储空间节点的大小、空间、个数固定，分布、排列如同一个数组，并且可根据索引号快速定位节点数据。但是在数据抽象处理时，常常需要像链表一样将节点一个个的串起来（节点的空间数据含义不同），根据节点中数据类型分别处理；

