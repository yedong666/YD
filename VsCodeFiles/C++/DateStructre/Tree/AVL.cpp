#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//AVL结点
typedef struct AVLNode{
    //数据
    int data;
    //平衡因子(即左右子树高度差)
    int balanceIndex;
    struct AVLNode *pleft;
    struct AVLNode *pright;
    
    /**
     * @brief 默认结点构造
     **/
    AVLNode(){
        data = -1;
        balanceIndex = 0;
        pleft = NULL;
        pright = NULL;
    }

}AVLNode;

//AVL类
class AVL{
private:
    //根结点
    AVLNode *root;
public:
    //LL型旋转(在某结点的左孩子的左子树上插入了新结点，导致该节点失衡)
    AVLNode* llTurn(AVLNode *&node, AVLNode *&parent);
    //RR型旋转(在某结点的右孩子的右子树上插入了新结点，导致该节点失衡)
    AVLNode* rrTurn(AVLNode *&node, AVLNode *&parent);
    //LR型旋转(在某结点的左孩子的右子树上插入了新结点，导致该节点失衡)
    AVLNode* lrurn(AVLNode *&node, AVLNode *&parent);
    //RL型旋转(在某结点的右孩子的左子树上插入了新结点，导致该节点失衡)
    AVLNode* rlTurn(AVLNode *&node, AVLNode *&parent);
    //插入新元素
    AVLNode* insertNode(int newData, AVLNode *&baseNode, stack<AVLNode*> &nodeStack);
    //删除结点
    void deleteNode(int deleteElement);
    //中序遍历
    void inorderTravel(AVLNode *baseNode);
    //层序遍历
    void levelTravel(AVLNode *baseNode);
    //创建一棵平衡二叉树
    void createAVL(vector<int> array);
    //更新平衡因子
    void updateBI(AVLNode *node);
    //获取二叉树高度
    int getHeight(AVLNode *node);
    //获取根结点
    AVLNode* getRoot();
    //初始化AVL树
    AVL(){root = NULL;};
};

/**
 * @param node LL型失衡结点
 * @param parent 失衡点的父节点
 * @return 旋转后顶替原失衡点位置的结点
 **/
AVLNode* AVL::llTurn(AVLNode *&node, AVLNode *&parent){
    //LL型旋转得到的新结点为失衡点的左孩子
    AVLNode *newBaseNode = node->pleft;
    //临时变量，存储新结点原右孩子
    AVLNode *tempNode = newBaseNode->pright;
    //失衡点作为新结点的新的右孩子
    newBaseNode->pright = node;
    //新结点的原右孩子作为失衡点的左孩子;
    node->pleft = tempNode;

    //更新左右子树发生变化的结点
    updateBI(newBaseNode);
    updateBI(newBaseNode->pright);

    if (!parent){
        //若parent为空直接返回，不用连接
        return newBaseNode;
    }

    //连接parent与新结点
    if (parent->pleft == node){
        parent->pleft = newBaseNode;
    }
    else{
        parent->pright = newBaseNode;
    }

    return newBaseNode;
}

/**
 * @param node RR型失衡结点
 * @param parent 失衡点的父节点
 * @return 旋转后顶替原失衡点位置的结点
 **/
AVLNode* AVL::rrTurn(AVLNode *&node, AVLNode *&parent){
    //RR型旋转得到的新结点为失衡点的右孩子
    AVLNode *newBaseNode = node->pright;
    //临时变量，存储新结点原左孩子
    AVLNode *tempNode = newBaseNode->pleft;
    //失衡点作为新结点的新的左孩子
    newBaseNode->pleft = node;
    //新结点的原左孩子作为失衡点的右孩子;
    node->pright = tempNode;

    //更新左右子树发生变化的结点
    updateBI(newBaseNode);
    updateBI(newBaseNode->pleft);

    if (!parent){
        //若parent为空直接返回，不用连接
        return newBaseNode;
    }

    //连接parent与新结点
    if (parent->pleft == node){
        parent->pleft = newBaseNode;
    }
    else{
        parent->pright = newBaseNode;
    }

    return newBaseNode;

}

/**
 * @param node LR型失衡结点
 * @param parent 失衡点的父节点
 * @return 旋转后顶替原失衡点位置的结点
 **/
AVLNode* AVL::lrurn(AVLNode *&node, AVLNode* &parent){
    node->pleft = rrTurn(node->pleft, node);
    node = llTurn(node, parent);
    return node;
}

/**
 * @param node RL型失衡结点
 * @param parent 失衡点的父节点
 * @return 旋转后顶替原失衡点位置的结点
 **/
AVLNode* AVL::rlTurn(AVLNode *&node, AVLNode* &parent){
    node->pright = llTurn(node->pright, node);
    node = rrTurn(node, parent);
    return node;
}

/**
 * @param 左右子树发生变化的结点 
 **/
void AVL::updateBI(AVLNode *node){
    if (node){
        node->balanceIndex = getHeight(node->pleft) - getHeight(node->pright);
    } 
}

/**
 * @param 以此节点作为根节点的二叉树的高度
 **/
int AVL::getHeight(AVLNode *node){
    if (node){
        //获取左子树高度
        int leftHeight = getHeight(node->pleft);
        //获取右子树高度
        int rightHeigt = getHeight(node->pright);
        //取两者中较大的高度
        int max = leftHeight > rightHeigt ? leftHeight : rightHeigt;
        //则此二叉树高度为max + 1
        return max + 1;
    }
    else{
        //node为空
        return 0;
    }
}

/**
 * @brief 删除AVL树中数据为deleteElement的结点
 * @param deleteElemetn 待删除结点的数据
 **/
