#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include "MatrixGraph.h"
#define MAXLEN 100

typedef struct Node{
	char data;
	int parent;
}Node;

class Tree{
public:
	Node tree[MAXLEN];
	int numNode = 0;
	void PreTraversal(){
		for(int i = 0; i < numNode; i++){
			cout << "data:" << tree[i].data << "	parent:" <<tree[i].parent << endl; 
		}
	}

	int GetIndex(char data){
		//更具结点数据搜索结点下标
		for(int i = 0; i < numNode; i++){
			if (tree[i].data == data){
				return i;
			}
		}
		return INF;
	}
};

//删除字符串、字符数组左边空格
void strLTrim(char* str)
{
	int i,j;
	int n=0;
	n=strlen(str)+1;
	for(i=0;i<n;i++)
	{
		if(str[i]!=' ')  //找到左起第一个非空格位置
			break;
	}
	    //以第一个非空格字符为手字符移动字符串
	for(j=0;j<n;j++)
	{
		str[j]=str[i];
		i++;
	}
}

//*************************从数据文件创建图**************************//
//* 函数功能：从文本文件创建邻接矩阵表示的图                        *//
//* 入口参数  char fileName[]，文件名                               *//
//* 出口参数：                                                      *//
//* 返 回 值：bool，true创建成功；false创建失败                     *//
//* 函 数 名：CreateGrpFromFile(char fileName[])                  *//
//*******************************************************************//
bool CreateGrpFromFile(const char fileName[], Graph &G)
{
	FILE* pFile;      //定义顺序表的文件指针
	char str[1000];   //存放读出一行文本的字符串
	char strTemp[10]; //判断是否注释行

	cellType  eWeight;     //边的信息，常为边的权值
	GraphKind GrpType;  //图类型枚举变量

	pFile=fopen(fileName,"r");
	if(!pFile)
	{

		printf("错误：文件%s打开失败。\n",fileName);
		return false;
	}

	while(fgets(str,1000,pFile)!=NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0]=='\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //跳过注释行
			continue;
		else  //非注释行、非空行，跳出循环
			break;
	}

    //循环结束，str中应该已经是文件标识，判断文件格式
	if(strstr(str,"Graph")==NULL)
	{
		printf("错误：打开的文件格式错误！\n");
		fclose(pFile); //关闭文件
		return false;
	}

	//读取图的类型，跳过空行
	while(fgets(str,1000,pFile)!=NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0]=='\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //注释行，跳过，继续读取下一行
			continue;		
		else  //非空行，也非注释行，即图的类型标识
			break;
	}
    
    //设置图的类型
	if(strstr(str,"UDG"))
		GrpType=UDG;  //无向图
	else if(strstr(str,"UDN"))
		GrpType=UDN;  //无向网
	else if(strstr(str,"DG"))
		GrpType=DG;   //有向图
	else if(strstr(str,"DN"))
		GrpType=DN;   //有向网
	else
	{
		printf("错误：读取图的类型标记失败！\n");
		fclose(pFile); //关闭文件
		return false;
	}

	//读取顶点元素，到str。跳过空行
	while(fgets(str,1000,pFile)!=NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0]=='\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //注释行，跳过，继续读取下一行
			continue;		
		else  //非空行，也非注释行，即图的顶点元素行
			break;
	}

    //顶点数据放入图的顶点数组	
	char* token=strtok(str," ");
	int nNum=1;	
	while(token!=NULL)
	{
		G.Data[nNum]=*token; // atoi(token);	//顶点数据转换为整数，若为字符则不需转换		
        token = strtok( NULL, " ");
		nNum++;
	}
	nNum--;   //顶点数

    //图的邻接矩阵初始化
	int nRow=1;  //矩阵行下标，从1开始
	int nCol=1;  //矩阵列下标，从1开始
	if(GrpType==UDG || GrpType==DG)
	{
		for(nRow=1;nRow<=nNum;nRow++)
			for(nCol=1;nCol<=nNum;nCol++)
				G.AdjMatrix[nRow][nCol]=0;
	}
	else
	{
		for(nRow=1;nRow<=nNum;nRow++)
			for(nCol=1;nCol<=nNum;nCol++)
				G.AdjMatrix[nRow][nCol]=INF;  //INF表示无穷大
	}
	
	//循环读取边的数据到邻接矩阵

	int edgeNum=0;  //边的数量
	elementType Nf,Ns; //边或弧的2个相邻顶点
	while(fgets(str,1000,pFile)!=NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0]=='\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //注释行，跳过，继续读取下一行
			continue;

		char* token=strtok(str," ");  //以空格为分隔符，分割一行数据，写入邻接矩阵
		
		if(token==NULL)  //分割为空串，失败退出
		{
			printf("错误：读取图的边数据失败！\n");
			fclose(pFile); //关闭文件
			return false;
		}
		Nf=*token;  //获取边的第一个顶点
		
		token = strtok( NULL, " ");  //读取下一个子串，即第二个顶点
		if(token==NULL)  //分割为空串，失败退出
		{
			printf("错误：读取图的边数据失败！\n");
			fclose(pFile); //关闭文件
			return false;
		}

		Ns=*token;  //获取边的第二个顶点
            //从第一个顶点获取行号		
		for(nRow=1;nRow<=nNum;nRow++)
		{
			if(G.Data[nRow]==Nf)  //从顶点列表找到第一个顶点的编号
				break;
		}
           //从第二个顶点获取列号		
		for(nCol=1;nCol<=nNum;nCol++)
		{
			if(G.Data[nCol]==Ns)  //从顶点列表找到第二个顶点的编号
				break;
		}

		//如果为网，读取权值
		if(GrpType==UDN || GrpType==DN)
		{
			token = strtok( NULL, " ");  //读取下一个子串，即边的附加信息，常为边的权重
			if(token==NULL)  //分割为空串，失败退出
			{
				printf("错误：读取图的边数据失败！\n");
				fclose(pFile); //关闭文件
				return false;
			}
			eWeight=atoi(token);  //取得边的附加信息
		}
		if(GrpType==UDN || GrpType==DN)  //如果为网，邻接矩阵中对应的边设置权值，否则置为1
			G.AdjMatrix[nRow][nCol]=eWeight;
		else
			G.AdjMatrix[nRow][nCol]=1;  //atoi(token);	//字符串转为整数

		edgeNum++;   //边数加1
	}

    G.VerNum=nNum;  //图的顶点数
	if(GrpType==UDG || GrpType==UDN)
		G.ArcNum=edgeNum / 2;  //无向图或网的边数等于统计的数字除2  
	else
		G.ArcNum=edgeNum;

	G.gKind=GrpType;  //图的类型

	fclose(pFile); //关闭文件
	return true;
}

