#include "super_array.h"

/**
* test case 1:初始化super_array，插入数据，取出相应文章数据，并打印
*/
int testcase1()
{
    int err;
    printf("========testcase1=========");

    printf("\n\n");
    return 0;
}
/**
* test case 2:初始化super_array，插入数据，取出相应文章数据，并打印
*/
int testcase2()
{
    int err;
    printf("========testcase2=========");
    printf("\n\n");
    return 0;
}

/**
* test case 3:初始化super_array，插入数据，取出相应文章数据，并打印
*/
int testcase3()
{
    int err;
    printf("========testcase3=========");
    printf("\n\n");
    return 0;
}
int main()
{
    int rtn;
    int index;
    int data;
    int tmp;
    super_array_header header;
    p_super_array_header pheader = &header;

    printf("==============testcase1=================\n");
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

    printf("===============testcase2=====================\n");
    //test case 2:获取super_array 长度，并删除 super_array中的节点
    printf("len of super_array is %d\n", get_super_array_len(pheader));

    tmp = 2;
    rtn = insert_node(pheader, tmp, &index);
    printf("len of super_array is %d\n", get_super_array_len(pheader));
    printf("index=%d\n",index);
    //rtn = delete_node(pheader, index);

    printf("len of super_array is %d\n", get_super_array_len(pheader));

    printf("==============显示supper_array数据===============\n");
    get_datas_by_list(pheader);

    return 0;
}
