#include "super_array.h"
int main()
{
    int rtn;
    int index;
    int data;
    //case 1: test program can output something
    printf("weijinhua\n");
    //case 2:初始化链表，插入数据，取出相应文章数据，并打印
    super_array_header header;
    p_super_array_header pheader = &header;

    rtn = super_array_init(pheader);
    if(rtn != 0) {
        printf("super_array_init failed\n");
        return rtn;
    }
    rtn = insert_node(pheader, 1, &index);
    if(rtn !=0 ) {
        printf("super_array insert_node failed , error:%d\n",rtn);
        return rtn;
    }
    printf("index=%d\n",index);

    rtn = get_data_by_index(pheader, &data, index);
    if(rtn != 0) {
        printf("super_array get_data_by_index failed , error:%d\n", rtn);
    }
    printf("data=%d\n",data);
    return 0;
}