void DFS(Graph G, int v){
	visit(G, v);
	for(int i = 1; i <= G.VerNum; i++){
		if (G.AdjMatrix[v][i] >= 1 && G.AdjMatrix[v][i] < INF && !visited[i]){
			DFS(G, i);
		}
	}
}

void BFS(Graph G, int v){
	/*
		访问v并初始化
	*/
	queue<int> vQueue;
	cout << G.Data[v];
	visited[v] = true;
	vQueue.push(v);
	int temp = v;
	while(!vQueue.empty()){
		for(int i = 1; i <= G.VerNum; i++){
			if (G.AdjMatrix[temp][i] >= 1 && G.AdjMatrix[temp][i] < INF && !visited[i]){
				//访问当前顶点的连接点
				//并将连接点入队
				cout << G.Data[i];
				visited[i] = true;
				vQueue.push(i);
			}
		}
		vQueue.pop();
		temp = vQueue.front();
		//更新当前结点
	}
}

//深度优先遍历生成树
void SpainningTree(Graph G, int v, Tree &T, int parent){
	T.tree[T.numNode].data = G.Data[v];
	T.tree[T.numNode].parent = parent;
	parent = T.numNode++;
	visited[v] = true;
	for(int i = 1; i <= G.VerNum; i++){
		if (G.AdjMatrix[v][i] >= 1 && G.AdjMatrix[v][i] < INF && !visited[i]){
			SpainningTree(G, i, T, parent);
		}
	}
}

/*
	以下为最小生成树的prim算法实现
	包含多个辅助函数，与辅助数据类型，以及主算法函数实现
*/

/*
	边数据类型
	可以一个边数组存储图中的所有边
	其中数组下标代表此边的一端顶点，v代表另一端顶点
	weight代表边的权值
	weight不为INF时代表此边不是候选边
	反之代表其为侯选边
*/
typedef struct Edge{
	int v;	
	int weight;
}Edge; 

