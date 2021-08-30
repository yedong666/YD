//查找单链表倒数第k个数据， 找到打印该数据，并返回true, 否则返回false
//思路：final_flag记录链表最后一个数据位置
//      search_flag[i][1]记录所查找的数据
//      那么search_flag[final_flag - k + 1][1] 即为所要查找数据
//缺点：浪费大量空间？
#include <iostream>
#include <vector>
using namespace std;

//封装链表相关数据类型
typedef int Date;
typedef struct Node{
    Date Nodedate;
    struct Node *pnext;
}Node;

class LinkList{
private:
    Node *Head;
public:
    LinkList();
    LinkList(Node *ptemp);
    void Createlist(void);              //交互式输入链表数据
    bool Travellist(void);
    Node * ReturnHead(void);
    Node * ReturnTail(void);
    bool Head_AddNode(Date add_date);   //头插法添加新节点
    bool Tail_AddNode(Date add_date);   //尾插添加新结点
    bool Rear_InsertNode(Date frontdate, Date interset_date);//在任意结点之后插入新节点(根据数据域值)
    bool Front_InsertNode(Date reardate, Date interset_date);  //在任意结点之前插入新结点(根据数据域值)
    bool SearchNode_Number(int number);        //按编号查找结点(头结点为第0个结点，以此类推)
    bool SearchNode_Date(Date search_date);  //按值查找
    bool DeleteNode_Number(int number);        //按编号删除结点
    bool DeleteNode_Date(Date search_date);  //按值删除结点
    bool DaleteList(void);              //删除链表
};

//内联函数实现（未测试！！！）
/**********************************************************************************************/
//初始化空表
LinkList::LinkList(Node * ptemp){
    Head = ptemp;
}

//初始化头结点为空
LinkList::LinkList(){
    Head = NULL;
}

//生成链表
void LinkList::Createlist(void){
    Node *p1, *p2;
    p1 = new Node;
    p1->pnext = NULL;
    Head = p1;
    do{
        Date newdate;
        cout << "Please input your date:" << endl;
        cin >> newdate;
        if (newdate==-1){
            break;
        }
        p2 = new Node;
        p2->Nodedate = newdate;
        p2->pnext = NULL;
        p1->pnext = p2;
        p1 = p2;
    }while(1);
    return;
}

//遍历链表结点数据
bool LinkList::Travellist(void){
    if (Head==NULL || Head->pnext==NULL){
        cout << "此链表为空或未创建！" << endl;
        return false;
    }
    Node *p;
    p = Head->pnext;
    while(p!=NULL){
        cout << p->Nodedate << endl;
        p = p->pnext;
    }
    return true;
}

//返回头结点
Node * LinkList::ReturnHead(void){
    return Head;
}

//返回尾结点
Node * LinkList::ReturnTail(void){
    if (Head==NULL || Head->pnext==NULL){
        cout << "此链表为空或未创建！" << endl;
        return NULL;
    }
    Node *p;
    p = Head->pnext;
    while(p->pnext != NULL){
        p = p->pnext;
    }
    return p;
}

//头插法添加新结点
bool LinkList::Head_AddNode(Date add_date){
    if(Head==NULL){
        cout << "此链表未创建！" << endl;
        return false; 
    }
    Node *p, *newNode;
    newNode = new Node;
    p = Head->pnext;
    newNode->Nodedate = add_date;
    Head->pnext = newNode;
    newNode->pnext = p;
    cout << "添加结点成功（头插）" << endl;
    return false;
}

//尾插法添加新结点
bool LinkList::Tail_AddNode(Date add_date){
    Node *p;
    p = new Node;
    p->Nodedate = add_date;
    p->pnext = NULL;
    ReturnTail()->pnext = p;
    return false;
}

//在任意结点后添加新结点
bool LinkList::Rear_InsertNode(Date frontdate, Date interset_date){
    if (Head==NULL || Head->pnext==NULL){
        cout << "此链表为空或未创建！" << endl;
        return false;
    }
    Node *p;
    p = Head->pnext;
    while(p->Nodedate!=frontdate && p->pnext!=NULL){
        p = p->pnext;
    }
    if (p->pnext==NULL){
        cout << "未找到对应前驱结点！" << endl;
        return false;
    }
    Node *pnew_node, *pnext_node;
    pnew_node = new Node;
    pnext_node = p->pnext;
    pnew_node->Nodedate = interset_date;
    p->pnext = pnew_node;
    pnew_node->pnext = pnext_node;
    cout << "添加结点成功" << endl;
    return true;
}

