#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <map>
using namespace std;

/*
    问题：给定一棵 n 个节点的树，如果树中存在边（a,b)(b,c)(c,d)，a,b,c,d 互不相同，
            并且 a 和 d 之间没有边，那么可以连一条边(a,d)，求最多能连多少条边？
    输入：第一行一个整数 N，接下来 N-1 行，表示树的每一条边。 
            1 <= N <= 2×10^5
    输出：输出一行，表示答案。

    分析：将本题已通俗的语言描述即为，在一个树形图中寻找这样2个顶点a, b，它们之间没有边相连,
          且从a到b仅需经过两个顶点；每发现这样一对顶点即在它们之间添加一条新边
        (注意：添加的新边在之后的搜索中将继续存在)，求可添加多少条边；
    思路：本体思路很简单，根据问题顺序解答即可，具体步骤为：
            1.根据输入构建树形图，采用邻接表的方式，之所以不采用邻接矩阵是由于2*10^5个顶点，需要2*10^5 * 2*10^5大小的矩阵
              空间复杂度过高
            2.分别从每个顶点出发，深度优先搜索遍历树形图，找到所有以该顶点为出发点，路径长度为4的路径，并对终点与起始点
              之间的关系进行判断，然后根据判断结果决定是否添加新边。
            3.输出结果maxEdgeNum  
    此算法时间复杂度为O(n)到O(n^2)之间，具体的复杂度与数据有关，原因是我们需分别对每个顶点计算以该顶点为起始点的合法
    路径有几条，同时递归深度仅为4，，此外就是递归结束判断时需遍历一次终点的邻接点。

*/

class Solution{
public:
    //计算边数
    int maxEdgeNum  = 0;
    vector<int> treeFlag;
    map<int, int> edgeMap;

    /**
     *@param index 当前遍历顶点
     *@param floor 递归深度
     *@param initIndex 初始顶点 
     */
    void DFS(vector<list<int>> &tree, int index, int floor, int initIndex){
        if(floor == 4){
           //当到达第四个顶点时，判断其与起始点之间是否有边
           bool flag = true;
           for(int i : tree[index]){
               if (i == initIndex ){
                   //发现有边，则说明此边不可添加
                   flag = false;
                   break;
               }
            }
            if (flag){
                //发现可添加边
                maxEdgeNum++;
                tree[index].push_back(initIndex);
                tree[initIndex].push_back(index);
            }
            return;
        }
        //设置已访问标记
        treeFlag[index] = 1;
    
        for(int i : tree[index]){
            if (treeFlag[i] == 0){
                //从相邻顶点继续深入
                DFS(tree, i, floor+1, initIndex);       
            }
        }
        //回溯前需重置访问标记
        treeFlag[index] = 0;
       
    }
};

int main(void){
    int N;
    cin >> N;
    //标记顶点是否被访问
    vector<int> treeFlag(N+1);
    //开辟空间
    vector<list<int>> tree(N+1);
    list<int> temp;
    for(int i = 0; i < N+1; i++){
        tree[i] = temp;
    }

    int m, n;
    for(int i = 1; i < N; i++){
        //采用邻接表保存图
        cin >> m >> n;
        tree[m].push_back(n);
        tree[n].push_back(m);
    }

    Solution solution;
    solution.treeFlag = treeFlag;

    for(int i = 1; i < N+1; i++){
        solution.DFS(tree, i, 1, i);
    }

    cout << solution.maxEdgeNum;
    return 0;
}