//判断两顶点之间是否有边
bool HasEdge(Graph G, int v1, int v2){
	if (G.AdjMatrix[v1][v2] > 0 && G.AdjMatrix[v1][v2] < INF){
		//根据伴随矩阵判断两顶点之间是否有边
		return true;
	}
	else{
		return false;
	}
}

//获取未选顶点中与已选顶点相连且边的权值最小的顶点
int GetMinWightVertex(Graph G, Edge *E, int &parent){
	int minWeight = INF;
	int n = 0;
	for(int i = 1; i <= G.VerNum; i++){
		if (!visited[i] && E[i].weight < minWeight){
			minWeight = E[i].weight;
			n = i;
		}
	}
	// cout << G.Data[n];
	parent = E[n].v;
	//对于顶点n来说, 在生成树中， v就是它的父节点
	return n;
}

//初始化侯选边集合
void InitEdgeArray(Graph G, Edge *E, int v){
	for(int i = 1; i <= G.VerNum; i++){
		if (HasEdge(G, v, i)){
			//若某顶点与v之间有边，则将它们之间的边转变为候选边
			E[i].v = v;
			E[i].weight = G.AdjMatrix[v][i];
		}
		else{
			E[i].weight = INF;
		}
	}
}

//更新侯选边集合
void UpdateEdge(Graph G, Edge *E, int v){
	for(int i = 1; i <= G.VerNum; i++){
		if (!visited[i] && HasEdge(G, v, i) && E[i].weight > G.AdjMatrix[v][i]){
			/*
				添加新候选边,或更新原有候选边
				若i与v相连，与原已选顶点之间没有边，则添加新候选边
				若i与v相连的同时，与原已选顶点之间也有边，则根据边的权值大小，保存小的
			*/
			E[i].v = v;
			E[i].weight = G.AdjMatrix[v][i];
		}
	}
}

void Prim(Graph G,Tree &T, int v){
	Edge edgeArray[MaxVerNum+1];
	int p = -1;	//临时变量，存储当前顶点的父节点在图中的位置

	//初始化生成树的第一个结点
	T.tree[T.numNode].data = G.Data[v];
	T.tree[T.numNode++].parent = p;
	visited[v] = true;

	//初始化侯选边集合
	InitEdgeArray(G, edgeArray, v);
	int vex = v;

	//标记已选顶点与未选顶点
	for(int i = 1; i < G.VerNum; i++){
		//每次循环得到一个新的生成树顶点，因为已初始化一个结点
		//所以循环G.VerNum-1次即可
		vex = GetMinWightVertex(G, edgeArray, p);
		// cout << G.Data[vex];
		//根据候选边，从未选顶点中找出与已选顶点相连且边权值最小的顶点，将其添加到已选顶点中
		T.tree[T.numNode].data = G.Data[vex];
		T.tree[T.numNode++].parent = T.GetIndex(G.Data[p]);
		//通过其父顶点的存储的数据搜索其父节点在已有生成树中的下标
		visited[vex] = true;
		UpdateEdge(G, edgeArray, vex); 
		//因为增加了新的已选顶点，所以需更新候选边
	}
}
/*
	算法分析：
		首先申请一个侯选边集合，根据出发点初始化候选边，将出发点标记为已选
		再根据图中顶点数目控制循环次数，每次都根据侯选边找到下一个顶点，将之设置为已选
*/

//判断图中两顶点之间是否有路径
bool HasPath(Graph G, int v1, int v2){
	if (G.AdjMatrix[v1][v2] > 0 && G.AdjMatrix[v1][v2] < INF){
		//如果v1,v2之间有边，显然两顶点之间有路径
		return true;
	}
	else{
		visited[v1] = true;
	 	for(int i = 1; i <= G.VerNum; i++){
		 	if (G.AdjMatrix[v1][i] > 0 && G.AdjMatrix[v1][i] < INF && !visited[i]){
				 /*
				 	如果v1，v2之间没有边，但与v1相连的顶点与v2有边，则v1与v2之间也有边
				 */
				if (HasPath(G, i, v2)){
					return true;
				}
			}
		}
		return false;
	}
}

