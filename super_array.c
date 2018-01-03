#include <stdlib.h>
#include "super_array.h"

#define DEFAULT_INIT_LEN 64
#define DEFAULT_INCREASE_LEN 64

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
    header->r_array_pace = (p_super_array_node)malloc(sizeof(super_array_node)* \
        header->total_len);
    if( header->r_array_pace == NULL )
        return 1;
    print_dbg("super_array_node alloc ok\n");
    //初始化空节点管理链表,倒着初始化:方便取数据时，从数组正向开始取
    //0节点为super_array的尾部
    for(i=header->total_len-1; i>0; i--) {
        rtn = list_insert_node(&header->freelist, i);
        if(rtn != 0)
            return rtn;
    }
    //header->r
    return 0;
}
/**
* return value:
* 0: success , 1: no memory space, 2: null
*
*/
//从头开始插入
int insert_node(p_super_array_header header, int data, int* index)
{
    int i;
    int tmp;
    int rtn;
    p_super_array_node r_array_pace;
    if(header == NULL)
        return 2;
    print_dbg("len=%d total_len=%d", header->len, header->total_len);
    if(header->len >= header->total_len) {
        tmp = header->total_len;
        header->total_len += header->total_len + header->increase_len;
        header->r_array_pace = (p_super_array_node)realloc(header->r_array_pace, \
            sizeof(super_array_node) * header->total_len);
        if(header->r_array_pace == NULL) {
            return 1;
        }
        for(i=header->total_len; i>=tmp; i--) {
            rtn = list_insert_node(&header->freelist,i);
            if(rtn != 0)
                return rtn;
        }
    }
    rtn = list_pick_node(&header->freelist, index);
    if(rtn != 0) {
        print_dbg("rtn=%d",rtn);
        return rtn;
    }
    print_dbg("index->%d", *index);
    r_array_pace = header->r_array_pace;
    //数据插入节点
    r_array_pace[*index].data = data;
    r_array_pace[*index].valid = 1;
    //节点插入使用super_array
    r_array_pace = header->r_array_pace;
    r_array_pace[header->first].previous = *index;
    //super_array的第一个节点的previous设置为 -1
    r_array_pace[*index].previous = -1;
    r_array_pace[*index].next = header->first;
    /*
    if(header->len == 0)
        r_array_pace[*index].previous = -1;
    */
    header->len += 1;
    header->first=*index;
    return 0;
}

/**
* return value:
* 0: success 1:out of range 2: no such node
*/
int delete_node(p_super_array_header header, int index)
{
    int tmp_previous;
    int tmp_next;
    p_super_array_node r_array = header->r_array_pace;
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
    r_array[index].valid = 0;
    tmp_next = r_array[index].next;
    r_array[tmp_next] = tmp_previous;
    r_array[tmp_previous].next = tmp_next;
/**
    tmp_previout = r_array[index].previous;
    r_array[r_array[index].previous].next = r_array[r_array[index].next].next;
    r_array[r_array[index].previous].index = r_array[r_array[index].next].next;
*/

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
    return header->header;
}

/**
* return vale:
* 0: success , 1: out of range 2: nonvalides
*/
int get_data_by_index(p_super_array_header header, int* data, int index)
{
    if(index >= header->total_len)
        return 1;
    if(header->r_array_pace[index].valid == 0)
        return 2;
    *data = header->r_array_pace[index].data;
    return 0;
}