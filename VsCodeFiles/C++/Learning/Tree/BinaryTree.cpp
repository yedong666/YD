#include <iostream>
#include <queue>
#include <string>
using namespace std;

typedef struct TreeNode{
    char date;
    TreeNode *pleft;
    TreeNode *pright;
}TreeNode;
string s[100];
int num = 0;
class BinaryTree{
private:
    TreeNode *baseNode;
    queue<TreeNode*> myqueue;
public:
    BinaryTree();
    void CreateSonTree(TreeNode **childTree, FILE *pf);     //建立子树
    void CreateTree(void);                                  //建立树
    void PreorderTraversal(TreeNode *node);     //先序遍历
    //void InorderTaversal(TreeNode *node);       //中序遍历
    //void PostorderTraversal(TreeNode *node);    //后序遍历
    void LevelTraversal1(TreeNode *node);        //层序遍历(基于数组)
    void LevelTraversal2(TreeNode *node);        //层序遍历(基于队列)
    void PutDateAndLevel(TreeNode *node, int level = 1);       //输出二叉树各结点的数据与对应的层数（中序）
    int GetTreeHeight(TreeNode *node);          //求二叉树高度
    int GetNodeNum(TreeNode *node);             //求二叉树结点个数
    void GetNodeFamilyDate(TreeNode *node, char nodeDate);     //获取结点的家庭成员信息
    void GetLeavesPath(TreeNode *node, string & str);                 //返回叶子结点到根节点的路径
    void PutAllPath(TreeNode *node , string & str);                   //输出所有节点到根节点的路径
    TreeNode * GetBaseNode(void);               //返回根结点
};

BinaryTree::BinaryTree(){
    baseNode = NULL;
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

void BinaryTree::LevelTraversal1(TreeNode *node){
    TreeNode **tempDate = new TreeNode*[GetNodeNum(node)];  //建立可存放二叉树所有节点数据的数组
    int i = 0, j = 1;
    tempDate[0] = node;
    while(j < GetNodeNum(node)){
        tempDate[j++] = tempDate[i]->pleft;
        tempDate[j++] = tempDate[i]->pright;
        i++;
    }
    for(int k = 0; k < j; k++){
        cout << tempDate[k]->date << endl;
    }
    return;
}

void BinaryTree::LevelTraversal2(TreeNode *node){
    TreeNode *p = node;
    while(p!=NULL){
        cout << p->date << endl;
        myqueue.push(p->pleft);
        myqueue.push(p->pright);
        p = myqueue.front();
        myqueue.pop();
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

/*
键盘输入一个元素x，求其父节点、兄弟结点、子结点的值，
不存在时给出相应提示信息。对兄弟结点和孩子结点，存在时要明确指出是左兄弟、左孩子、右兄弟或右孩子。
*/

void BinaryTree::GetLeavesPath(TreeNode *node, string & str){
    if(node != NULL){
        str.push_back(node->date);
        if (node->pleft == NULL && node->pright == NULL){
            s[num++] = str;
        }
        //找到叶子结点就将已获得的路径保存到s数组
        else{
            GetLeavesPath(node->pleft, str);
            GetLeavesPath(node->pright, str);
        }
        //没找到叶子结点就继续寻找
        str.pop_back();
        //返回上一层之前需要把当前的路径点删除
        return;
    }
}

void BinaryTree::PutAllPath(TreeNode *node , string & str){
    if (node != NULL){
       str.push_back(node->date);
       int i = str.length()-1;
       while(i>0){
           cout << str[i] << "->";
           i--;
       }
       cout << baseNode->date <<endl;
       PutAllPath(node->pleft, str);
       PutAllPath(node->pright, str);
       str.pop_back();
    }
}

int main(void){
    BinaryTree myTree;
    string str;;
    myTree.CreateTree();
    // cout << myTree.GetBaseNode()->date;
    // myTree.PreorderTraversal(myTree.GetBaseNode());
    // myTree.PutDateAndLevel(myTree.GetBaseNode());
    // cout << "树的高度是：" << myTree.GetTreeHeight(myTree.GetBaseNode()) << endl;;
    // cout << "树一共有" << myTree.GetNodeNum(myTree.GetBaseNode()) << "个结点" << endl;
    // cout << "层序遍历：";
    // myTree.LevelTraversal(myTree.GetBaseNode());
    // cout << endl;
    // myTree.GetPath(myTree.GetBaseNode(), str);
    // for(int i = 0; i<num; i++){
    //     cout << s[i] << endl;
    // }
    myTree.PutAllPath(myTree.GetBaseNode(), str);
    return 0;
}