//判断有向图是否是一棵以顶点v0为根结点的有向树
//有向树：联通图，根节点入度为0，其余结点入度为1
bool IsTree(Graph G, int v0){
	int *inDegree = new int[G.VerNum + 1];

	//初始化所有顶点入度
	int i = 0;
	inDegree[i++] = 0;
	while(i < G.VerNum+1){
		inDegree[i++] = 0;
	}

	//计算所有顶点入度
	for(i = 1; i <= G.VerNum; i++){
		for(int j = 1; i <= G.VerNum; j++){
			if (G.AdjMatrix[i][j] > 0 && G.AdjMatrix[i][j] < INF){
				inDegree[j]++;
			}
		}
	}

	//若根节点入度不为0，说明此图不是有向树，直接返回false
	if (inDegree[v0] != 0){
		return false;
	}
	else{
		for(i = 1; i <= G.VerNum; i++){
			if (i != v0 && inDegree[i] != 1){
				//若某结点不是根节点，且其入度不为1，也说明此图不是有向树，返回false
				return false;
			}
		}
	}

	return true;

}

//KrusKal算法(求解网的最小生成树)
typedef struct K_Edge{
	int v1;	
	int v2;
	int weight;
	bool treeFalg;	//是否为生成树的边的标志
}K_Edge;
//用于存储边集
void KrusKal(Graph G, Tree &T){
	vector<K_Edge> edge;
	int component[MaxVerNum];
	//存储连通分量编号
	K_Edge tempEdge;
	//将图中边以此方式存储，便于以后算法实现
	for(int i = 1; i <= G.ArcNum; i++){
		for(int j = 1; j <= G.ArcNum; j++){
			tempEdge.weight = G.AdjMatrix[i][j];
			if (tempEdge.weight == INF || tempEdge.weight <= 0){
				continue;
			}
			tempEdge.v1 = i;
			tempEdge.v2 = j;
			tempEdge.treeFalg = false;

			if (edge.empty()){
				edge.push_back(tempEdge);
			}
			else{
				bool tempflag = false;
				for(int k = 0; k < edge.size(); k++){
					//插入过程中用插入排序对其按从大到小的顺序进行排序
					if (tempEdge.weight > edge[k].weight){
						edge.insert(edge.begin()+k, tempEdge);
						tempflag = true;
						break;
					}
				}
				if (!tempflag){
					edge.push_back(tempEdge);
				}

			}
		}
	}
	for(int i = 0; i < edge.size(); i++){
		cout << edge[i].v1 << "		" << edge[i].v2 << "	" << edge[i].weight << endl;
	}

	for(int i = 1; i <=	G.VerNum; i++){
		component[i] = i;
		//初始时将每一个顶点都视为一个联通分量，并赋予编号
	}

	int num = edge.size()-1;
	while(num > -1){
		//依次选取最小边
		tempEdge = edge[num];
		if (component[tempEdge.v1] != component[tempEdge.v2]){
			//若此边两头的顶点所在联通分量编号不同，则此边合法，修改新形成的连通分量的编号都为INF
			component[tempEdge.v1] = INF;
			component[tempEdge.v2] = INF;
			edge[num].treeFalg = true;	//将此边加入已选边
		}
		num--;
	}

	for(int i = 0; i < edge.size(); i++){
		if (edge[i].treeFalg){
			cout << edge[i].v1 << "		" << edge[i].v2 << "	" << edge[i].weight << endl;
		}
	}
}

