#include <iostream>
#include <stack>
#include <vector>
#include <vector>
#include <queue>
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
            //若min的右子树不为空，则需有、将min的前驱结点连接到min的右子树
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

void AVL::levelTravel(AVLNode *node){
   if (node != NULL){
        queue<AVLNode*> myqueue;
        vector<AVLNode *> tempArray;
        AVLNode *tempNode;
        if(node){
            myqueue.push(node);
        }
        while(!myqueue.empty()){
            while(!myqueue.empty()){
                tempNode = myqueue.front();
                myqueue.pop();
                cout << tempNode->data << "  ";
                if (tempNode->pleft){
                    tempArray.push_back(tempNode->pleft);
                }
                if (tempNode->pright){
                    tempArray.push_back(tempNode->pright);
                }
            }
            cout << endl;
            for(int i = 0; i < tempArray.size(); i++){
                myqueue.push(tempArray[i]);
            }

            while(!tempArray.empty()){
                tempArray.pop_back();
            }
        }
        cout << endl;
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
        cout << "右旋 ";
        tempNode = llTurn(tempNode, p);
    }
    else if (tempNode->balanceIndex > 1 && tempNode->pleft->balanceIndex < 0){
        cout << "左右旋 ";
        tempNode = lrurn(tempNode, p);
    }
    else if (tempNode->balanceIndex < -1 && tempNode->pright->balanceIndex >= 0){
        cout << "右左旋 ";
        tempNode = rlTurn(tempNode, p);
    }
    else if (tempNode->balanceIndex < -1 && tempNode->pright->balanceIndex < 0){
        cout << "左旋 ";
        tempNode = rrTurn(tempNode, p);
    }
    else {}

    return tempNode;
}

void AVL::createAVL(vector<int> array){
    cout << "以数组：";
    for(int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }
    cout << "创建二叉树"<<endl;
    stack<AVLNode*> nodeStack;
    for(int i = 0; i < array.size(); i++){
        cout << "插入" << array[i];
        root = insertNode(array[i], root, nodeStack);
        cout << endl;
    }
}

/*
二叉搜索树
其特点如下：设x为二叉查找树中的一个结点，
x节点包含关键字key，一句话就是左孩子比父节点小，
右孩子比父节点大，还有一个特性就是”中序遍历“可以让结点有序。
若任意节点的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
任意节点的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
任意节点的左、右子树也分别为二叉查找树；
没有键值相等的节点。
*/

//结点数据构造
typedef struct Node{
    int data;
    Node *pleft;
    Node *pright;
}Node;

//BST类
class BinarySearchTree{
private:
    Node *baseNode;
public:
 BinarySearchTree();
 Node* GetBaseNode(void);
 void SearchNode(int searchElement);
 void InorderTaversal(Node *node);
 void LevelTaversal(Node *node);
 void InsertNode(Node *&node, int newdata);
 void DeleteNode(int deleteElement);
 void CreateBST(vector<int> dataArray); 
};

BinarySearchTree::BinarySearchTree(void){
    baseNode = NULL;
}

Node* BinarySearchTree::GetBaseNode(void){
    return baseNode;
}

void BinarySearchTree::InsertNode(Node *&node, int newdata){
    if (!node){
        cout << "发现插入位置，插入" << newdata << "\n\n";
        node = new Node;
        node->data = newdata;
        node->pleft = NULL;
        node->pright = NULL;
    }
    else{
        if (newdata < node->data){
            cout << "待插入元素" << newdata << " < " << "当前结点元素" << node->data << "   在此结点左子树寻找插入位置\n";
            InsertNode(node->pleft, newdata);
        }else if (newdata > node->data){
            cout << "待查元素" << newdata << " > " << "当前结点元素" << node->data << "   在此结点右子树寻找插入位置\n";
            InsertNode(node->pright, newdata);
        }
        else{
            cout << "二叉查找树中不能存在键值相同的结点。" << endl;
            return;
        } 
    }
}

void BinarySearchTree::CreateBST(vector<int> dataArray){
    cout << "以数组: {";
    for(int i = 0; i < dataArray.size(); i++){
        cout << dataArray[i] << " ";
    }
    cout << "}创建二叉搜索树\n";
    cout << "\n此二叉搜索树为空" << endl;
    for(int i = 0; i < dataArray.size(); i++){
        InsertNode(baseNode, dataArray[i]);
    }
    cout << "创建完成！" << endl;
}

void BinarySearchTree::InorderTaversal(Node* node){
    if (node){
        InorderTaversal(node->pleft);
        cout << node->data << " ";
        InorderTaversal(node->pright);
    }
}

void BinarySearchTree::LevelTaversal(Node *node){
    if (node != NULL){
        queue<Node*> myqueue;
        vector<Node *> tempArray;
        Node *tempNode;
        if(node){
            myqueue.push(node);
        }
        while(!myqueue.empty()){
            while(!myqueue.empty()){
                tempNode = myqueue.front();
                myqueue.pop();
                cout << tempNode->data << "  ";
                if (tempNode->pleft){
                    tempArray.push_back(tempNode->pleft);
                }
                if (tempNode->pright){
                    tempArray.push_back(tempNode->pright);
                }
            }
            cout << endl;
            for(int i = 0; i < tempArray.size(); i++){
                myqueue.push(tempArray[i]);
            }

            while(!tempArray.empty()){
                tempArray.pop_back();
            }
        }
        cout << endl;
    }
}

