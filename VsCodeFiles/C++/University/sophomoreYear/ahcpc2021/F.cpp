#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
问题：
    有一条无限长的道路，道路可以近似看做一条直线。道路上有 N 个部分需要维修，
    第 i 个部分的维修的位置是 Vi，Xi 时间开始维修，直到 Yi 时间维修结束。有 Q
    个维修工人，第 i 个工人的上班的时间是 Ai，下班时间是 Bi，从 Ai 时间开始，
    他负责所有维修位置在[Li,Ri]范围的道路，直到 Bi 时间结束。他想要知道他的
    工人上班的每一分钟是否都在进行维修工作，你能编写一个程序回答他吗？

输入：第一行一个整数 N，接下来 N 行，每行三个整数 Vi,Xi,Yi。 
     下一行一个整数 Q，接下来 Q 行，每行四个整数 Li,Ri,Ai,Bi。 
     1 <= N,Vi,Q <= 10^5，1 <= Xi <= Yi <= 10^5 
     1 <= Li <= Ri <= 10^5，1 <= Ai <= Bi <= 10^5  
     
示例：
    输入：
        4 
        5 3 3 
        2 4 5 
        3 1 2 
        5 2 3 
        4 
        2 3 2 2 
        1 4 2 3 
        2 5 2 4 
        3 5 1 5
    输出：
        Yes 
        No 
        Yes 
        No

分析：如果一个工人在工作时间类一直在工作，那么说明其维修区间中的所有路段的施工时间集合应当包含
      其上班时间集合，例如对于第一个工人，其维修区间是2———3，其维修区间中所有路段的施工时间集合应当是
      1，2，4, 5;而该工人的上班时间集合是2，所以应当输出yes;
      所以现在的问题变成了如何恰当的表示施工时间集合与工作时间集合，并且得出两者的关系
      显然，直接列出时间点，判断两者是否为父子集的关系可以解决此问题，但同时其时间复杂度与空间复杂度过高
      因此采用此方法是不太好的。可采用区间包含来解决此问题

*/

class Road{
public:
    int vi;
    int xi;
    int yi;
};

class Worker{
public:
    int li;
    int ri;
    int ai;
    int bi;
};

struct cmp{
    bool operator() (Road& road1, Road& road2){
		if (road1.xi > road2.xi){
            return false;
        } else if (road1.xi == road2.xi){
            return road1.yi > road2.yi;
        } else{
            return true;
        }
	}
};


class Solution{
public:
    /**
     * @brief 判断一个工人在其工作时间内是否一直在工作
     * @param 
     **/
    bool isWorking(vector<Road> &roads, Worker worker){
        //1.筛选出工作区间内的路
        vector<Road> workRoads;
        for(int i = 0; i < roads.size(); i++){
            if (roads[i].vi >= worker.li && roads[i].vi <= worker.ri){
                workRoads.push_back(roads[i]);
            }
        }

        //2.对路段按施工时间区间进行合并.用finalRoad保存最终所得路段
        vector<Road> finalRoad;
        Road tempRoad = workRoads[0];
        for(int i = 1; i < workRoads.size(); i++){
            if (tempRoad.yi - workRoads[i].xi < -1){
                finalRoad.push_back(tempRoad);
                tempRoad = workRoads[i];
            } else{
                tempRoad.yi = tempRoad.yi > workRoads[i].yi ? tempRoad.yi : workRoads[i].yi;
            }
        }
        finalRoad.push_back(tempRoad);

        //4.验证工人工作时间是否跨区间，若跨区间则没有一直工作
        for(int i = 0; i < finalRoad.size(); i++){
            // cout << finalRoad[i].xi << "--" << finalRoad[i].yi << "  ";
            if (worker.ai >= finalRoad[i].xi && worker.bi <= finalRoad[i].yi){
                cout << "Yes" << endl;
                return true;
            }
        }

        cout << "No" << endl;
        return false;
    }
};

int main(void){
    Solution solution;
    vector<Road> roads;
    vector<Worker> workers;
    int N, Q;
    int vi, xi, yi;
    int li, ri,ai, bi;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> vi >> xi >> yi;
        Road road;
        road.vi = vi;
        road.xi = xi;
        road.yi = yi;
        roads.push_back(road);
    }
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> li >> ri >> ai >> bi;
        Worker worker;
        worker.li = li;
        worker.ri = ri;
        worker.ai = ai;
        worker.bi = bi;
        workers.push_back(worker);
    }

    //对路段进行排序(按开始时间从小到大，若开始时间相同，则比较结束时间，小的在前)
    sort(roads.begin(),roads.end(), cmp());

    for(int i = 0; i < Q; i++){
       solution.isWorking(roads, workers[i]);
    }

    return 0;
}