/*
	从一个顶点到其余各个顶点的最短路径————Dijkstra算法
	思路:1.初始化起点到各顶点的路径长度,有边长度为边的权值，无边则设置为INF
		   设置起点先驱顶点为-1，将除起点外的所有顶点状态设置为未解
		 2.根据路径长度搜索下一个求解顶点(未解顶点中，到起点路径长度最小的顶点即为下一个求解顶点)
		 3.将所得求解顶点状态设置为已解
		 4.访问与当前已解顶点相连的且未解的顶点，若其到起点的路径长度小于当前已解顶点到
		    起点的路径长度加上它们弧的权值之和，则需修改这些顶点的先驱顶点与路径长度
		 5.重复2，3，4直至求解完所有顶点
*/		
void DijKstra(Graph &G, int *path, int *dist, int vFirst){
	bool solveFlag[MaxVerNum+1];
	for(int i = 1; i <= G.VerNum; i++){
		solveFlag[i] = false;
		//初始时将所有顶点都设置为未解
		if (G.AdjMatrix[vFirst][i] > 0 && G.AdjMatrix[vFirst][i] < INF){
			//若有顶点与起点相连，则其弧的权值暂为其到起点的最短路径长度
			//并将其先驱结点修改为vFirst
			dist[i] = G.AdjMatrix[vFirst][i];
			path[i] = vFirst;
		}
		else {
			dist[i] = INF;
		}
	}

	solveFlag[vFirst] = true;	//设置起点为已解
	path[vFirst] = -1;			//设置起点的先驱顶点为-1
	dist[vFirst] = 0;			//设置其路径长度为0

	int vexTemp = vFirst;
	int minDist;
	int num = 1;	

	//搜索下一个求解顶点
	while(num < G.VerNum){
		//每次循环求解一个顶点需循环MaxVerNum-1次

		minDist = INF;
		for(int i = 1; i <= G.VerNum; i++){
			//搜索待求解点
			if (minDist > dist[i] && !solveFlag[i]){
				//cout << G.AdjMatrix[vPre][i] << "	" << endl;
				vexTemp = i;
				minDist = dist[i];
			}
		}

		if (minDist == INF){
			//无未解点
			return;
		}

		solveFlag[vexTemp] = true;
		dist[vexTemp] = minDist;

		for(int i = 1; i <= G.VerNum; i++){
			if (G.AdjMatrix[vexTemp][i] + dist[vexTemp] < dist[i] && !solveFlag[i]){
			/*
				若与vexTemp相连，且其新的路径长度小于原有路径长度，需将其路径长度与先驱结点更新
			*/
			dist[i] = G.AdjMatrix[vexTemp][i] + dist[vexTemp];
			path[i] = vexTemp;
			}
		}

		num++;
	}

	//打印路径及路径长度
	int k, tempPath[MaxVerNum+1];
	for(int i = 1; i <= G.VerNum; i++){
		if (i == vFirst){
			continue;
		}
		k = i;
		cout << "顶点" << i << "到顶点1的路径长度为：" << dist[i] << endl;  
		cout << "路径为：";
		num = 0;
		while(k != -1){
			tempPath[num++] = k;
			k = path[k];
		}
		for(int j = num-1; j > -1; j--){
			cout << tempPath[j] << " ";
		}
		cout << endl;
	}
}

/*
	求解图中任意两顶点之间的最短路径————Floyd算法
	思路：1.初始化两个二维数组path与dist, path存储路径，dist存储路径长度
		   其中path[i][j]表示从起点i到终点j的路径中终点j的前驱顶点
		   dist[i][j]表示从起点i到终点j的路径中终点j的路径长度
		   具体过程为：若顶点i与顶点j之间有弧，则i为j的前驱结点，否者设其前驱结点为-1
		   			  若顶点i与顶点j之间有弧，则弧的权值即为临时最短路径长度，否则设其为INF
		  2.设置三重循环，向所有顶点组合之间的路径添加中转点m，(m为不等于i,j的任意顶点)，比较新的路径长度与原有
		  	路径长度，如若新的路径长度更小，则更新dist[i][j]与path[i][j];
*/

void Floyd(Graph G, int path[MaxVerNum+1][MaxVerNum+1], int dist[MaxVerNum+1][MaxVerNum+1], int vFirst){
	//初始化
	for(int i = 1; i <= G.VerNum; i++){
		for(int j = 1; j <= G.VerNum; j++){
			if (i != j && G.AdjMatrix[i][j] > 0 && G.AdjMatrix[i][j] < INF){
				dist[i][j] = G.AdjMatrix[i][j];
				path[i][j] = i; 
			}
			else{
				dist[i][j] = INF;
				path[i][j] = -1;
			}
		}
	}

	//核心算法；三重循环
	for(int m = 1; m <= G.VerNum; m++){
		for(int i = 1; i <= G.VerNum; i++){
			for(int j = 1; j <= G.VerNum; j++){
				if (i != j && dist[i][m] + dist[m][j] < dist[i][j]){
					dist[i][j] = dist[i][m] + dist[m][j];
					path[i][j] = path[m][j];
				}
			}
		}
	}

	//打印路径及路径长度
	int k;
	int num;
	int tempPath[MaxVerNum+1];
	for(int i = 1; i <= G.VerNum; i++){
		if (i == vFirst){
			continue;
		}
		k = i;
		cout << "顶点" << vFirst << "到顶点" << i <<"的路径长度为：" << dist[vFirst][i] << endl;  
		cout << "路径为：";
		num = 0;
		while(k != vFirst){
			tempPath[num++] = k;
			k = path[vFirst][k];
		}
		cout << vFirst << " ";
		for(int j = num-1; j > -1; j--){
			cout << tempPath[j] << " ";
		}
		cout << endl;
	}

}

