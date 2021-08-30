#include <iostream>
#include "LinearList.h"

int main(void){
    vector<int> array1, array2, array3, array4,
                array5, array6, array7, array8,
                arrayD, arrayE;
    array1 = {1, 3, 4, 6, 8, 9, 0, 11, 45, 67, 28, 32, 61, 222};
    array2 = {2, 4, 7, 9, 1, 3};
    array3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60};
    array4 = {1, 3, 5, 6, 9};
    array5 = {1, 2, 4, 7, 9, 10};
    array6 = {2, 4, 6, 12, 13, 20};
    array7 = {2, 12, 20, 45};
    array8 = {1, 1, 2, 2, 2, 3, 4, 4, 7, 7, 9};
    arrayD = {1, 3, 5};
    arrayE = {2, 4, 6};
    LinearList list1(array1), list2(array2), list3(array3), list4(array4), 
               list5(array5), list6(array6), list7(array7), list8(array8);
    LinearList A, B;
    LinearList C, D(arrayD), E(arrayE);
    cout << "第一题测试：" << endl;
    list1.Search_element(5);
    list1.Search_element(list1.length);
    list1.Search_element(0);
    list1.Search_element(list1.length+1);
    list1.Search_element(list1.length+2);
    cout << "第2题测试：" << endl;
    list2.Inseret_node(0,100);
    list2.Travellist();
    cout << "第3题测试：" << endl;
    list3.Delete_node(0);
    list3.Travellist();
    cout << "第4题测试：" << endl;
    list4.Add_element(8);
    list4.Travellist();
    cout << "第5题测试：" << endl;
    list5.Separate_list(A, B);
    list5.Travellist();
    A.Travellist();
    B.Travellist();
    cout << "第6题测试：" << endl;
    C.Public_element(list6, list7);
    C.Travellist();
    cout << "第7题测试：" << endl;
    list8.Delete_same_element();
    list8.Travellist();
    cout << "附加题测试：" << endl;
    cout << C.MidNumber(D, E);
    return 0;
}
