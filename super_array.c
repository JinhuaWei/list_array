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
    header->first = 0;
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
    for(i=header->total_len-1; i>=0; i--) {
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
int insert_node(p_super_array_header header, int data, int* index)
{
    int i;
    int tmp;
    int rtn;
    p_super_array_node r_array_pace;
    if(header == NULL)
        return 2;
    print_dbg("len=%d total_len=%d\n", header->len, header->total_len);
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
        print_dbg("rtn=%d\n",rtn);
        return rtn;
    }
    print_dbg("index->%d\n", *index);
    r_array_pace = header->r_array_pace;
    //数据插入节点
    r_array_pace[*index].data = data;
    r_array_pace[*index].valid = 1;
    //节点插入使用super_array
    r_array_pace = header->r_array_pace;
    r_array_pace[*index].next = header->first;
    header->first=*index;
    return 0;
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