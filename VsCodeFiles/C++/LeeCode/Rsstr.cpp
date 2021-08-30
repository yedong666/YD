//给你一个字符串 s，找到 s 中最长的回文子串。
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//1.暴力求解
class Solution1 {
public:
    string longestPalindrome(string s) {
        int i, j;
        int ileft=0, iright=0;
        int maxlength = 0;
        for(i=0; i<s.size(); i++){
            for(j=i+1; j<s.size(); j++){
                if(isRestr(s,i,j) && j - i + 1> maxlength){
                    ileft = i;
                    iright = j;
                    maxlength = j -i + 1;
                }
            }
        }
        string newstr;
        newstr.assign(s, ileft, iright-ileft+1);
        return newstr;    
    }

    bool isRestr(string s, int a, int b){
        while(s[a]==s[b] && a<=b){
            a++;
            b--;
        }
        if(a>b){
            return true;
        }
        else{
            return false;
        }

    }
};

//动态规划
class Solution2 {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0||len==1)
            return s;
        int start=0;//回文串起始位置
        int max=1;//回文串最大长度
        vector<vector<int>>  dp(len,vector<int>(len));//定义二维动态数组
        for(int i=0;i<len;i++)//初始化状态
        {
            dp[i][i]=1;
            if(i<len-1&&s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                max=2;
                start=i;
            }
        }
        for(int l=3;l<=len;l++)//l表示检索的子串长度，等于3表示先检索长度为3的子串
        {
            for(int i=0;i+l-1<len;i++)
            {
                int j=l+i-1;//终止字符位置
                if(s[i]==s[j]&&dp[i+1][j-1]==1)//状态转移
                {
                    dp[i][j]=1;
                    start=i;
                    max=l;
                }
            }
        }
        return s.substr(start,max);//获取最长回文子串
    }
};

int main(void){
    string str="ccc";
    Solution1 way;
    cout << way.longestPalindrome(str) << endl;
    return 0;
}