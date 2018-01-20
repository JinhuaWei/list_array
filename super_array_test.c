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
    //插入、获取数据，并进行对比测试
    rtn = super_array_init(pheader);
    if(rtn != 0) {
        printf("super_array_init failed\n");
    }
    tmp = 2;
    rtn = insert_node(pheader, tmp, &index);
    if(rtn !=0 ) {
        printf("super_array insert_node failed , error:%d\n",rtn);
    }
    rtn = get_data_by_index(pheader, &data, index);
    if(rtn != 0) {
        printf("super_array get_data_by_index failed , error:%d\n", rtn);
    }
    printf("testcase 1: insert position:%d write_data=%d read_data:%d\n", \
            index, tmp, data);
    if(rtn != 0 || tmp != data) {
        printf("testcase1 test failed\n");
    }
    printf("\n\n");


    printf("===============testcase2=====================\n");
    //test case 2:测试super_array的增删是否正确,插入2、3、5三个数据
    printf("len of super_array before insert : %d\n", get_super_array_len(pheader));
    rtn = insert_node(pheader, 2, &index);
    rtn = insert_node(pheader, 3, &index);
    rtn = insert_node(pheader, 5, &index);
    printf("len of super_array after insert : %d\n", get_super_array_len(pheader));
    if(rtn != 0 ) {
        printf("testcase2 test failed\n");
    }
    printf("显示supper_array数据：\n");
    get_datas_by_list(pheader);
    printf("\n\n");

    printf("===============testcase3=====================\n");
    //testcase 3：查找并删除中的节点, 查找并修改节点
    //printf();

    return 0;
}
