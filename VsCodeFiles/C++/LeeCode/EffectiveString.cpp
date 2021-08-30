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
        string string1, string2, string3;
        int i=0;
        while(i<s.size())
        {
            if(s[i]=='('){
                string1=string1+s[i];
            }
            else if(s[i]=='{'){
                string2=string2+s[i];
            }
            else if(s[i]=='['){
                string3=string3+s[i];
            }
            else{
                if(string1.size()!=0&&s[i]==')'&&(i-s.find(string1[string1.size()-1]))%2==1){
                    if(string1.size()){
                       string1.erase(string1.end()-1); 
                    }
                    else{
                        return false;
                    }
                }
                else if(string2.size()!=0&&s[i]=='}'&&(i-s.find(string2[string2.size()-1]))%2==1){
                    if(string2.size()){
                       string2.erase(string2.end()-1); 
                    }
                    else{
                        return false;
                    }
                }
                else if(string3.size()!=0&&s[i]==']'&&(i-s.find(string3[string3.size()-1]))%2==1){
                    if(string3.size()){
                       string3.erase(string3.end()-1); 
                    }
                    else{
                        return false;
                    }    
                }
                else{
                    return false;
                }   
            }
            i++;    
        }
        if(string1.size()==0&&string2.size()==0&&string3.size()==0){
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
    string str="(]";
    int a; 
    a=x.isValid(str);
    cout << a;
    return 0;
}