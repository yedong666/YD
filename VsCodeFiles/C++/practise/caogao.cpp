#include <iostream>
struct TreeNode
{
    char date;
    struct TreeNode *plchild;
    struct TreeNode *prchild;
};
typedef struct TreeNode TreeNode;
class Tree
{
private:
    TreeNode *BaseNode;             //根节点
    int Node_number;                //节点数
    int Treeheight;                 //树的高度
public:
    Tree();                         //初始化树
    void VisitTree(TreeNode *pnode);//访问树的结点方式
    void CreateSonTree(TreeNode *pchild, int iflag);    //建立子树
    void CreateTree();                                  //建立树
    void TravelTree(TreeNode *pnode);                   //遍历树
    TreeNode * GetBasenode();                           //获取根节点
    int Getnumber();                                    //获取树的结点数
    int Getheightleft(TreeNode *pnode);                                    //获取左子树的高度
    int Getheightright(TreeNode *pnode);                                   //获取右子树的高度
    int Getheight(TreeNode *pnode);                                        //获取树的高度
};
using namespace std;
Tree::Tree()
{
    BaseNode=NULL;
    Node_number=0;
    Treeheight=0;
}
void Tree::CreateSonTree(TreeNode *pchild, int iflag)
{
    char chx;
    cout <<"Please input your tree date:" << endl;
    cin >> chx;
    if(chx!='.')
    {
        TreeNode *ptemp;
        ptemp=new TreeNode;
        ptemp->date=chx;
        ptemp->plchild=NULL;
        ptemp->prchild=NULL;
        if(iflag==0)
        {
            pchild->plchild=ptemp;
        }
        if(iflag==1)
        {
            pchild->prchild=ptemp;
        }
        Node_number++;
        CreateSonTree(ptemp,0);
        CreateSonTree(ptemp,1);
    }
}
void Tree::CreateTree()
{
    if(BaseNode!=NULL)
    {
        cout << "It has created tree." << endl;
        return;
    }
    char chx;
    cout << "Please input your tree date:" << endl;
    cin >> chx;
    if(chx!='.')
    {
        TreeNode *ptemp;
        ptemp=new TreeNode;
        ptemp->date=chx;
        ptemp->plchild=NULL;
        ptemp->prchild=NULL;
        BaseNode=ptemp;
        //输入根节点数据
        Node_number++;
        Treeheight++;
        CreateSonTree(ptemp,0);
        CreateSonTree(ptemp,1);
    }
}
void Tree::VisitTree(TreeNode *pnode)
{
    cout << pnode->date <<endl;
    return;
}
void Tree::TravelTree(TreeNode *pnode)
{
    if(pnode!=NULL)
    {
        VisitTree(pnode);
        TravelTree(pnode->plchild);
        TravelTree(pnode->prchild);
        return;
    }
}
TreeNode * Tree::GetBasenode()
{
    return BaseNode;
}
int Tree::Getnumber()
{
    return Node_number;
}
int Tree::Getheightleft(TreeNode *pnode)
{
    if(pnode==NULL)
    {
        return 0;
    }
    return 1+Getheightleft(pnode->plchild);
}
int Tree::Getheightright(TreeNode *pnode)
{
    if(pnode==NULL)
    {
        return 0;
    }
    return 1+Getheightright(pnode->prchild);
}
int Tree::Getheight(TreeNode *pnode)
{
    int hl, hr, h;
    hl=Getheightleft(pnode);
    hr=Getheightright(pnode);
    h=hl>hr ? hl:hr;
    return h;
}
int main(void)
{
    string a, b, c;
    a="12345";
    b+=a[1];
    b+=a[2];
    cout << b;
    return 0;
}
