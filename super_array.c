#include <stdlib.h>
#include "super_array.h"

#define DEFAULT_INIT_LEN 64
#define DEFAULT_INCREASE_LEN 64

/**
* 0 节点为supper_array 的尾部,哨兵作用，不存放任何数据， 头结点的privous为 -1
*
*/


/**
* return value:
* 1: no memory space
*/
int super_array_init(p_super_array_header header)
{
    int i;
    int rtn;
    header->first = 0;//0节点为super_array的尾部
    header->len = 0;
    header->total_len = DEFAULT_INIT_LEN;
    header->increase_len = DEFAULT_INCREASE_LEN;
    //分配内存空间
    header->r_array = (p_super_array_node)malloc(sizeof(super_array_node)* \
        header->total_len);
    if( header->r_array == NULL )
        return 1;
    print_dbg("super_array_node alloc OK\n");

    //初始化空节点管理链表,倒着初始化:方便取数据时，从数组正向开始取
    //0节点为super_array的尾部

    //初始化空闲节点链表
    for(i=header->total_len-1; i>0; i--) {
        rtn = list_insert_node(&header->freelist, i);
        if(rtn != 0)
            return rtn;
    }
    return 0;
}

/**
* return value:
* 0: success , 1: no memory space, 2: null
*/
//从头开始插入
int insert_node(p_super_array_header header, int data, int* index)
{
    int i;
    int tmp;
    int rtn;
    p_super_array_node r_array;
    if(header == NULL)
        return 2;

    //增加存储空间
    if(header->len + 1 > header->total_len) {
        tmp = header->total_len;
        header->total_len += header->total_len + header->increase_len;
        header->r_array = (p_super_array_node)realloc(header->r_array, \
            sizeof(super_array_node) * header->total_len);
        if(header->r_array == NULL) {
            print_dbg("alloc memory failed\n");
            return 1;
        }
        //初始化刚分配的存储空间，放置于空闲链表中
        for(i=header->total_len; i>=tmp; i--) {
            rtn = list_insert_node(&header->freelist,i);
            if(rtn != 0)
                return rtn;
        }
    }
    ///获取空闲节点
    rtn = list_pick_node(&header->freelist, index);
    if(rtn != 0) {
        print_dbg("Get free node failed, err is %d\n",rtn);
        return rtn;
    }

    r_array = header->r_array;
    //数据插入节点
    r_array[*index].data = data;
    r_array[*index].valid = 1;
    //将节点插入supper_array的头
    r_array = header->r_array;
    r_array[header->first].previous = *index;
    //super_array的第一个节点的previous设置为 -1
    r_array[*index].previous = -1;
    r_array[*index].next = header->first;
    header->first = *index;
    header->len += 1;

    print_dbg("inset data in the head of list, index: %d, data: %d\n", \
         header->first, data);

    return 0;
}

/**
* return value:
* 0: success 1:out of range 2: no such node
*/
int delete_node_by_index(p_super_array_header header, int index)
{
    int tmp_previous;
    int tmp_next;

    p_super_array_node r_array = header->r_array;
    if(index >= header->total_len) {
        print_dbg("failed: index out of range");
        return 1;
    }
    if(r_array == NULL)
        return 1;
    if(r_array[index].valid == 0) {
        print_dbg("the %drd data is nonvalid", index);
        return 2;
    }

    //delete the node
    r_array[index].valid = 0;
    tmp_next = r_array[index].next;
    tmp_previous = r_array[index].previous;
    r_array[tmp_next].previous = tmp_previous;
    r_array[tmp_previous].next = tmp_next;
    header->len -= 1;
    return 0;
}
/**
* descprition: delete super_array by list mothod
*/
int delete_node_by_list(p_super_array_header header)
{
    // to do
    return 0;
}


/**
* 通过链表方式遍历整个super_array数据结构,并实现出来
*/
int get_datas_by_list(p_super_array_header header)
{
    int tmp_index = header->first;
    p_super_array_node r_array = header->r_array;

    while(tmp_index != 0) {
        printf("data is %d next->index=%d\n", r_array[tmp_index].data, tmp_index);
        tmp_index = r_array[tmp_index].next;
    }
    return 0;
}


/**
*  获取super_array 有效长度
*/
int get_super_array_len(p_super_array_header header)
{
    return header->len;
}

/**
* 获取super_array的总长度
*/
int get_super_array_total_len(p_super_array_header header)
{
    return header->total_len;
}

/**
* return vale:
* 0: success , 1: out of range 2: nonvalides
*/
int get_data_by_index(p_super_array_header header, int* data, int index)
{
    if(index >= header->total_len)
        return 1;
    if(header->r_array[index].valid == 0)
        return 2;
    *data = header->r_array[index].data;
    return 0;
}