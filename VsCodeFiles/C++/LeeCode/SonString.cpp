//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0,j,k,max = 0,len;
        for(j=i;j<s.size();j++){
            for(k=i;k<j;k++){
                if(s[k]==s[j]){
                    len = j-i;
                    if(len > max) max =len;
                    i = k+1;
                    break;
                }
            }
        }
        return j-i>max?j-i:max;
        
    }
};
int main(void){
    Solution way1;
    string temp = "pwwkew";
    cout << way1.lengthOfLongestSubstring(temp);
    return 0;
}