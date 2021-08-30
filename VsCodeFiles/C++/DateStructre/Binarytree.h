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