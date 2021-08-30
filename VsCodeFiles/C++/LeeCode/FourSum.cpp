/*
给定一个包含?n 个整数的数组?nums?和一个目标值?target，判断?nums?中是否存在四个元素 a，b，c?和 d?，
使得?a + b + c + d?的值与?target?相等？找出所有满足条件且不重复的四元组。
注意：答案中不可以包含重复的四元组。
示例 1：
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
示例 2：
输入：nums = [], target = 0
输出：[]
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       
    }
};
int main(void){
    Solution way;
    vector<int> myarray;
    return 0;
}
/*
最朴素的方法是使用四重循环枚举所有的四元组，然后使用哈希表进行去重操作，得到不包含重复四元组的最终答案。假设数组的长度是 nn，则该方法中，枚举的时间复杂度为 O(n^4)O(n 
4
 )，去重操作的时间复杂度和空间复杂度也很高，因此需要换一种思路。

为了避免枚举到重复四元组，则需要保证每一重循环枚举到的元素不小于其上一重循环枚举到的元素，且在同一重循环中不能多次枚举到相同的元素。

为了实现上述要求，可以对数组进行排序，并且在循环过程中遵循以下两点：

每一种循环枚举到的下标必须大于上一重循环枚举到的下标；

同一重循环中，如果当前元素与上一个元素相同，则跳过当前元素。

使用上述方法，可以避免枚举到重复四元组，但是由于仍使用四重循环，时间复杂度仍是 O(n^4)O(n 
4
 )。注意到数组已经被排序，因此可以使用双指针的方法去掉一重循环。

使用两重循环分别枚举前两个数，然后在两重循环枚举到的数之后使用双指针枚举剩下的两个数。假设两重循环枚举到的前两个数分别位于下标 ii 和 jj，其中 i<ji<j。初始时，左右指针分别指向下标 j+1j+1 和下标 n-1n?1。每次计算四个数的和，并进行如下操作：

如果和等于 \textit{target}target，则将枚举到的四个数加到答案中，然后将左指针右移直到遇到不同的数，将右指针左移直到遇到不同的数；

如果和小于 \textit{target}target，则将左指针右移一位；

如果和大于 \textit{target}target，则将右指针左移一位。

使用双指针枚举剩下的两个数的时间复杂度是 O(n)O(n)，因此总时间复杂度是 O(n^3)O(n 
3
 )，低于 O(n^4)O(n 
4
 )。

具体实现时，还可以进行一些剪枝操作：

在确定第一个数之后，如果 \textit{nums}[i]+\textit{nums}[i+1]+\textit{nums}[i+2]+\textit{nums}[i+3]>\textit{target}nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target，说明此时剩下的三个数无论取什么值，四数之和一定大于 \textit{target}target，因此退出第一重循环；
在确定第一个数之后，如果 \textit{nums}[i]+\textit{nums}[n-3]+\textit{nums}[n-2]+\textit{nums}[n-1]<\textit{target}nums[i]+nums[n?3]+nums[n?2]+nums[n?1]<target，说明此时剩下的三个数无论取什么值，四数之和一定小于 \textit{target}target，因此第一重循环直接进入下一轮，枚举 \textit{nums}[i+1]nums[i+1]；
在确定前两个数之后，如果 \textit{nums}[i]+\textit{nums}[j]+\textit{nums}[j+1]+\textit{nums}[j+2]>\textit{target}nums[i]+nums[j]+nums[j+1]+nums[j+2]>target，说明此时剩下的两个数无论取什么值，四数之和一定大于 \textit{target}target，因此退出第二重循环；
在确定前两个数之后，如果 \textit{nums}[i]+\textit{nums}[j]+\textit{nums}[n-2]+\textit{nums}[n-1]<\textit{target}nums[i]+nums[j]+nums[n?2]+nums[n?1]<target，说明此时剩下的两个数无论取什么值，四数之和一定小于 \textit{target}target，因此第二重循环直接进入下一轮，枚举 \textit{nums}[j+1]nums[j+1]。

*/