void AVL::deleteNode(int deleteElement){
    //存储访问过的结点，以便找到父节点与最小不平衡点
    stack<AVLNode *> nodeStack;
    //初始化p为根结点
    AVLNode *p = root;

    while(p){
        //搜索待删除结点
        nodeStack.push(p);
        if (p->data == deleteElement){
            break;
        }
        else if(p->data > deleteElement){
            p = p->pleft;
        }
        else{
            p = p->pright;
        }
    }

    if (!p){
        cout << "无此元素，删除失败！" << endl;
        return;
    }

    if (p->pleft && p->pright){
        //若待删除结点左右子树皆不为空
        AVLNode *min = p->pright;
        while(min->pleft){
            //则搜索出其右子树上的最小结点
            nodeStack.push(min);
            min = min->pleft;
        }
        //用其右子树的最小结点数据覆盖p的数据
        p->data = min->data;
        
        //删除min;
        if (min->pright){
            //若min的右子树不为空，则需将min的前驱结点连接到min的右子树
           if (nodeStack.top() == p){
               //若min的前驱结点为p,则min应为p的右孩子
               p->pright = min->pright;
           }
           else{
               //否则应为其前驱结点的左孩子
               AVLNode *temp = nodeStack.top();
               temp->pleft = min->pright;
           }
        }
        else{
            //若min的右孩子为空，则对应找到其相应的前驱结点，将其前驱结点的左孩子或右孩子置空
            if (nodeStack.top() == p){
               p->pright = NULL;
            }
            else{
               AVLNode *temp = nodeStack.top();
               temp->pleft = NULL;
            }
        }
        //释放min
        delete min;
    }
    else{
        nodeStack.pop();
        AVLNode *pr = nodeStack.top();
        if (!p->pleft){
            if (pr->pleft == p){
                pr->pleft = p->pright;
            }
            else{
                pr->pright = p->pright;
            }
        }
        else{
            if (pr->pleft == p){
                pr->pleft = p->pleft;
            }
            else{
                pr->pright = p->pleft;
            }
        }
        delete p;
        p = NULL;
    }

    AVLNode *q, *parent;
    while(!nodeStack.empty()){
        q = nodeStack.top();
        nodeStack.pop();
        if (!nodeStack.empty()){
            parent = nodeStack.top();
        }
        else{
            parent = NULL;
        }

        updateBI(q);//更新平衡因子
        
        //调节平衡
        if (q->balanceIndex > 1 && q->pleft->balanceIndex >= 0){
            cout << "ll";
            q = llTurn(q, parent);
        }
        else if (q->balanceIndex > 1 && q->pleft->balanceIndex < 0){
            cout << "lr";
            q = lrurn(q, parent);
        }
        else if (q->balanceIndex < -1 && q->pright->balanceIndex >= 0){
            cout << "rl";
            q = rlTurn(q, parent);
        }
        else if (q->balanceIndex < -1 && q->pright->balanceIndex < 0){
            cout << "rr";
            q = rrTurn(q, parent);
        }
        else {}
    }
}

/**
 * @param 中序遍历此平衡二叉树
 **/ 
void AVL::inorderTravel(AVLNode *node){
    if (node){
        inorderTravel(node->pleft);
        cout << "数据：" << node->data << " 平衡因子：" << node->balanceIndex << endl;
        inorderTravel(node->pright);  
    }
}

AVLNode* AVL::getRoot(){
    return root;
}

AVLNode* AVL::insertNode(int newData, AVLNode *&baseNode, stack<AVLNode*> &nodeStack){
    if (!baseNode){
        baseNode = new AVLNode;
        baseNode->data = newData;
    }
    else{
        nodeStack.push(baseNode);
        if (newData < baseNode->data){
            baseNode = insertNode(newData, baseNode->pleft, nodeStack);
        }else if (newData > baseNode->data){
           baseNode = insertNode(newData, baseNode->pright, nodeStack);
        }
        else{
            cout << "平衡二叉树中不能存在键值相同的结点。" << endl;
            return NULL;
        } 
    }
    
    //临时变量，存储当前baseNode的父节点
    AVLNode *tempNode;
    if (!nodeStack.empty()){
        tempNode = nodeStack.top();
        updateBI(tempNode);
        nodeStack.pop();
    }
    else{
        //若栈为空说明当前结点已是根结点
        return baseNode;
    }

    AVLNode *p;
    if(!nodeStack.empty()){
        p = nodeStack.top();
    }
    else{
        p = NULL;
    }

    if (tempNode->balanceIndex > 1 && tempNode->pleft->balanceIndex >= 0){
        cout << "ll";
        tempNode = llTurn(tempNode, p);
    }
    else if (tempNode->balanceIndex > 1 && tempNode->pleft->balanceIndex < 0){
        cout << "lr";
        tempNode = lrurn(tempNode, p);
    }
    else if (tempNode->balanceIndex < -1 && tempNode->pright->balanceIndex >= 0){
        cout << "rl";
        tempNode = rlTurn(tempNode, p);
    }
    else if (tempNode->balanceIndex < -1 && tempNode->pright->balanceIndex < 0){
        cout << "rr";
        tempNode = rrTurn(tempNode, p);
    }
    else {}

    return tempNode;
}


void AVL::createAVL(vector<int> array){
    stack<AVLNode*> nodeStack;
    for(int i = 0; i < array.size(); i++){
        root = insertNode(array[i], root, nodeStack);
    }
}

int main(void){
    AVL T;
    vector<int> array = {3, 1, 2, 4, 7, 5, 9, 11, 8};
    T.createAVL(array);
    T.inorderTravel(T.getRoot());
    cout << "_______________________" << endl;
    T.deleteNode(5);
    T.deleteNode(8);
    T.inorderTravel(T.getRoot());
    return 0;
}