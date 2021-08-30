/*
给定长度为?2n?的整数数组 nums ，你的任务是将这些数分成?n 对,
例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从 1 到?n 的 min(ai, bi) 总和最大。

ege1:输入：nums = [1,4,3,2]
输出：4
解释：所有可能的分法（忽略元素顺序）为：
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
所以最大总和为 4

ege2:输入：nums = [6,2,6,5,1,2]
输出：9
解释：最优的分法为 (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int arraynumsairSum(vector<int>& nums) {
        int SIZE = nums.size();
        int i, MaxSum = 0;
        Quicklysort(nums,0,SIZE);
        for(i=0; i<SIZE; i+=2){
            MaxSum += nums[i];
        }
        return MaxSum;
    }
    void Quicklysort(vector<int>& nums,int left, int right){
        int i=left, j=right;
        int mid=nums[i];
        if(left>=right){
        return;
        }
        while(i<j){
            while(nums[j]>=mid&&i<j){
                j--;
            }
            nums[i]=nums[j];
            while(nums[i]<=mid&&i<j){
                i++;
            }
            nums[j]=nums[i];
    }
    nums[i]=mid;
    Quicklysort(nums,left,i-1);
    Quicklysort(nums,i+1,right);
    return;
    }
};
int main(void){
    Solution ways1;
    int MaxSum;
    vector <int> nums = {1, 4, 3, 2};
    MaxSum = ways1.arraynumsairSum(nums);
    cout << "The max sum is " << MaxSum << endl;
    return 0;
}
