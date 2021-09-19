//数据结构——图的存储，遍历， 以及各种算法的实现
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
#define MAXVERNUM 1000  //定义最大顶点数
#define INFINITY 65535  //定义无穷大

//图的顶点数据
typedef struct vertex_date
{
    char date;
}vertex_date;

//枚举图的种类
typedef enum {UDG, UDN, DG, DN} GraphKind;
//UDG:无向图
//UDN:无向网
//DG:有向图
//DN:有向网
class Graph
{
private:
    string GraphName;                       //图名字
    vertex_date Graph_Date;                 //顶点数据
    vector<vector<int>> adjacent_matrix;    //邻接矩阵
    int verNum;                             //顶点数
    int arcNum;                             //边数
    GraphKind graphkind;                    //图种类
public:
    Graph(string & name);                                
    ~Graph(void);
    bool Save_graph(void);                  //存储图
    bool Depth_first_search(void);          //深度优先搜索
    bool Breadth_first_search(void);        //广度优先搜索
};

//以下为建立，储存图结构的一些辅助函数
string & Delete_str_space(string & str);        //删除字符串中的空格
bool Recognize_file(FILE *pfile);           //识别文件
bool Import_date(FILE *pfile);              //导入数据


/*
图是一种数据结构，其节点可以有零个或多个相邻的元素，
两个节点相连称为边。
顶点（也就是节点）vertex
边 edge
路径
无向图：顶点之间的连接没有方向
有向图：顶点之间的连接有方向
带权图：边上带有权值，也叫网。
*/