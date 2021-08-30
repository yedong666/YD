/*给定一个整数数组 nums?和一个整数目标值 target，请你在该数组中找出 和为目标值 的那?两个?整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
你可以按任意顺序返回答案。*/
#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vx(2);
        int iflag=0;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
                for(int j = i+1; j < n; j++){
                    if(nums[j] == target - nums[i]){
                        vx[0] = i;
                        vx[1] = j;
                        iflag = 1;
                        break;
                    }
                
                }
            if(iflag==1){
                break;
            }
        }
        return vx;
    }
};
int main(void){
    vector<int> vy = {-1, -2, -3, -4, -5};
    vector<int> vx(2);
    Solution ways;
    vx = ways.twoSum(vy, -8);
    cout << vx[0] << " " << vx[1];
    return 0;
}
