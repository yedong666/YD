//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int i=0, j=0, k=0;
            int a = nums1.size();
            int b = nums2.size();
             int myarray[a+b];
            while(i<a&&j<b){
                if(nums1[i]>nums2[j]){
                    myarray[k] = nums2[j];
                    j++;
                }
                else{
                    myarray[k] = nums1[i];
                    i++;
                }
                k++;
            }
            if(i==a){
                for(j; j<nums2.size(); j++){
                    myarray[k] = nums2[j];
                    k++;
                }
            }
            if(j==b){
                for(i; i<nums1.size(); i++){
                    myarray[k] = nums1[i];
                    k++;
                }
            }
           double midnumber;
           if((a+b)%2==0){
               midnumber = (myarray[(a+b)/2] + myarray[(a+b)/2-1])/2.0;
           }
           else{
               midnumber = (double)myarray[(a+b)/2];
           }
           return midnumber;
            
            
    }
};

int main(void){
    vector<int> test1 = {1, 2}, test2 = {3, 4};
    Solution way;
    cout << way.findMedianSortedArrays(test1, test2);
    return 0;
}