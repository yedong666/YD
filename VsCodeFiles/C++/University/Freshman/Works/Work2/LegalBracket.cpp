#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool Legalbracket(char *input){
    vector<char> str(100);
    char ch;
    int i = 0, j = 0;
    while(input[i] != '\0'){
        ch = input[i++];
        if (ch == '{' || ch == '[' ||ch == '('){
            str[j] = ch;
            j++;
        }
        else if(ch == '}' || ch == ']' ||ch == ')'){
            if (ch-str[j-1] < 3 && ch - str[j-1] > -3){
                j--;
            }
            else {
                str[j++] = ch;
            }
        }
        else {}
    }
    if (j==0){
        cout << "输入表达式中括号合法！" << endl;
        return true;
    }
    else{
        cout << "输入表达式中括号不合法！" << endl;
        return false;
    }
}

int main(void){
    char *input = new char[100];
    cout << "请输入表达式：" << endl;
    gets(input);
    Legalbracket(input);
    return 0;
}