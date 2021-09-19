#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

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
        node = new Node;
        node->data = newdata;
        node->pleft = NULL;
        node->pright = NULL;
    }
    else{
        if (newdata < node->data){
            InsertNode(node->pleft, newdata);
        }else if (newdata > node->data){
            InsertNode(node->pright, newdata);
        }
        else{
            cout << "二叉查找树中不能存在键值相同的结点。" << endl;
            return;
        } 
    }
}

void BinarySearchTree::CreateBST(vector<int> dataArray){
    for(int i = 0; i < dataArray.size(); i++){
        InsertNode(baseNode, dataArray[i]);
    }
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
        Node *tempNode;
        if(node){
            myqueue.push(node);
        }
        while(!myqueue.empty()){
            tempNode = myqueue.front();
            myqueue.pop();
            cout << tempNode->data << " ";
            if (tempNode->pleft){
                myqueue.push(tempNode->pleft);
            }
            if (tempNode->pright){
                myqueue.push(tempNode->pright);
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

int main(void){
    vector<int> testArray ={5, 3, 7, 2, 4, 8, 9, 6};
    BinarySearchTree testTree;
    testTree.CreateBST(testArray);
    cout << "中序遍历：";
    testTree.InorderTaversal(testTree.GetBaseNode());
    cout << "\n层序遍历：";
    testTree.LevelTaversal(testTree.GetBaseNode());
    cout << "------------------------------------------\n";
    // testTree.DeleteNode(5);
    // cout << "中序遍历：";
    // testTree.InorderTaversal(testTree.GetBaseNode());
    // cout << "\n层序遍历：";
    // testTree.LevelTaversal(testTree.GetBaseNode());
    int temp;
    cout << "请输入查找元素：";
    cin >> temp;
    testTree.SearchNode(temp);
    return 0;
}