void BinarySearchTree::DeleteNode(int deleteElement){
    Node *deleteNode = baseNode; //初始化删除结点为根结点(暂时)
    Node *p = NULL;              //临时变量，存储deleteNode的父节点

    //搜索待删除结点
    while(deleteNode != NULL){
        if (deleteNode->data == deleteElement){
            //找到，退出
            break;
        }
        else{
            p = deleteNode;
            if (deleteElement > deleteNode->data){
                deleteNode = deleteNode->pright;
            }
            else{
                 deleteNode = deleteNode->pleft;
            }
        }
    }

    if (deleteNode == NULL){
        //搜索失败，退出
        cout << "此二叉排序树中无此结点，查找失败！" << endl;
        return;
    }

    if (deleteNode->pleft != NULL && deleteNode->pright != NULL){
        //若待删除结点的左右子节点都不为空
        //则搜索待删除结点的后继结点
        //用之覆盖待删除结点，然后删除原后继结点即可
        Node *next = deleteNode->pright;
        Node *ptemp = deleteNode;
        while(next->pleft != NULL){
            ptemp = next;
            next = next->pleft;
        }
        deleteNode->data = next->data;
        p = ptemp;
        deleteNode = next;
    }

    bool flag = false;
    if (p->pleft == deleteNode){
        flag = true;
    }

    if (deleteNode->pleft != NULL){
        if (flag){
            p->pleft = deleteNode->pleft;
        }
        else{
            p->pright = deleteNode->pleft;
        }
    }
    else{
         if (flag){
            p->pleft = deleteNode->pright;
        }
        else{
            p->pright = deleteNode->pright;
        }
    }
    
    cout << "删除成功！" << endl;
}

void BinarySearchTree::SearchNode(int searchElement){
    Node *p = baseNode;
    while(p != NULL){
        if (p->data == searchElement){
            cout << searchElement << " = " << p->data;
            cout << "   查找成功！" << endl;
            break;
        }
        else if (p->data > searchElement){
            cout << searchElement << " < " << p->data;
            cout << "   查找当前结点的左子树" << endl;
            p = p->pleft;
        }
        else{
            cout << searchElement << " > " << p->data;
            cout << "   查找当前结点的右子树" << endl;
            p = p->pright;
        }  
    }
    if (!p){
        cout << "无此元素，查找失败！" << endl;
    }
}

bool BinarySearch(vector<int> array, int searchData){
    //array中元素按升序排列
    int high = array.size() - 1;
    int low = 0;
    int mid;
    cout << "在array[0]到array[" << high << "]中查找" << endl;
    while(high >= low){
        mid = (high + low) / 2;
        if (array[mid] == searchData){
            cout << array[mid] << " = " << searchData;
            cout << "查找成功！" << endl;
            return true;
        }
        else if (array[mid] > searchData){
            cout << array[mid] << " > " << searchData;
            cout << "\t在array[" << low << "]到array[" << mid-1 << "]查找" << endl;
            high = mid - 1;
        }
        else{
            cout << array[mid] << " < " << searchData;
            cout << "\t在array[" << mid + 1 << "]到array[" << high << "]" << endl;
            low = mid + 1;
        }
    }
    cout << "查找失败！" << endl;
    return false;
}

void test1(vector<int> array){
    cout << "数组元素：";
    for(int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }
    cout << endl;
    int element;
    char flag = 'Y';
    while(flag == 'Y'){
        cout << "请输入你要查找的元素：";
        cin >> element;
        BinarySearch(array, element);
        cout << "是否继续(Y/N): ";
        cin >> flag;
    }
}

void Menu(void){
    cout << "-------------------------------------------\n";
    cout << "1.采用二分查找算法查找相关数据" << endl;
    cout << "2.创建二叉排序树" << endl;
    cout << "3.在二叉排序树种查找结点" << endl; 
    cout << "4.在二叉排序树种删除结点" << endl;
    cout << "5.创建一棵平衡的二叉排序树" << endl;
    cout << "注：输入-1退出程序！"<< endl;
    cout << "-------------------------------------------\n";
}

int main(void){
    vector<int> array1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> array2 ={5, 3, 7, 2, 4, 8, 9, 6};
    vector<int> array3 ={1, 3,9, 2, 7, 5, 4};
    vector<int> array4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
                          14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
    BinarySearchTree bst;
    AVL a;
    int t;
    while(1){
        Menu();
        cout << "请输入题号：";
        cin >> t;
        switch (t)
        {
        case 1:
            test1(array1);
            system("pause");
            break;

        case 2:
           bst.CreateBST(array2);
           bst.InorderTaversal(bst.GetBaseNode());
           cout << endl;
           bst.LevelTaversal(bst.GetBaseNode());
           system("pause");
           break;

        case 3:
            int n;
            bst.CreateBST(array2);
            cout << "二叉排序树：" << endl;
            bst.LevelTaversal(bst.GetBaseNode());
            cout << "请输入查找元素：";
            cin >> n;
            bst.SearchNode(n);
            system("pause");
            break;
        case 4:
            int x;
            bst.CreateBST(array2);
            cout << "二叉排序树：" << endl;
            bst.LevelTaversal(bst.GetBaseNode());
            cout << "请输入要删除元素：";
            cin >> x;
            bst.DeleteNode(x);
            cout << "删除元素" << x << "后的二叉排序树：" << endl;
            bst.LevelTaversal(bst.GetBaseNode());
            system("pause");
            break;
        case 5:
            a.createAVL(array4);
            cout << "平衡二叉树(中序)：" << endl;
            a.inorderTravel(a.getRoot());
            cout << "平衡二叉树(层序)：" << endl;
            a.levelTravel(a.getRoot());
            system("pause");
            break;
        default:
            return 0;
        }

        system("cls");
    }
}