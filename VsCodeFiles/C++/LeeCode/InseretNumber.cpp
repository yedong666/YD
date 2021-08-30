//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
//如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//你可以假设数组中无重复元素。
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::vector;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int Max, Min, Mid;
       Max = nums.size() - 1;
       Min = 0;
       int iflag, i;
       while(Min<=Max){
           //注意：一定得是<=, 而不能用!=
           //不然可能会出现死循环
            Mid = (Max+Min)/2;
           if(target == nums[Mid]){
               return Mid;
           }
           else if(target > nums[Mid]){
               Min = Mid+1;
           }
           else{
               Max = Mid-1;
           }
       }
       return Min;
    }
};
//思路：二分查找
int main(void){
    vector<int> myarray = {3, 5, 7, 9, 10};
    int number1 = 8;
    int number2 = 10;
    Solution ways1;
    cout << ways1.searchInsert(myarray, number1);
    return 0;
}