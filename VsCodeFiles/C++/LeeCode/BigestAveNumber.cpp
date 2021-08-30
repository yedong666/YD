//给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数
#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int ktemp = k - 1;
        double Ave;
        double Sum = 0.0;
        double Sumtemp;
        for(int i = 0; i < k; i++){
            Sum += nums[i];
        }
        Sumtemp = Sum;
        for(int i = 1; i <= n-k; i++){
            Sumtemp += nums[ktemp + i];
            Sumtemp -= nums[i-1];
            if (Sumtemp > Sum){
                Sum = Sumtemp;
            }
        }
        Ave = Sum / (double)k;
        return Ave;
    }
};
int main(void){
    Solution ways;
    vector <int> nums = {0,1,1,3,3};
    cout << ways.findMaxAverage(nums, 4);
    return 0;
}