/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行?Z 字形排列。
比如输入字符串为 "PAYPALISHIRING"?行数为 3 时，排列如下：
P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
请你实现这个将字符串进行指定行数变换的函数：
string convert(string s, int numRows);
输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"
*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        string str[numRows];
        int n=0,dir=1;
        for(int i=0;i<s.size();++i){
            if(n==numRows-1)dir=-1;
            if(n==0)dir=1;
            str[n]+=s[i];
            n+=dir;
        }
        for(int i=1;i<numRows;++i){
            str[0]+=str[i];
        }
        return str[0];
    }
};
class Solution1 {
public:
    string convert(string s, int numRows) {
        char **chrow, *chline;
        string news;
        chrow = new char* [numRows];
        int line = s.size()/numRows*2;
        for(int i = 0; i<numRows; i++){
            chrow[i] = new char [line];
        }
        for(int i = 0; i<numRows; i++){
            for(int j=0; j<line; j++){
                chrow[i][j] = ' ';
            }
        }
        for(int i; i<s.size(); i++){
            int a, b, c, d, e;
            a = i/(numRows-1);
            d = a*(numRows-1);
            b = d%2;
            c = i%(numRows-1);
            if(!b){
                e = d/2;
                chrow[c][e]=s[i];
            }
            else{
                e = d/2-1;
                chrow[numRows-1+c][e+c];
            }
        }
        int x=0;
        for(int i = 0; i<numRows; i++){
            for(int j=0; j<line; j++){
                if(chrow[i][j]!=' ')
                news[x]= chrow[i][j];
            }
        }
        return news;

    }
};
int main(void){
    Solution way;
    string s="1234567";
    cout << way.convert(s, 3);
    return 0;
}
