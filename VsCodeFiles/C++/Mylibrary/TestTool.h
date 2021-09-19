#include <iostream>

/*
输出顺序容器:
    array   静态的连续数组
    vector  动态的连续数组
    deque   双端队列
    forward_list    单链表
    list    双链表
所有元素    
*/
template<typename T>
void printContainer(T t){
     for (auto element : t) {
        std::cout << ' ' << element;
    }
    std::cout << "\n";
}
