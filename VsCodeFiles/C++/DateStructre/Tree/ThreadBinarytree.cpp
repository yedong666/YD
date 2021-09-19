//线索二叉树的实现（中序）
#include <iostream>
using namespace std;
typedef char Date;
//数据
struct TreeNode{
    Date treedate;
    int ltag;       //前驱标志
    int rtag;       //后继标志
    struct TreeNode *plchild;   //左子树（ltag为1时其为前驱）
    struct TreeNode *prchild;   //右子树（rtag为1时其为后继）
};

typedef struct TreeNode TreeNode;

enum Thread{link, thread};      //枚举线索标识的值

//线索二叉树的结点
class ThreadBinaryTree{
private:
    TreeNode *headNode;     //头结点
    TreeNode *BaseNode;     //根结点
    TreeNode *preNode;      //总是指向当前结点的前驱(中序)
public:
    ThreadBinaryTree();                     //初始化树
    TreeNode *GetBaseNode();                //获取根结点
    void CreateTree(TreeNode *&Node);       //建立二叉树
    void TravelTree(TreeNode *Node);        //中序遍历二叉树(非递归)
    void ThreadingTree(TreeNode *&Node);    //二叉树线索化
    void ImproveThrTree(TreeNode *&Node);   //改进线索二叉树,即建立头结点
};

ThreadBinaryTree::ThreadBinaryTree(){
    BaseNode = NULL;
    preNode = NULL;
}

TreeNode* ThreadBinaryTree::GetBaseNode(){
    return BaseNode;
}

void ThreadBinaryTree::CreateTree(TreeNode *&Node){
   char chDate;
   cin >> chDate;
   if (chDate == '#'){
       return;
   }
   Node = new TreeNode;
   Node->treedate = chDate;
   Node->plchild = NULL;
   Node->prchild = NULL;
   Node->ltag = 0;
   Node->rtag = 0;
   CreateTree(Node->plchild);
   CreateTree(Node->prchild);
}

void ThreadBinaryTree::ThreadingTree(TreeNode *&Node){
    if (Node){
        ThreadingTree(Node->plchild);   //线索化左子树
        if (!Node->plchild){
            //如果当前结点的左子树为空,则让plchild指向当前结点前驱
            Node->ltag = 1;
            Node->plchild = preNode;
        }
        if(!preNode->prchild){
            //如果当前结点的前一个结点的右子树为空，则让其prchild指向当前结点
            preNode->rtag = 1;
            preNode->prchild = Node;
        }
        preNode = Node;
        ThreadingTree(Node->prchild);   //线索化右子树
    }
}

void ThreadBinaryTree::ImproveThrTree(TreeNode *&Node){
    //初始化头结点
    headNode = new TreeNode;    
    headNode->ltag = 0;
    headNode->rtag = 1;
    
    //将头结点与根节点，中序遍历的第一个结点，最后一个结点，连接起来
    if (!Node) {
        headNode->plchild = headNode;
        headNode->prchild = headNode;
    }
    else {
        preNode = headNode;
        headNode->plchild = Node;
        ThreadingTree(Node);
        preNode->rtag = 1;
        preNode->prchild = headNode;
        headNode->prchild = preNode;
    }

    //给根结点赋值
    BaseNode = Node;
}

void ThreadBinaryTree::TravelTree(TreeNode *Node){
    TreeNode *tempNode = Node;
    while(tempNode != headNode){

        while(tempNode->ltag != 1){
            //搜索当前树的第一个结点(中序)
            tempNode = tempNode->plchild;
        }
        cout << tempNode->treedate << endl;

        //输出其后继结点
        //若其后继结点也有后继结点，依旧按此法输出
        //直到无后继结点为止
        while(tempNode->rtag == 1 && tempNode->prchild != headNode){
            tempNode = tempNode->prchild;
            cout << tempNode->treedate << endl;
        }

        //若无后继结点，则搜索其右子树的第一个结点
        tempNode = tempNode->prchild;
    }
}

int main(void){
    ThreadBinaryTree testTree;
    TreeNode *p = testTree.GetBaseNode();
    testTree.CreateTree(p);
    testTree.ImproveThrTree(p);
    testTree.TravelTree(testTree.GetBaseNode());
    return 0;
}
