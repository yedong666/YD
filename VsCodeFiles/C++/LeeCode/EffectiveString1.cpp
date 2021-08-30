/*给定一个只包括 '('，')'，'{'，'}'，'['，']'?的字符串 s ，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        string stringx;
        int i=0,j=-1;
        while(i<s.size())
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                stringx+=s[i];
                j++;
            }
            else if(s[i]==')'&&j>-1){
                if(stringx[j]!='('){
                    return false;
                }
                else{
                    stringx.erase(j);
                    j--;
                }
            }
            else if(s[i]==']'&&j>-1){
                if(stringx[j]!='['){
                    return false;
                }
                else{
                    stringx.erase(j);
                    j--;
                }
            }
            else if(s[i]=='}'&&j>-1){
                if(stringx[j]!='{'){
                    return false;
                }
                else{
                    stringx.erase(j);
                    j--;
                }
            }
            else{
                return false;
            }
            i++;   
        }
        if(j==-1){
            return true;
        }
        else{  
            return false;
        }
    }
};
int main(void)
{
    Solution x;
    string str="(";
    int a;
    a=x.isValid(str);
    cout << a;
    return 0;
}