/*	
	有向无环图的判断————拓扑排序
	拓扑序列：对于一顶点序列，若满足位置在前的顶点到位置在后的顶点有路径，位置在后的顶点到位置在前的顶点
			 无路径，则称之为拓扑序列，产生拓扑序列的过程称为拓扑排序
	实现思路：
		1.获取有向图中所有顶点的入度，将其中入度为0的顶点存入栈中
		2.弹出栈顶元素，将其加入拓扑序列。
		3。将此元素代表的顶点的后继顶点的入度减一，若发现某顶点的入度为0，则将其入栈
		4.重复2.3，直至栈为空为止。
		5.若最终所得拓扑序列中包含图的所有顶点，则此图为有向无环图
*/
void TopologicalSort(Graph G, int topologicalStr[MaxVerNum+1]){
	int inDegree[MaxVerNum+1];	//储存所有顶点的入度
	stack<int> topologicalVex;  //储存入度为0的顶点栈
	cout << G.VerNum << endl;

	//获取所有顶点的入度，并将入度为0的顶点入栈
	for(int i = 1; i <= G.VerNum; i++){
		int tempInDegree = 0;
		for(int j = 1; j <= G.VerNum; j++){
			cout << j << " " << i << " " << G.AdjMatrix[j][i] << endl;
			if (i != j && G.AdjMatrix[j][i] > 0 && G.AdjMatrix[j][i] < INF){
				//若顶点j到顶点i有合法弧，则顶点i的入度加一
				tempInDegree++;
			}
		}
		inDegree[i] = tempInDegree;
		cout << "顶点" << i << "的入度为" << inDegree[i] << endl;
		if (inDegree[i] == 0){
			topologicalVex.push(i);
		}
	}

	int num = 0; //记录拓扑序列的顶点个数
	while(!topologicalVex.empty()){
		//将栈顶元素代表的顶点加入拓扑序列
		int vex = topologicalVex.top();
		topologicalVex.pop();
		topologicalStr[num++] = vex;
		cout << "顶点" << vex << "加入拓扑序列" << endl;

		for(int i = 1; i <= G.VerNum; i++){
			if (G.AdjMatrix[vex][i] > 0 && G.AdjMatrix[vex][i] < INF && inDegree[i] != 0){
				inDegree[i]--;
				if (inDegree[i] == 0){
					topologicalVex.push(i);
				}
			}
		}
	}

	for(int i = 0; i < num; i++){
		cout << topologicalStr[i];
	}

	cout << endl;

	if (num == G.VerNum){
		cout << "这是一个有向无环图！" << endl;
	}
	else{
		cout << "这不是一个有向无环图！" << endl;
	}

}

/*
	关键路径————源点到汇点的路径
	思路：对每个顶点(事件),设置最短完成时间与最长完成时间，
	通过将相关算法嵌入拓扑排序获得每个顶点的最短完成时间，
	通过将相关算法嵌入逆拓扑排序获得每个顶点的最长完成时间，
	由于关键路径不受任何时事件的影响，所以最短完成时间与最长完成时间相等的
	顶点即为关键路径上的一个顶点，借此即可求出关键路径
	注意：关键路径可能不止一条
*/
typedef struct Accident{
	int shortestTime;
	int longestTime;
}Accident; 

void PrinKeytPath(Graph G, bool flag[MaxVerNum+1], int sourceVex, int meetingVex, vector<int> &path){
	int temp = sourceVex;
	path.push_back(temp);
	if (temp == meetingVex){
		//如果源点与汇点重合，则打印path(即初始源点到汇点的一条路径)
		for(int i = 0; i < path.size(); i++){
			cout << path[i] << "	";
		}
		cout << endl;
	}
	else{
		//否则寻找当前顶点的后继顶点到汇点的路径
		flag[temp] = false;
		for(int i = 1; i <= G.VerNum; i++){
			if (G.AdjMatrix[temp][i] > 0 && G.AdjMatrix[temp][i] < INF && flag[i]){
				PrinKeytPath(G, flag, i, meetingVex, path);
			}	
		}
	}
	path.pop_back();
}