//在任意结点之前添加新结点
bool LinkList::Front_InsertNode(Date reardate, Date interset_date){
    if (Head==NULL || Head->pnext==NULL){
        cout << "此链表为空或未创建！" << endl;
        return false;
    }
    Node *p;
    p = Head;
    while(p->pnext->Nodedate!=reardate && p->pnext!=NULL){
        p = p->pnext;
    }
    if (p->pnext==NULL){
        cout << "未找到指定元素！"  << endl;
        return false;
    }
    Node *pnew_node;
    pnew_node = new Node;
    pnew_node->Nodedate = interset_date;
    pnew_node->pnext = p->pnext;
    p->pnext = pnew_node;
    cout << "插入成功！" << endl;
    return true;
}

//按其在链表中所处位置查找结点
bool LinkList::SearchNode_Number(int number){
    if(number<0){
        cout << "编号不合法！"  << endl;
        return false;
    }
    if(number==0){
        cout << "头结点不存储数据！" << endl;
        return false;
    }
    int i = 1;
    Node *p;
    p = Head->pnext;
    while(p!=NULL){
        if(number == i){
            cout << "此链表第" << i << "个节点数据为" << p->Nodedate << endl;
            return true;
        }
        else{
            p = p->pnext;
            i++;
        }
    }
    cout << "编号超出范围!" << endl;
    return false;
}

//按其存储的数据值查找新结点
bool LinkList::SearchNode_Date(Date search_date){
    Node *p;
    int i = 1;
    p = Head->pnext;
    while(p!=NULL){
        if(p->Nodedate == search_date){
            cout << "查找数据在此链表第" << i << "个结点" << endl;
            return true;
        }
        else{
            p = p->pnext;
            i++;
        }
    }
    cout << "未查找到相关数据！" << endl;
    return false;
}

//按其在链表中所处位置删除结点
bool LinkList::DeleteNode_Number(int number){
     if(number<0){
        cout << "编号不合法！"  << endl;
        return false;
    }
    if(number==0){
        cout << "头结点不存储数据！" << endl;
        return false;
    }
    int i = 1;
    Node *p;
    p = Head->pnext;
    while(p!=NULL){
        if(number == i+1){
            Node *ptemp;
            ptemp = p->pnext;
            p->pnext = p->pnext->pnext;
            delete ptemp;
            cout << "已删除此链表第" << i+1 << "个结点" << endl;
            return true;
        }
        else{
            p = p->pnext;
        }
    }
    cout << "编号超出范围, 删除失败！" << endl;
    return false;
}

//按其存储的数据值删除新结点
bool LinkList::DeleteNode_Date(Date search_date){
    Node *p;
    int i = 1;
    p = Head->pnext;
    while(p!=NULL){
        if(p->pnext->Nodedate == search_date){
            Node *ptemp;
            ptemp = p->pnext;
            p->pnext = ptemp->pnext;
            delete ptemp;
            cout << "已删除存储数据" << search_date << "的结点" << endl;
            return true;
        }
        else{
            p = p->pnext;
            i++;
        }
    }
    cout << "未查找到相关数据, 删除失败！" << endl;
    return false;
}

//删除链表
bool LinkList::DaleteList(void){
    if (Head==NULL || Head->pnext==NULL){
        cout << "此链表为空或未创建！" << endl;
        return false;
    }
    Node *p;
    p = Head->pnext;
    while(p!=NULL){
        Node *ptemp;
        ptemp = p;
        p = p->pnext;
        delete ptemp;
    }
    cout << "已删除整个链表！"  << endl;
    return true;
}

//查找链表倒数第k个节点数据
bool Search_k_date1(LinkList & test_linklist, int k);    //第一版
bool Search_k_date2(LinkList & test_linklist, int k);    //第一版
//两版本算法时间复杂度相同，但第一版算法空间消耗大得多

//就地逆置链表
bool InversionList(LinkList & test_linklist);

//链表模拟集合并集A = A与B的并集
LinkList & UnionList(LinkList & A, LinkList & B);

//将两个递增有序的链表合并为一个递减有序的链表
LinkList & MergeList(LinkList & A, LinkList & B);

int main(void){
    LinkList mylist1, mylist2;
    mylist1.Createlist();
    Search_k_date2(mylist1, 3);
    return 0;
}

