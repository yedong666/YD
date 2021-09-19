#include <iostream>
#include <windows.h>
#include <ctime>
#include <vector>
#include <stack>
using namespace std;

typedef struct Index{
    int x;
    int y;
}Index;

void fun1(int **&array, int a, int b, int n, int v){
    int i = a;
    int j = b;

    for(i; i < n; i++){
        if (array[i][b] == -1)
            array[i][b] = v;
    }

    // for(j; j < n; j++){
    //     array[a][j] = v;
    // }

    i = a;
    j = b;
    while(i < n && j < n) {
        if (array[i][j] == -1)
            array[i][j] = v;
        i++;
        j++;
    }

    i = a;
    j = b;
    while(i < n && j >= 0){
        if (array[i][j] == -1)
            array[i][j] = v;
        i++;
        j--;
    }
}

void fun2(int **&array, int a, int b, int n, int v){
    int i = a;
    int j = b;

    for(i; i < n; i++){
        if (array[i][b] == v)
            array[i][b] = -1;
    }

    i = a;
    j = b;
    while(i < n && j < n) {
        if (array[i][j] == v)
            array[i][j] = -1;
        i++;
        j++;
    }

    i = a;
    j = b;
    while(i < n && j >= 0){
        if (array[i][j] == v)
            array[i][j] = -1;
        i++;
        j--;
    }
}


void getIndex(stack<Index> &s, vector<Index> &Indexs){
    while(!s.empty()){
        Indexs.push_back(s.top());
        s.pop();
    }
}

int k = 0;
void test(int **&array, vector<vector<Index>> &allIndexs, int n, int t, stack<Index> &tempIndex){
    if (n == t){
        vector<Index> vt;
        while(!tempIndex.empty()){
            //cout << tempIndex.top().x << "," << tempIndex.top().y << "  ";
            vt.push_back(tempIndex.top());
            tempIndex.pop();
        }

        for(int i = vt.size()-1; i > -1; i--){
            tempIndex.push(vt[i]);
        }

        //cout << endl;
        allIndexs.push_back(vt);
    }
    else{
        for(int i = 0; i < n; i++){
            if (array[t][i] == -1){
                Index index;
                index.x = t;
                index.y = i;
                tempIndex.push(index);
                fun1(array, t, i, n, t);

                // for(int i = 0; i < n; i++){
                //     for(int j = 0; j < n; j++){
                //             cout << array[i][j] << "  ";
                //     }
                //     cout << endl;
                // }

                // cout << "\n--------------------------"<< endl;

                test(array, allIndexs, n, t + 1, tempIndex);
                if (!tempIndex.empty()){
                    tempIndex.pop();
                }
                fun2(array, t, i, n, t);
            }
        }
    }
}

int main(void){

    long finish, start; 

    start = GetTickCount();

    stack<Index> indexs;
    vector<vector<Index>> allIndexs;

    int n = 12;

    int **map = new int*[n];
    int i;
    for(i = 0; i < n; i++){
        int *p = new int[n];
        map[i] = p;
    }

    int j;
    for(i = 0; i < n; i++){
        j = 0;
        while(j < n){
            map[i][j++] = -1;
        }
    }

    test(map, allIndexs, n, 0, indexs);

    // fun1(map, 0, 3, n, 0);
    // fun1(map, 0, 3, n, 1);

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << map[i][j] << "  ";
    //     }
    //     cout << endl;
    // }

    cout << allIndexs.size() << endl;
    finish = GetTickCount();
    cout << finish-start;

    return 0;
}

