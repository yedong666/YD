#include <iostream>
#include <queue>
#include <string>
#define MAXLEN 100
using namespace std;

typedef struct TreeNode{
    char date;
    TreeNode *pleft;
    TreeNode *pright;
}TreeNode;
/***********************/
string s[100];
int num = 0;
//保存路径信息
/***********************/
static int iflag = 0;
//记录访问结点个数
/***********************/

//以顺序表存储的二叉树
//对于一个结点，若data = -1, 则该结点为空;
typedef struct ArrayTreeNode{
    char date;
    int pleft;
    int right;
}ArrayTreeNode;

class ArrayTree{
public:
    int nodeNum = 0;
    ArrayTreeNode binaryTree[100];
    ArrayTree(char *s, int index);
};

ArrayTree::ArrayTree(char s[], int index){
    for(int i = 1; i < index; i++){
        cout << s[i];
        binaryTree[i].date = s[i];
        binaryTree[i].pleft = i*2;
        binaryTree[i].right = i*2 + 1;
        nodeNum++;
    }
}

class BinaryTree{
private:
    TreeNode *baseNode;
    queue<TreeNode*> myqueue;
public:
    BinaryTree();
    BinaryTree(TreeNode *node);
    void CreateSonTree(TreeNode **childTree, FILE *pf);     //建立子树
    void CreateTree(void);                                  //建立树
    void PreorderTraversal(TreeNode *node);     //先序遍历
    void InorderTaversal(TreeNode *node);       //中序遍历
    void PostorderTraversal(TreeNode *node);    //后序遍历
    void LevelTraversal2(TreeNode *node);                         //层序遍历(基于队列)
    void PutDateAndLevel(TreeNode *node, int level = 1);          //输出二叉树各结点的数据与对应的层数（中序）
    int GetTreeHeight(TreeNode *node);                            //求二叉树高度
    int GetNodeNum(TreeNode *node);                               //求二叉树结点个数
    void GetLeafNode(TreeNode *node);                             //求二叉树的叶子节点个数
    void GetTwoDegreeNode(TreeNode *node);                        //求二叉树度为二的结点个数
    void GetDateLevel(TreeNode *node, char nodeDate, int level, bool &flag);  //查找数据为nodeDate的结点层次
    void GetNodeFamilyDate(TreeNode *node, char nodeDate);        //获取结点的家庭成员信息
    void SwopLR(TreeNode *node);                                  //交换二叉树每个结点的左右孩子结点的值                                 
    TreeNode * GetBaseNode(void);                                 //返回根结点
};

BinaryTree::BinaryTree(){
    baseNode = NULL;
}

BinaryTree::BinaryTree(TreeNode *node){
    baseNode = node;
}

void BinaryTree::CreateSonTree(TreeNode **childTree, FILE *pf){
    char chDate, ch_left_flag, ch_right_flag;
    if(fscanf(pf, "%c %c %c\n", &chDate, &ch_left_flag, &ch_right_flag)==EOF){
        cout << "文件已读取完毕！" << endl;
        return;
    }
    *childTree = new TreeNode;
    (*childTree)->date = chDate;
    (*childTree)->pleft = NULL;
    (*childTree)->pright = NULL;
    if(ch_left_flag != '&')
    CreateSonTree(&(*childTree)->pleft, pf);
    if(ch_left_flag != '&')
    CreateSonTree(&(*childTree)->pright, pf);
}

void BinaryTree::CreateTree(void){
    baseNode = new TreeNode;
    char chDate, ch_left_flag, ch_right_flag;
    FILE *pf;
    if (pf = fopen("TestDate.txt", "r")){
        cout << "文件打开成功！" << endl;
    }
    fscanf(pf, "%c %c %c\n", &chDate, &ch_left_flag, &ch_right_flag);
    baseNode->date = chDate;
    baseNode->pleft = NULL;
    baseNode->pright = NULL;
    if(ch_left_flag != '&')
    CreateSonTree(&baseNode->pleft, pf);
    if(ch_left_flag != '&')
    CreateSonTree(&baseNode->pright, pf);
    fclose(pf);
}

void BinaryTree::PreorderTraversal(TreeNode *node){
    if (node!=NULL){
        cout << node->date << endl;
        PreorderTraversal(node->pleft);
        PreorderTraversal(node->pright);
    }
}

void BinaryTree::InorderTaversal(TreeNode *node){
    if (node!=NULL){
        PreorderTraversal(node->pleft);
        cout << node->date << endl;
        PreorderTraversal(node->pright);
    }
}

void BinaryTree::PostorderTraversal(TreeNode *node){
    if (node!=NULL){
        PreorderTraversal(node->pleft);
        PreorderTraversal(node->pright);
        cout << node->date << endl;
    }
}