bool Search_k_date1(LinkList & test_linklist, int k){
    Node *ptemp;
    vector<Date> savedate;
    ptemp = test_linklist.ReturnHead()->pnext;
    int i = 0;
    while(ptemp != NULL){
        savedate[i++] = ptemp->Nodedate;
        ptemp = ptemp->pnext;
    }
    if (i<k) {
        return false;
    }
    else {
        cout << savedate[i-k] << endl;
        return true;
    }
}

bool InversionList(LinkList & test_linklist){
    if (test_linklist.ReturnHead()->pnext->pnext == NULL){
        cout << "此链表无需逆置" << endl;
        return false;
    }
    Node *pfront, *prear, *ptemp;
    pfront = test_linklist.ReturnHead()->pnext;
    prear = pfront->pnext;
    pfront->pnext = NULL;
    ptemp = NULL;
    while(prear!=NULL){
        ptemp = prear->pnext;
        prear->pnext = pfront;
        pfront = prear;
        prear = ptemp;
    }
    test_linklist.ReturnHead()->pnext = pfront;
    cout << "逆置成功！" << endl;
    return true;
}

LinkList & UnionList(LinkList & A, LinkList & B){
    Node *p1, *p2, *ptemp;
    p1 = A.ReturnHead()->pnext;
    p2 = B.ReturnHead()->pnext;
    while(p2!=NULL){
        while(p1!=NULL){
            if (p1->Nodedate == p2->Nodedate){
                break;
            }
            else{
                ptemp = p1; //临时指针变量，保存前一个结点
                p1 = p1->pnext;
            }
        }
        if(p1==NULL){
                p1 = new Node;
                p1->Nodedate = p2->Nodedate;
                p1->pnext = NULL;
                ptemp->pnext = p1;
            }
            p1 = A.ReturnHead()->pnext;
            p2 = p2->pnext;
    }
    return A;
}

LinkList & MergeList(LinkList & A, LinkList & B){
    Node *ptemp;
    ptemp = new Node;
    ptemp->pnext = NULL;
    static LinkList newlist(ptemp);
    Node *pa, *pb;
    pa = A.ReturnHead()->pnext;
    pb = B.ReturnHead()->pnext;
    while(pa!=NULL && pb!=NULL){
        if (pa->Nodedate <= pb->Nodedate){
            newlist.Head_AddNode(pa->Nodedate);
            pa = pa->pnext;
        }
        else{
            newlist.Head_AddNode(pb->Nodedate);
            pb = pb->pnext;
        }
    }
    if (pa==NULL){
        ptemp = pb;
    }
    else {
        ptemp = pa;
    }
    while(ptemp!=NULL){
        newlist.Head_AddNode(ptemp->Nodedate);
        ptemp =ptemp->pnext;
    }
    return newlist;    
}

LinkList & UnionForList(LinkList & A, LinkList & B){
    Node *pa, *pb;
    pa = A.ReturnHead()->pnext;
    pb = B.ReturnHead()->pnext;
    Node *p1, *p2, *ptemp;
    p1 = pa;
    p2 = pb;
    ptemp = NULL;
    while(pa!=A.ReturnHead()){
        pa = pa->pnext;
    }
    while(pb!=B.ReturnHead()){
        pb = pb->pnext;
    }
    while(p2!=pb && p1!=pa){
        if (p1->Nodedate == p2->Nodedate){
            ptemp = p2;
            p2 = ptemp->pnext;
            B.DeleteNode_Date(ptemp->Nodedate);
        }
        else if(p1->Nodedate > p2->Nodedate){
            p2 = p2->pnext;
        }
        else{
            p1 = p1->pnext;
        }
    }
    pa = B.ReturnHead();
    pb = A.ReturnHead();
    return A; 
}

bool Search_k_date2(LinkList & test_linklist, int k){
    Node *p1, *p2;
    int iflag = 0;
    p1 = test_linklist.ReturnHead()->pnext;
    p2 = p1;
    while(p1->pnext!=NULL){
        p1 = p1->pnext;
        iflag++;
        if(iflag > k-1){        //当p1与p2位置相差k-1个结点时，p2开始移动
            p2 = p2->pnext;     //则当p1到达最后一个结点时，p2所处位置即倒数第k个结点
        }
    }
    if (iflag < k){
        cout << "链表长度小于k" << endl;
        return false;
    }
    else{
        cout << p2->Nodedate << endl;
        return true;
    }
}