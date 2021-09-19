#include <iostream>
#define MAXLEN 100
using namespace std;

typedef char date;

//双亲表示法结点
typedef struct PForestNode{
    date nodeDate;
    int parent;
}PFNode;

//双亲表示法森林
class PForest{
private:
    PFNode* forest[MAXLEN];
    int num = 0;
public:
    PForest();
    PFNode* GetNode(int i);
    void AddNode(date newNodeDate, int parent, int index);
    int GetNum(void);
};

PFNode* PForest::GetNode(int i){
    return forest[i];
}

/*
newNodeDate:即所添加新节点的数据
parent:即所添加新节点是的父节点
index:即所添加新结点在双亲表示法森林中的下标
*/
void PForest::AddNode(date newNodeDate, int parent, int index){
    PFNode *p;
    p->nodeDate = newNodeDate;
    p->parent = parent;
    forest[index] = p;
    num++;  //每添加一个新结点，结点数便加一
}

//返回当前森林中的结点个数
int PForest::GetNum(void){
    return num;
}

//孩子兄弟表示法结点
typedef struct BCForestNode{
    date nodeDate;
    BCNode *pBrother;
    BCNode *pChild;
}BCNode;

//孩子兄弟法森林
class BCForest{
private:
    BCNode *baseNode;
public:
    BCForest();
    BCNode* GetBaseNode(void);                                //返回根结点
    int GetNodeNum(BCNode *node);                             //返回结点个数
    int GetLeavesNodeNum(BCNode *node);                       //返回叶子结点个数
    void CreateBCForest(BCNode *&node, PForest &pForest, int index);      //创建森林
};

BCForest::BCForest(){
    baseNode = NULL;
}

BCNode* BCForest::GetBaseNode(void){
    return baseNode;
}

int BCForest::GetNodeNum(BCNode *node){
    if (node != NULL){
        return 1 + GetNodeNum(node->pChild) + GetNodeNum(node->pBrother);
        /*
        一座森林的结点个数为1加上其孩子树的结点个数与兄弟树的结点个数
        */
    }
    else {
        return 0;
    }
}

void BCForest::CreateBCForest(BCNode *&node , PForest &pForest, int index){
    // if (index != -1){
    //     node = new BCNode;
    //     PFNode *ptemp = pForest.GetNode(index);
    //     node->nodeDate = ptemp->nodeDate;
    //     CreateBCForest(node->pChild, pForest, )
    // }
}







/*************************************************************************************/
//将以孩子兄弟表示法存储(二叉链表)的森林转化为双亲表示法存储
void TurnFun(BCNode *BCFNode, PForest &PF, int parent = -1){
    if (BCFNode != NULL){
        PF.AddNode(BCFNode->nodeDate, parent, PF.GetNum());
        TurnFun(BCFNode->pChild,PF, PF.GetNum()-1);
        //孩子结点的父节点为当前结点在双亲表示法数组中的下标
        TurnFun(BCFNode->pBrother, PF, parent);
        //兄弟表示法的父节点与当前结点的父节点相同
    }
}

//计算森林高度
int GetHeight(BCNode *BCFNode){
    if (BCFNode != NULL){
        int FCHeight = GetHeight(BCFNode->pChild);      //获取孩子树高度
        int BHeight = GetHeight(BCFNode->pBrother);     //获取兄弟树结点
        return ((1+FCHeight) > BHeight ? (FCHeight+1) : BHeight); 
        /*
        注意：兄弟树的高度不用算上当前结点，而孩子树需要
        */
    }
    else{
        return 0;
    }
}

int main(void){
    return 0;
}

/*
void linkedToParent(csNode *&T,pTree &T1,int &f)
{
    //f 为双亲结点的下标
    int f1;
    if(T)
    {
        T1.node[T1.n].data=T->data;
        T1.node[T1.n].parent=f;
        f1=T1.n; //更新第一个孩子结点的双亲
        T1.n++; //结点数加 1
        linkedToParent(T->firstChild,T1,f1); //双亲变为 f1
        linkedToParent(T->nextSibling,T1,f); //双亲仍为 f 
    } 
}
*/