TreeNode * BinaryTree::GetBaseNode(void){
    return baseNode;
}

int BinaryTree::GetNodeNum(TreeNode *node){
    if (node != NULL ){
        int numLeft, numRight;
        numLeft = GetNodeNum(node->pleft);
        numRight = GetNodeNum(node->pright);
        return 1 + numLeft + numRight;
    }
    else{
        return 0;
    }
}

static int leavNodeNum = 0; 
void BinaryTree::GetLeafNode(TreeNode *node){
    if (node != NULL){
        if (node->pleft == NULL && node->pright == NULL){
            leavNodeNum++;
        }
        GetLeafNode(node->pleft);
        GetLeafNode(node->pright);
    }
}

static int twoDegreeNodeNum = 0;
void BinaryTree::GetTwoDegreeNode(TreeNode *node){
    if (node != NULL){
        if (node->pleft != NULL && node->pright != NULL){
            twoDegreeNodeNum++;
        }
        GetTwoDegreeNode(node->pleft);
        GetTwoDegreeNode(node->pright);
    }
}

void BinaryTree::GetDateLevel(TreeNode *node, char nodeDate, int level, bool &flag){
    if (node != NULL){
        if (node->date == nodeDate){
            cout << "此元素在树中的层次为：" << level+1 << endl;
            flag = true;
        }
        GetDateLevel(node->pleft, nodeDate, level+1, flag);
        GetDateLevel(node->pright, nodeDate, level+1, flag);
    }
}

void BinaryTree::LevelTraversal2(TreeNode *node){
    TreeNode *p = node;
    if (p){
        myqueue.push(p);
    }
    while(!myqueue.empty()){
        p = myqueue.front();
        myqueue.pop();
        cout << p->date << endl;
        if (p->pleft){
            myqueue.push(p->pleft);
        }
        if (p->pright){
            myqueue.push(p->pright);
        }
    }
}

void BinaryTree::PutDateAndLevel(TreeNode *node, int level){
    if (node != NULL){
        PutDateAndLevel(node->pleft,level+1);
        cout << "date:" << node->date <<" level:" << level << endl;
        PutDateAndLevel(node->pright,level+1);
    }
}

int BinaryTree::GetTreeHeight(TreeNode *node){
    if(node!=NULL){
        int m, n;
        m = GetTreeHeight(node->pleft);
        n = GetTreeHeight(node->pright);
        return 1+(m>n?m:n);
    }
    else{
        return 0;
    }
}

void BinaryTree::GetNodeFamilyDate(TreeNode *node, char nodeDate){
    if (node != NULL){
        if (nodeDate == baseNode->date){
            cout << "此结点为根结点, 其无父节点,无兄弟结点！" << endl;
            if (node->pleft != NULL){
                cout << "其左孩子为" << node->pleft->date << endl;
            }
            else{
                cout << "此节点无左孩子！" << endl;
            }
            if (node->pright != NULL){
                cout << "其右孩子为" << node->pright->date << endl;
            }      
            else{
                cout << "此结点无有孩子！" << endl;
            }
            return;  
        }
        else{
            TreeNode *p;
            if (node->pleft->date != nodeDate && node->pright->date != nodeDate){
                GetNodeFamilyDate(node->pleft, nodeDate);
                GetNodeFamilyDate(node->pright, nodeDate);
            }
            else{
                if (node->pleft->date == nodeDate){
                    p = node->pleft;
                    cout << "此节点父节点为" << node->date << endl;
                    if (node->pright != NULL)
                    cout << "此结点兄弟结点（右兄弟）为" << node->pright->date << endl;
                    else cout << "此结点无兄弟结点" << endl;
                }
                if (node->pright->date == nodeDate){
                    p = node->pright;
                    cout << "此节点父节点为" << node->date << endl;
                    if (node->pleft != NULL)
                    cout << "此结点兄弟结点（左兄弟）为" << node->pleft->date << endl;
                    else cout << "此结点无兄弟结点" << endl;
                }
                if (p->pleft != NULL){
                    cout << "其左孩子为" << p->pleft->date << endl;
                }
                else{
                    cout << "此节点无左孩子！" << endl;
                }
                if (p->pright != NULL){
                    cout << "其右孩子为" << p->pright->date << endl;
                }      
                else{
                    cout << "此结点无右孩子！" << endl;
                }
                return;
            }    
        }    
    }
}

void BinaryTree::SwopLR(TreeNode *node){
    if (node != NULL){
        SwopLR(node->pleft);
        SwopLR(node->pright);
        TreeNode *ptemp;
        ptemp = node->pleft;
        node->pleft = node->pright;
        node->pright = ptemp;
    }
}

