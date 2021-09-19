//主函数，运行实例测试
#include "LinearList.h"
int main(void){
    vector<int> array = {1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 6};
    vector<int> newarray = {1, 4, 2, 1, 5, 6, 4, 5};
    vector<int> testarray1 = {1, 2, 5, 7, 8, 9};
    vector<int> testarray2 = {2, 4, 5, 6, 9};
    LinearList list(array);
    LinearList newlist(newarray);
    LinearList list1(testarray1);
    LinearList list2(testarray2);
    PutList(DeleteAE(newlist));
    PutList(DeleteOrdedAE(list));
    PutList(ordered_IntersectSet(list1, list2));
    PutList(ordered_UnionSet(list1, list2));
    PutList(ordered_MinusSet(list1, list2));
    return 0;
}