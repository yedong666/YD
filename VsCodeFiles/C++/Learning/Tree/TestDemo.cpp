#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

void f(char *s, int i){
    if (s[i] != '#'){
        f(s, 2*i);
        cout << s[i];
        f(s, 2*i + 1);
    }
}

int main(void){
   char s[16] = {'#', '1', '2', '3', '4', '5', '6', '7', '#', '#', '#', '#', '#', '#', '#', '#'};
   f(s,1);
   return 0;
}  
