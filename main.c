#include "super_array.h"

int main()
{
    int rtn;
    int index;
    int data;
    int tmp;
    super_array_header header;
    p_super_array_header pheader = &header;

    //test case 1:初始化super_array，插入数据，取出相应文章数据，并打印
    rtn = super_array_init(pheader);
    if(rtn != 0) {
        printf("super_array_init failed\n");
        return rtn;
    }
    tmp = 2;
    rtn = insert_node(pheader, tmp, &index);
    if(rtn !=0 ) {
        printf("super_array insert_node failed , error:%d\n",rtn);
        return rtn;
    }
    rtn = get_data_by_index(pheader, &data, index);
    if(rtn != 0) {
        printf("super_array get_data_by_index failed , error:%d\n", rtn);
    }
    printf("testcase 1: insert position:%d write_data=%d read_data:%d\n", \
            index, tmp, data);

    //test case 2:获取super_array 长度，并删除 super_array中的节点

    return 0;
}
