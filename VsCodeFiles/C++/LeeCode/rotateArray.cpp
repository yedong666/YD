#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
    eg: 输入: nums = [1,2,3,4,5,6,7], k = 3
        输出: [5,6,7,1,2,3,4]
    解释:
        向右旋转 1 步: [7,1,2,3,4,5,6]
        向右旋转 2 步: [6,7,1,2,3,4,5]
        向右旋转 3 步: [5,6,7,1,2,3,4]
    思路：分段翻转数组
*/ 


void swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

/**
 * @brief:逆置数组left到right之间的元素顺序
 **/
void reverseArray(vector<int> &nums, int start, int end){
    while(start < end){
        swap(nums[start++], nums[end--]);
    }
}

void rotateArray(vector<int> &nums, int k){
    int len = nums.size();
    k %= len;
    //先逆置整个数组
    reverseArray(nums, 0, len-1);
    //再逆置0到k-1之间的元素
    reverseArray(nums, 0, k-1);
    //在逆置k到len-1之间的元素
    reverseArray(nums, k, len-1);
}

int main(void){
    vector<int> testArray = {1, 2, 3, 4, 5, 6, 7};
    rotateArray(testArray, 3);
    for(int i = 0; i < testArray.size(); i++){
        cout << testArray[i] << " ";
    }
    return 0;
}
