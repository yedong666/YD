#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define null 99999
#define MAXLEN 100
using namespace std;

//无向图(邻接矩阵表示法)
class MatrixGraph{
private:
    int numVertex;  //顶点数
    int matrix[MAXLEN][MAXLEN];   //邻接矩阵
    char vertexData[MAXLEN];      //顶点数据
    bool visited[MAXLEN];
public:
    MatrixGraph(const char *fileName);
    void ResetVisit(void);
    //重置访问标志
    void DFS(int vertex);              
    void BFS(int vertex);
};

MatrixGraph::MatrixGraph(const char *fileName){
    FILE *pf;
    char tempData;
    int number;
    numVertex = 0;
    if (!(pf = fopen(fileName, "r"))){
        cout << "打开文件失败！" << endl;
    }

    //初始化访问标志与边
    for(int i = 0; i < MAXLEN; i++){
        visited[i] = false;
        for(int j = 0; j < MAXLEN; j++){
            matrix[i][j] = 0;
        }
    }

    while(fscanf(pf, "%c%d ", &tempData, &number) != EOF){
        if (tempData == '#'){
            //顶点数据读取结束
            //换行读取边数据
            break;
        }
        cout << tempData << number << endl;
        vertexData[number] = tempData;
        numVertex++;
    }

    int vertex1, vertex2;
    while(fscanf(pf, "%d %d\n", &vertex1, &vertex2) != EOF){
        cout << vertex1 << vertex2 << endl;
        matrix[vertex1][vertex2] = 1;
        matrix[vertex2][vertex1] = 1;
    }
}

void MatrixGraph::DFS(int vertex){
    cout << vertexData[vertex] << endl; //访问当前顶点
    visited[vertex] = true;             //更新访问标志
    for(int i = 0; i < numVertex; i++){
        if (matrix[i][vertex] == 1 && matrix[vertex][i] == 1 && !visited[i]){
            //寻找与当前顶点之间有边的顶点
            //并对其深度优先搜索
            DFS(i);
        }
    }
}

void MatrixGraph::BFS(int vertex){
    queue<int> gQueue;
    int w;

    //初始化
    cout << vertexData[vertex];
    visited[vertex] = true;
    gQueue.push(vertex);

    while(!gQueue.empty()){
        w = gQueue.front();
        gQueue.pop();
        for(int i = 0; i < numVertex; i++){
            if (matrix[i][w] == 1 && matrix[w][i] == 1 && !visited[i]){
                //遍历当前顶点的所有临接点
                cout << vertexData[i];
                visited[i] = true;
                gQueue.push(i);
            }
        }
    }
}

//边链表
class EdgeList{
public:
    int vertex;             //顶点编号
    EdgeList *nextEdge;     //下一条边
public:
    EdgeList();
    EdgeList(int v);
    //添加新边
    void AddEdge(int newVertex);
};

EdgeList::EdgeList(){
    vertex = null;
    nextEdge = NULL;
}

EdgeList::EdgeList(int v){
    vertex = v;
    nextEdge = NULL;
}

void EdgeList::AddEdge(int newVertex){
    EdgeList *p = this;
    while(p->nextEdge){
        //搜索最后一条边
        p = p->nextEdge;
    }
    EdgeList *newEdge = new EdgeList(newVertex);
    p->nextEdge = newEdge;
}

//顶点
struct Vectex{
    char data;              //顶点存储的数据
    bool visitedFlag;       //顶点的访问标志
    EdgeList *headEdge;     //边链表的头结点(按编号从小到大的顺序存储与此顶点相连相连的所有顶点编号)
};


//无向图(邻接表表示法)
class LinkListGraph{
private:
    vector<struct Vectex> vertex;       //存储所有顶点
    int numVerdex;
public:
    LinkListGraph(const char *fileName);//根据文件数据创建无向图
    void BFS(int v);
};

LinkListGraph::LinkListGraph(const char *fileName){
    FILE *pf;

    //作为临时变量从文件读取数据
    char data;          
    //顶点数据
    int number;         
    //顶点编号(决定此顶点在顶点数组中的下标)
    char linkVerdex;    
    //存储邻接顶点的编号

    numVerdex = 0; 
    //初始化此无向图的顶点数量     

    if(!(pf = fopen(fileName, "r"))){
        cout << "打开文件失败！" << endl;
    }

    while(fscanf(pf, "%c%d\n", &data, &number) != EOF){
        /*
            按指定方式从文件读取数据
            每一行存储一个顶点的相关信息
            前两个字符分别为顶点数据与顶点编号，
            此后以空格分隔，每个字符代表与此顶点邻接的顶点编号
            读取到‘#’，即代表此顶点相关数据已读完，换行读取下一个顶点信息
        */

        EdgeList *p = new EdgeList;
        //给当前顶点创建边链表

        while(fscanf(pf, "%c ", &linkVerdex) != EOF){
            if (linkVerdex == '#' ){
                break;
            }

            p->AddEdge(linkVerdex-'0');
            //将邻接点编号存储到边链表中
        }

        /*
            创建顶点实体，并完善相关信息，将之存储到此图的顶点数组中
        */
        Vectex v;
        v.data = data;
        v.headEdge = p;
        v.visitedFlag = false;
        vertex.push_back(v);

        numVerdex++;
        //更新顶点个数
    }
}

void LinkListGraph::BFS(int v){
    cout << vertex[v].data << endl;
    //访问当前顶点
    vertex[v].visitedFlag = true;
    //更新当前顶点的访问标志
    int temp;
    EdgeList *p = vertex[v].headEdge->nextEdge;
    while(p){
        if (!vertex[p->vertex].visitedFlag){
            //若当前顶点的此临接点未被访问，则BFS此临接点
            BFS(p->vertex);
        }
        p = p->nextEdge;
        //指向下一个邻接点
    }
}

int main(void){
    // MatrixGraph
    // MatrixGraph("GraphTestData.txt");
    // MatrixGraph.BFS(0);
    LinkListGraph test("GraphTestData2.txt");
    test.BFS(0);
    return 0;
}