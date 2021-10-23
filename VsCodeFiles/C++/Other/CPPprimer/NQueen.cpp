#include <iostream>
#include <windows.h>
#include <ctime>
#include <cmath> 
#include <vector>
using namespace std;
bool checkPos(int *map, int n, int level){
    for(int i = 0; i < level; i++){
        //检查坐标是否符合要求
        if (abs(map[i] - map[level]) == abs(i - level) || map[i] - map[level] == 0){
            return false;
        }
    }
    return true;
}

void searchQueen(int *&map, vector<int *> &allIndex, int n, int level){
    if (level == n){
        //找到一种完整布棋方法
        for(int i = 0; i < n; i++){
            cout << i << "," << map[i] << " ";
        }
        cout << endl;
        allIndex.push_back(map);
    }
    else{
        while(map[level] < n){
            if (checkPos(map, n, level)){
                //若此层有合适位置，则深入下一层继续布局
                searchQueen(map, allIndex, n, level+1);
            }
            map[level]++;
        }
        //返回上一层前，需将标记过的位置从新置0
        map[level] = 0;
    }
}

void nQueue(int n){
    vector<int *> allIndex;
    int *map = new int[n];
    int i = 0;

    //初始化地图
    for(i; i < n; i++){
        map[i] = 0;
    }

    searchQueen(map, allIndex, n, 0);

    cout << allIndex.size() << endl;

}

int main(void){
    long finish, start; 
    start = GetTickCount();
    nQueue(8);
    finish = GetTickCount();
    cout << finish-start;
    return 0;
}
