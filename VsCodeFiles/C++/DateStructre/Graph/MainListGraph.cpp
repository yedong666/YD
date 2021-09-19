#include <cstring>
#include "ListGraph.h"

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

//销毁图
void DestroyGraph(Graph &G)
{
	EdgeNode *p,*u;        //边链表结点指针
	int vID;
	for(vID=1; vID<=G.VerNum; vID++)  //循环删除每个顶点的边链表
	{
		p=G.VerList[vID-1].firstEdge;
		G.VerList[vID-1].firstEdge=NULL;
		while(p)           //循环删除当前顶点所有的关联边 
		{
			u=p->next;    //u指向下一个边结点
			delete(p);     //删除当前边结点
			p=u;
		}		
	}
	p=NULL;
	u=NULL;
	G.VerNum=-1;  //标识图已经销毁
}

//****************************文件创建图*****************************//
//* 函数功能：从文本文件创建邻接表表示的图                          *//
//* 入口参数  char fileName[]，文件名                               *//
//* 出口参数：Graph &G，即创建的图                                  *//
//* 返 回 值：bool，true创建成功；false创建失败                    *//
//* 函 数 名：CreateGraphFromFile(char fileName[], Graph &G)        *//
//* 备注：本函数使用的数据文件格式以边（顶点对）为基本数据          *//
//*******************************************************************//
int CreateGraphFromFile(char fileName[], Graph &G)
{
	FILE* pFile;         //定义文件指针
	char str[1000];        //存放读出一行文本的字符串
	char strTemp[10];      //判断是否注释行
	char* ss; 
  int i=0, j=0;
	int edgeNum=0;        //边的数量
	eInfoType eWeight;     //边的信息，常为边的权值
	GraphKind graphType;  //图类型枚举变量
	pFile=fopen(fileName,"r");
	if(!pFile)
	{
		printf("错误：文件%s打开失败。\n",fileName);
		return false;
	}
		while(fgets(str,1000,pFile)!=NULL)  //跳过空行和注释行
	{
		strLTrim(str);     //删除字符串左边空格，这是一个自定义函数
		if (str[0]=='\n')    //空行，继续读取下一行
			continue;
		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)    //跳过注释行
			continue;
		else                          //非注释行、非空行，跳出循环
			break;
	}
  //循环结束，str中应该已经是图的标识Graph，判断标识是否正确
	if(strstr(str,"Graph")==NULL)
	{
		printf("错误：打开的文件格式错误！\n");
		fclose(pFile);                //关闭文件
		return false;
	}
	//读取图的类型，跳过空行及注释行
	while(fgets(str,1000,pFile)!=NULL)
	{
		strLTrim(str);     //删除字符串左边空格，这是一个自定义函数
		if (str[0]=='\n')    //空行，继续读取下一行
			continue;
		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //注释行，跳过，继续读取下一行
			continue;		
		else                       //非空行，也非注释行，即图的类型标识
			break;
	}
  //设置图的类型
	if(strstr(str,"UDG"))
		graphType=UDG;    //无向图
	else if(strstr(str,"UDN"))
		graphType=UDN;    //无向网
	else if(strstr(str,"DG"))
		graphType=DG;     //有向图
	else if(strstr(str,"DN"))
		graphType=DN;     //有向网
	else
	{
		printf("错误：读取图的类型标记失败！\n");
		fclose(pFile);       //关闭文件
		return false;
	}
	//读取顶点数据到str。跳过空行
	while(fgets(str,1000,pFile)!=NULL)
	{
		strLTrim(str);     //删除字符串左边空格，这是一个自定义函数
		if (str[0]=='\n')    //空行，继续读取下一行
			continue;
		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //注释行，跳过，继续读取下一行
			continue;		
		else                       //非空行，也非注释行，即图的顶点元素行
			break;
	}
	//顶点数据放入图的顶点数组		
	char* token=strtok(str," ");
	int nNum=0;	
	while(token!=NULL)
	{
		G.VerList[nNum].data=*token;
		G.VerList[nNum].firstEdge=NULL;
      token = strtok( NULL, " ");
		nNum++;
	}
	//循环读取边（顶点对）数据
	int nRow=0;          //矩阵行下标
	int nCol=0;           //矩阵列下标
	EdgeNode* eR;       //边链表尾指针
	EdgeNode* p;    
	elementType Nf, Ns;   //边或弧的2个相邻顶点
	while(fgets(str,1000,pFile)!=NULL)
	{
		strLTrim(str);     //删除字符串左边空格，这是一个自定义函数
		if (str[0]=='\n')    //空行，继续读取下一行
			continue;
		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //注释行，跳过，继续读取下一行
			continue;
		char* token=strtok(str," ");     //以空格为分隔符，分割一行数据
		if(token==NULL)            //分割为空串，失败退出
		{
			printf("错误：读取图的边数据失败！\n");
			fclose(pFile);            //关闭文件
			return false;
		}
		Nf=*token;                //获取边的第一个顶点
		token = strtok( NULL, " ");   //读取下一个子串，即第二个顶点
		if(token==NULL)          //分割为空串，失败退出
		{
			printf("错误：读取图的边数据失败！\n");
			fclose(pFile);          //关闭文件
			return false;
		}
		Ns=*token;    //获取边的第二个顶点
                   //从第一个顶点获取行号
		for(nRow=0;nRow<nNum;nRow++)
		{
			if(G.VerList[nRow].data==Nf)  //从顶点列表找到第一个顶点的编号
				break;
		}
                    //从第二个顶点获取列号
		for(nCol=0;nCol<nNum;nCol++)
		{
			if(G.VerList[nCol].data==Ns)  //从顶点列表找到第二个顶点的编号
				break;
		}
		//如果为网，读取权值
		if(graphType==UDN || graphType==DN)
		{            //读取下一个子串，即边的附加信息，常为边的权重
			token = strtok( NULL, " ");  
			if(token==NULL)    //分割为空串，失败退出
			{
				printf("错误：读取图的边数据失败！\n");
				fclose(pFile);    //关闭文件
				return false;
			}
			eWeight=atoi(token);  //取得边的附加信息，即权值
		}
		eR=G.VerList[nRow].firstEdge;
		while(eR!=NULL && eR->next!=NULL)
		{
			eR=eR->next;        //后移边链表指针，直至尾节点
		}
		p=new EdgeNode;        //申请一个边链表结点
		p->adjVer=nCol+1;       //顶点的编号，从1开始
	    //边的附加信息（权值），对有权图保存权值，无权图为1
if(graphType==UDN || graphType==DN) 
			p->eInfo=eWeight;
	    else
			p->eInfo=1; 
		p->next=NULL;
		if(G.VerList[nRow].firstEdge==NULL)
		{
			G.VerList[nRow].firstEdge=p;
			eR=p;
		}
		else
		{
			eR->next=p;
			eR=p;       //新的尾指针				
		}				
		edgeNum++;     //边数加1
	}
	G.VerNum=nNum;    //图的顶点数
	if(graphType==UDG || graphType==UDN)
		G.ArcNum=edgeNum / 2;   //无向图或网的边数等于统计的数字除2  
	else
		G.ArcNum=edgeNum;
	G.gKind=graphType;           //图的类型
	fclose(pFile);                 //关闭文件
	return true;
}

int main(void){
    return 0;
}