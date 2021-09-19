#include "../TestTool.h"
#include <vector>
#include <array>
#include <deque>
#include <list>

int main(void){
    std::vector<int> testArray1 = {1, 2, 3, 4, 5, 6};
    printContainer(testArray1);
    std::array<int, 5> testArray2 = {1, 2, 3, 4, 5};
    printContainer(testArray2);
    std::deque<int> queue1;
    for(int i = 0; i < 5; i++){
        queue1.push_back(i);
    }
    printContainer(queue1);
    
    return 0;
}