#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
问题：
        地球即将毁灭，科学家们派遣了一支队伍前往银河系外进行调查，寻找未来人类
    能居住的行星。幸运的是，在一个星球上，科学家们搜集到了许多 RNA 片段，科
    学家们把这些 RNA 片段运送往地球的实验基地中进行研究。经过几周的研究，他
    们发现这些 RNA 片段中存在着许多未知的病毒！ 
        每个 RNA 片段都由 ACT 三种碱基组成，经过研究发现，如果一个 RNA 能够翻译出
    一个 AACCTT 无限循环的蛋白质序列，那么这个 RNA 就存在病毒！RNA 翻译蛋白
    质时，首先会随机选择一个位置的碱基，将该碱基翻译为蛋白质，然后继续随机
    选择相邻位置的碱基进行翻译，直到结束。现在给出一个 RNA，你需要判断这个
    RNA 是否存在病毒。

输入：
    第一行两个整数 N 和 M，N 表示 RNA 中所含碱基总数，M 表示相邻碱基的对数。
    接下来一行，给出一个长 N 的字符串，表示每个位置碱基的种类。接下来 M 行，
    每行两个整数 ai,bi，表示位置 ai 的碱基和位置 bi 的碱基相邻。 
    1 <= N, M <= 105 
    1 <= ai, bi <= N 
    保证字符串中只含 ACT。

输出：
    如果存在病毒，输出“Yes”,否则输出“No”

示例：
    输入：
        6 7 
        AACCTT 
        1 2 
        1 6 
        2 3 
        3 4 
        4 5 
        1 2 
        5 6
    输出：Yes

分析：由题意可得每一个碱基周围都存在若干个相邻碱基，当翻译过当前碱基之后，会在其相邻碱基中随机选择一个继续进行翻译.
      值得注意的是其相邻碱基也可以是它本身，如果可以翻译出无限循环的AACCTT蛋白质序列，则说明该RNA是病毒.
      解题思路是利用图的深度优先搜索，将每个碱基视为一个顶点，采用二维数组保存，若两碱基相邻，则该位置至为true,反之为false;
      首先需要找出一组可作为出发点的顶点，即这些顶点代表的碱基是A,然后分别从这些顶点出发进行深度优先搜索遍历.
      不同于原始的深度优先搜索遍历，这种深搜不需要标记遍历过的顶点，因为有可能会需要多次遍历相同的顶点，
      那么采用什么来控制遍历路径与结束呢？
      这里我是采用根据目标碱基序列来控制遍历路径的.
      从初始点出发，以后在其相邻顶点中寻找代表下一个碱基的顶点，
      若没有，则说明此路不通，返回；
      若有，则继续深入，
      当走过的路径已经超过AACCTT的长度，这时我们需要一个标志判断这条路径是否可以无限翻译出AACCTT,
      我采取的方法是保存走过的路径，当已经翻译出一组AACCTT,且仍旧在继续深入时，若发现接下来需要保存的顶点已存在
      于所保存的路径中，则说明我们进入了循环，返回true，程序结束(我们只需要找到一条可以循环产生AACCTT的路径即可，
      因此虽然程序中有许多循环，但往往不必全部进行);
      需要注意的是为什么在路径长度为6时不直接进行判断下一个顶点是否为出发点，借此来判断是否应该终止呢
      原因是给出的碱基位置字符序列的长度与相邻碱基位置的不确定，也就是说不一定都是6个碱基为一组循环，
      可能有这种情况：第7个顶点是一个全新的顶点，它不在已保存路径中，但它代表的碱基同样也是A,
      并且其相邻碱基中有保存路径中的第二个顶点，这种情况下，其也可以进行无线循环翻译AACCTT

存在问题：
    保存相邻碱基之间的位置关系消耗空间较多，也许可以采用稀疏矩阵进行优化
    时间复杂度不稳定，最坏的情况下甚至会接近O(n^3);
    此解法也许存在bug，但由于测试数据有限无法测出
*/

const string virus = "AACCTT"; 

class Solution{
public:
    string s;
    vector<vector<bool>> poses;
    bool isVirus(int len, int pos, vector<int> &path){
        if (len > 6){
            for(int i = 0; i < path.size(); i++){
            //验证是否进入循环
                if (path[i] == pos){
                    return true;
                }
            }
        }
        //未进入循环则保存顶点，继续进行探索
        path.push_back(pos);
        bool flag;
        for(int i = 1; i < poses.size(); i++){
            //发现合适顶点
           if (poses[pos][i] && s[i] == virus[len%6]){
               //从该顶点继续深入
               flag = isVirus(++len, i, path);
               //若当前线路成功进入循环，则按线路返回
               if (flag) break;
           }
        }
        return flag;
    }

    /**
     * @brief 返回初始顶点集
     **/
    vector<int> getCharPos(char targetChar){
        vector<int> charPos;
        for(int i = 0; i < s.length(); i++){
            //搜索初始顶点位置
            if (s[i] == targetChar){
                charPos.push_back(i);
            }
        }
        return charPos;
    }
};

int main(void){
    Solution solution;
    int M, N;
    cin >> N >> M;
    string s;
    cin >> s;

    //用以保存相邻碱基之间的位置关系
    vector<vector<bool>> poses(N+1);
    for(int i = 0; i < N+1; i++){
        vector<bool> tempArray(N+1);
        poses[i] = tempArray;
    }
    solution.s = " " + s;
    for(int i = 0; i < M; i++){
        //循环输入相邻碱基
        int a, b;
        cin >> a >> b;
        poses[a][b] = true;
        poses[b][a] = true; 
    }
    solution.poses = poses;
    //获取初始顶点集
    vector<int> initPos = solution.getCharPos(virus[0]);
    for(int i = 0; i < initPos.size(); i++){
        vector<int> path;
        //发现一条可循环翻译出AACCTT的路径即可
        if (solution.isVirus(1, initPos[i], path)){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}