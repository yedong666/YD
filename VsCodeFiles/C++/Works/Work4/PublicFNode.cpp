#include <iostream>
using namespace std;

int PublicFNode(int i, int j);

int main(void){
    int i = 8, j = 9;
    cout << "编号为" << i << "与编号为" << j << "的最近公共祖先结点编号为" << PublicFNode(i, j) << endl;
    return 0;
}

int PublicFNode(int i, int j){
    while(i != j){
        if (i>j){
            i /= 2;
        }
        else {
            j /= 2;
        }
    }
    return i;
}