void CriticalPath(Graph &G, int sourceVex, int meetingVex){
	bool CriticalPath[MaxVerNum+1];			//标记图中在关键路径上的顶点
	Accident AllVex[MaxVerNum+1];			//存储所有顶点的最长时间与最短时间
	int inDegree[MaxVerNum+1];				//储存所有顶点的入度
	int outDegree[MaxVerNum+1]; 			//存储所有顶点的出度
	stack<int> topologicalVex;  			//储存入度为0的顶点栈
	stack<int> opTopologicalVex;			//储存出度为0的顶点栈
	AllVex[sourceVex].shortestTime = 0;		//源点的最短时间初始化为0
	AllVex[meetingVex].longestTime = 0;		//汇点的最长时间初始化为0

	//获取所有顶点的入度与出度，并将入度为0与出度为0的顶点分别压入相应
	for(int i = 1; i <= G.VerNum; i++){
		AllVex[i].shortestTime = 0;

		int tempInDegree = 0;
		int tempOutDegree = 0;

		for(int j = 1; j <= G.VerNum; j++){
			if (i != j && G.AdjMatrix[j][i] > 0 && G.AdjMatrix[j][i] < INF){
				//若顶点j到顶点i有合法弧，则顶点i的入度加一
				tempInDegree++;
			}
			if (i != j && G.AdjMatrix[i][j] > 0 && G.AdjMatrix[i][j] < INF){
				//若顶点i到顶点j有合法弧，则顶点i的出度加一
				tempOutDegree++;
			}

		}
		inDegree[i] = tempInDegree;
		outDegree[i] = tempOutDegree;

		if (inDegree[i] == 0){
			//若顶点入度为0,将其加入拓扑序列栈
			topologicalVex.push(i);
		}
		if (outDegree[i] == 0){
			//若顶点出度为0，将其加入逆拓扑序列栈
			opTopologicalVex.push(i);
		}
	}

	//进行拓扑排序，求各顶点的最短时间
	while(!topologicalVex.empty()){
		//获取拓扑序列栈栈顶元素
		int vex = topologicalVex.top();
		topologicalVex.pop();

		for(int i = 1; i <= G.VerNum; i++){
			if (G.AdjMatrix[vex][i] > 0 && G.AdjMatrix[vex][i] < INF && inDegree[i] != 0){
				//更新当前顶点的后继顶点的入度
				inDegree[i]--;

				if (AllVex[vex].shortestTime + G.AdjMatrix[vex][i] > AllVex[i].shortestTime){
					//更新当前顶点的后继顶点的最短时间
					AllVex[i].shortestTime = AllVex[vex].shortestTime + G.AdjMatrix[vex][i];
				}

				if (inDegree[i] == 0){
					//若某后继顶点入度为0则将其入栈
					topologicalVex.push(i);
				}
			}
		}
	}

	for(int i = 1; i <= G.VerNum; i++){
		//初始化各顶点的最长完成时间
		AllVex[i].longestTime = AllVex[meetingVex].shortestTime;
	}

	//进行逆拓扑排序，求各顶点的最长时间
	while(!opTopologicalVex.empty()){
		//获取逆拓扑序列栈栈顶元素
		int vex = opTopologicalVex.top();
		opTopologicalVex.pop();

		for(int i = 1; i <= G.VerNum; i++){
			if (G.AdjMatrix[i][vex] > 0 && G.AdjMatrix[i][vex] < INF && outDegree[i] != 0){
				//更新当前顶点的前驱顶点的出度
				outDegree[i]--;

				if (AllVex[vex].longestTime - G.AdjMatrix[i][vex] < AllVex[i].longestTime){
					//更新当前顶点的前驱顶点的最长路径
					AllVex[i].longestTime = AllVex[vex].longestTime - G.AdjMatrix[i][vex];
				}

				if (outDegree[i] == 0){
					//若某前驱顶点出度为0则将其入栈
					opTopologicalVex.push(i);
				}
			}
		}
	}

	for(int i = 1; i <= G.VerNum; i++){
		if (AllVex[i].longestTime == AllVex[i].shortestTime){
			//搜索最短完成时间与最长完成时间相等的事件，并将之标记
			CriticalPath[i] = true;
		}
		else{
			CriticalPath[i] = false;
		}
	}

	vector<int> path;
	PrinKeytPath(G, CriticalPath, sourceVex, meetingVex, path);
	//打印关键路径
}

int main(void){
	Graph G;
	CreateGrpFromFile("GraphTestData3.txt", G);
	CriticalPath(G, 1, 10);
    return 0;
}