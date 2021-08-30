#include <iostream>
#include <vector>
#include <random>
#include <queue>
#include <string>
using namespace std;

/*
路径：
在一棵树中，从一个节点往下到另一个结点之间的通路
称为路径，通路中分支的数目称为路径长度。

二叉树带权路径长度(WPL)：
假设二叉树有n个叶子节点，那么每个叶子节点到根节点的路径长度乘以
乘以叶子结点自身的权值的和即为二叉树的带权路径长度。

哈夫曼树：由给定的拥有固定权值的叶子节点构造出的一棵二叉树
此二叉树的WPL值最小
*/
class HuffmanTree{
private:
    int weight;             //权值
    string HuffmanCode;     //哈夫曼编码
    HuffmanTree *lchild;
    HuffmanTree *rchild;
public:
    HuffmanTree(int the_weight, HuffmanTree *left = NULL, HuffmanTree *right = NULL);   //对哈夫曼树结点相关数据赋值
    HuffmanTree*  CreateHFTree(int *w, int w_size);    //根据所给数据得到一棵哈夫曼树的根结点
    int GetWeight(void);                                //返回结点权值
    void GetHFCode(HuffmanTree *node, string & s);                  //获取哈夫曼编码
    void PrintHFCode(HuffmanTree *node);
};

HuffmanTree::HuffmanTree(int the_weight, HuffmanTree *left, HuffmanTree *right){
    weight = the_weight;
    lchild = left;
    rchild = right;
}

int HuffmanTree::GetWeight(void){
    return weight;
}

void HuffmanTree::GetHFCode(HuffmanTree *node, string & s){
    if(node != NULL){
        node->HuffmanCode = s;
        if (node->lchild != NULL)
        GetHFCode(node->lchild, s.append("0"));
        if (node->rchild != NULL)
        GetHFCode(node->rchild, s.append("1"));
        s.pop_back();
    }
}

void HuffmanTree::PrintHFCode(HuffmanTree *node){
    if (node != NULL){
        cout << node->HuffmanCode << endl;
        cout << node->lchild->HuffmanCode << endl;
        cout << node->rchild->HuffmanCode << endl;
        // PrintHFCode(node->lchild);
        // PrintHFCode(node->rchild);
    }    
}

//自定义优先队列优先级(权值小的优先)
struct cmp{
    bool operator() (HuffmanTree* node1, HuffmanTree* node2){
		return node1->GetWeight()>node2->GetWeight();
	}
};

HuffmanTree* HuffmanTree::CreateHFTree(int *w, int w_size){
    //定义优先队列
    priority_queue<HuffmanTree*, vector<HuffmanTree*>, cmp> Q;
    //参数1：元素类型   参数2：容器类型     参数3：优先级设定
    for(int i = 0; i < w_size; i++){
       HuffmanTree *t =  new HuffmanTree(w[i]);
       Q.push(t);
    }
    while(Q.size() != 1){
        HuffmanTree* left = Q.top();
	    Q.pop();
		HuffmanTree* right = Q.top();
		Q.pop();
		HuffmanTree* root = new HuffmanTree(left->GetWeight()+right->GetWeight(), left, right);
        Q.push(root);
    }
    HuffmanTree *root = Q.top();
	Q.pop();
	return root;		
}

int main(void){
    int array[10] = {1, 4};
    static string str = "0";
    HuffmanTree test(0);
    HuffmanTree *hft = test.CreateHFTree(array, 2);
    test.GetHFCode(hft, str);
    test.PrintHFCode(hft);
    return 0;
}

