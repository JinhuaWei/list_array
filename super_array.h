#include <stdio.h>
#include "link_int.h"

//#define DEBUG
#ifdef DEBUG
#define print_dbg(format, args...)\
    printf("%s:%d "format"\n", __FILE__, __LINE__, ##args)
#else
#define print_dbg(format, args...) {}
#endif

#define DEFAULT_INIT_LEN 64
#define DEFAULT_INCREASE_LEN 64

typedef struct super_array_node {
    int next;
    //the previous of first node is set -1
    int previous;
    //1:有效，0：无效
    int valid;
    //暂时使用int类型的数据，
    //void*类型 存储任意数据类型
    void* data;
} super_array_node, * p_super_array_node;

typedef struct super_array_header {
    //节点的第一个头
    int first;
    //使用的存储空间
    //int r_len;
    //总的存储空间
    int total_len;
    //已使用的长度
    int len;
    //每次增长的长度
    int increase_len;
    //super_array的存储空间
    p_super_array_node r_array;
    //节点空闲链表
    link_node freelist;

}super_array_header, *p_super_array_header;

int super_array_init(p_super_array_header header);

int get_data_by_index(p_super_array_header header, void* data, int index, \
                int(*get_data)(super_array_node* node, void* data));

int insert_node(p_super_array_header header, void* data, int* index, \
                int(*store_data)(super_array_node* node, void* data));
int delete_node_by_index(p_super_array_header header, int index, \
            int(*free_data)(super_array_node* node));
    int tmp_previous;
int get_super_array_len(p_super_array_header header);
int get_super_array_total_len(p_super_array_header header);
int get_datas_by_list(p_super_array_header header, void(*show_data)(void* data));
int delete_node_by_match(p_super_array_header header, int (*func)(void* , void*), void* data, \
            int(*free_data)(super_array_node* node));
int modify_node_by_match(p_super_array_header header, int (*func_match)(void* , void*), \
                        void* src_data, void* dst_data, int(*modify_node)(void* , void*));