void TurnArray(TreeNode **node , ArrayTree *a_node, int index){
    if (index <= a_node->nodeNum){
        int left = a_node->binaryTree[index].pleft;
        int right = a_node->binaryTree[index].right;
        *node = new TreeNode;
        (*node)->date = a_node->binaryTree[index].date;
        (*node)->pleft =NULL;
        (*node)->pright = NULL;
        if (a_node->binaryTree[left].date != '#')
        TurnArray(&((*node)->pleft), a_node, left);
        if (a_node->binaryTree[right].date != '#')
        TurnArray(&((*node)->pright), a_node, right);
    }
}

void Menu(void){
    cout << "<1>打印出二叉树的三种遍历序" << endl;
    cout << "<2>设计算法按中序次序输出二叉树中各结点的值及其所对应的层次数" << endl;
    cout << "<3>求二叉树的高度" << endl;
    cout << "<4>求二叉树的结点数" << endl;
    cout << "<5>求二叉树的叶子结点数" << endl;
    cout << "<6>求二叉树的度为2的结点数" << endl;
    cout << "<7>键盘输入一个元素x，求其父节点、兄弟结点、子结点的值，" <<
            "不存在时给出相应提示信息。对兄弟结点和孩子结点，" <<
            "存在时要明确指出是左兄弟、左孩子、右兄弟或右孩子" << endl;
    cout << "<8>键盘输入一个元素x，求其在树中的层次。不存在时给出相应提示信息" << endl;
    cout << "<9>将按顺序方式存储在数组中的二叉树转换为二叉链表形式。（数组中要扩展为完全二叉树）。" << endl;
    cout << "<10>交换二叉树中每个结点的左右孩子指针的值。（即：左子树变为右子树，右子树变为左子树）" << endl;
    cout << "<11>层序遍历二叉树" << endl;
    cout << "(输入-1退出程序)" << endl;
}

int main(void){
    char s[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '#', '#', '#', '#', '#', '#', '#', '#'};
    BinaryTree myTree;
    bool flag = false;
    ArrayTree *myArrayTree = new ArrayTree(s, 16);
    TreeNode *node;
    TurnArray(&node, myArrayTree, 1);
    BinaryTree testTree(node);
    myTree.CreateTree();
    while(1){
        Menu();
        int testNum;
        cout << "请输入题号：" << endl;
        cin >> testNum;
        switch (testNum){
            case 1: cout << "先序遍历：" << endl;
                    myTree.PreorderTraversal(myTree.GetBaseNode());
                    cout << "中序遍历:" << endl;
                    myTree.InorderTaversal(myTree.GetBaseNode());
                    cout << "后序遍历:" << endl;
                    myTree.PostorderTraversal(myTree.GetBaseNode());
                    system("pause");
                    break;
            case 2: myTree.PutDateAndLevel(myTree.GetBaseNode());
                    system("pause");
                    break;
            case 3: cout << "此二叉树的高度为：" << myTree.GetTreeHeight(myTree.GetBaseNode()) << endl;
                    system("pause");
                    break;
            case 4: cout << "此二叉树的结点个数为：" << myTree.GetNodeNum(myTree.GetBaseNode()) << endl;
                    system("pause");
                    break;
            case 5: myTree.GetLeafNode(myTree.GetBaseNode());
                    cout << "二叉树的叶子结点个数为：" << leavNodeNum << endl;
                    system("pause");
                    break;
            case 6: myTree.GetTwoDegreeNode(myTree.GetBaseNode());
                    cout << "此二叉树度为2的结点个数为：" << twoDegreeNodeNum << endl;
                    system("pause");
                    break;
            case 7: char element;
                    cout << "请输入你要查找的元素：";
                    cin >> element;
                    myTree.GetNodeFamilyDate(myTree.GetBaseNode(), element);
                    system("pause");
                    break;
            case 8: char date;
                    cout << "请输入你要查找的元素：";
                    cin >> date;
                    myTree.GetDateLevel(myTree.GetBaseNode(), date, 0, flag);
                    if (!flag){
                        cout << "此二叉树中无此元素" << endl;
                    }
                    system("pause");
                    break;
            case 9: testTree.PreorderTraversal(testTree.GetBaseNode());
                    system("pause");
                    break;
            case 10:cout << "交换二叉树各节点左右孩子结点指针前(先序遍历)：" << endl;
                    myTree.PreorderTraversal(myTree.GetBaseNode());
                    myTree.SwopLR(myTree.GetBaseNode());
                    cout << "交换二叉树各节点左右孩子结点指针后(先序遍历):" << endl;
                    myTree.PreorderTraversal(myTree.GetBaseNode());
                    system("pause");
                    break;
            case 11:myTree.LevelTraversal2(myTree.GetBaseNode());
                    system("pause");
                    break;
            default:
                    return -1;
        }
        system("cls");

    }
    return 0;
}
