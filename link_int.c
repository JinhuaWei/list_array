#include <stdlib.h>
#include <stdio.h>
#include "link_int.h"
/**
* return:
* 0: success , 1 : header none, 2: no memory
*/
//int data 可以改写为 void* data，使其更加通用
int list_insert_node(p_link_node header, int data)
{
    p_link_node pnode = NULL;
    /*
    if(header != NULL)
        return 1;
    */
    pnode = (p_link_node)malloc(sizeof(link_node));
    if(pnode == NULL)
        return 2;
    pnode->data = data;
    pnode->next = header->next;
    header->next = pnode;
    //printf("weijinhua");
    return 0;
}
//摘取头部数据，并将节点从链表中擦除
//return
// 1: no memory spacee , 0: success
int list_pick_node(p_link_node header, int* data)
{
    p_link_node tpnode;
    tpnode = header->next;
    if (tpnode == NULL)
        return 1;
    header->next = tpnode->next;
    *data = tpnode->data;
    free(tpnode);
    return 0;
}