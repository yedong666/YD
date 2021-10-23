#include <iostream>
#include <vector>
#define TARGET 7
using namespace std;

/*
    问题：给定N个不大于3的正整数，求最多能将其分为多少组，使每一组都为7的倍数

    输入要求：有多组数据，对于一次输入，第一行第一个数代表本次输入的组数，此后每两行为一组
             前一行表示本组数据的数量，后一行有3个数x、y、z分别代表改组数据中1、2、3的个数

    输出要求：针对每组数据分别输出其所能分组的最大数量

    分析：
          应尽可能多的组合出7；
          先将2、3组合，组合后有4种情况：
          a.只剩下2
          b.只剩下3
          c.两者恰好组合完
          d.剩下一个2和若干个3(若2和3同时剩余，则2必然只能有一个)
          对于每种情况进行相应处理即可
*/
class Solution{
public:
    //计算一组数据的最大最大分组量
    int n = 0;
    void maxGroups(int x, int y, int z, int groups){
        /*
            ...
        */
    }
};

class Group{
public:
    int x;
    int y;
    int z;
    int num;
};

int main(void){
    Solution solution;
    int T;
    cin >> T;
    vector<Group> data(T);
    for(int i = 0; i < T; i++){
        int num, x, y, z;
        cin >> num;
        cin >> x >> y >> z;
        data[i].x = x;
        data[i].y = y;
        data[i].z = z;
        data[i].num = num;
    }

    for(int i = 0; i < T; i++){
        cout << data[i].x << " " << data[i].y << " " <<data[i].z << " " << data[i].num << " : ";
        solution.maxGroups(data[i].x, data[i].y, data[i].z, 0);
        cout << solution.n << endl;
        solution.n = 0;
    }
    return 0;
}