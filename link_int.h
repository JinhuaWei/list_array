#include <stdlib.h>
typedef struct link_node {
    int data;
    struct link_node* next;
} link_node, *p_link_node;


int list_insert_node(p_link_node header, int data);
//摘取头部数据，并将节点从链表中擦除
int list_pick_node(p_link_node header, int* data);