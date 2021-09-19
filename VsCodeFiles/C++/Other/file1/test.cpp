#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void){
    // string s;
    // s[0]='i';
    // cout << s;
    // return 0;
    vector<int> str;
    for(char ch = 'a'; ch < 'z' + 1; ch++){
        str[ch-'a'] = ch;
    }
    cout << str.size();
    return 0;
}