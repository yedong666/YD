//单向链表的各功能实现
#include <iostream>
using namespace std;

class Node
{
public:
    int date;
    Node *pnext;
};

class List
{
public:
    Node *head;
    int length;
public:
    List();
    void Createlist();      //生成链表
    void Travellist();      //遍历链表
    void Sortlist();        //链表排序
    void Addnode(int date1, int date2, int date3);         //在指定位置插入新节点
    void Addnode_head(int newndate);    //头插结点
    void Addnode_trail(int newdate);   //尾插结点
    void Inversionlist();   //链表逆置
    void Deletenode(int deletedate);      //删除指定结点
    void Deletelist();      //删除链表
    void Getlistlength();   //获取链表长度
};

List::List()
{
    head=NULL;
    length=0;
}

void List::Createlist()
{
    Node *p1, *p2;
    p1=new Node;          
    head=p1;
    head->pnext=NULL;
    do
    {
        int a;
        cout << "Please input date:";
        cin >> a;
        if(a==0)
        {
            break;
        }
        p2=new Node;
        p2->date=a;
        p2->pnext=NULL;
        p1->pnext=p2;
        p1=p2;
        length++;
    } while(1);
};

void List::Travellist()
{
    Node *p;
    p=head->pnext;
    while(p!=NULL)
    {
        cout << "Date is: " << p->date << endl;
        p=p->pnext;
    }
}

void List::Sortlist()
{
    Node *x, *y, *k, temp;
    x=head->pnext;
    for(x;x->pnext!=NULL;x=x->pnext)
    {
        k=x;
        for(y=x->pnext;y!=NULL;y=y->pnext)
        {
            if(k->date>y->date)
            {
                k=y;
            }
        }
        if(k!=x)
        {
            temp=*k;                //交换两结点数据域，不改变指针指向
            k->date=x->date;
            x->date=temp.date;
        }
    }
}

void List::Getlistlength()
{
    cout << "The length of linklist is: " << length << endl;
}

void List::Addnode(int date1, int date2, int date3)
{
    if(length<2)
    {
        cout << "It's error!" << endl;
        return;
    }
    Node *p, *q, *Newnode;
    p=head->pnext;
    q=p->pnext;
    while((p->date!=date1||q->date!=date2)&&q->pnext!=NULL)
    {
        p=p->pnext;
        q=q->pnext;
    }
    if(p->pnext==NULL)
    {
        cout << "It's error!" << endl;
        return;
    }
    Newnode=new Node;
    Newnode->date=date3;
    p->pnext=Newnode;
    Newnode->pnext=q;
    length++;
}

void List::Addnode_head(int newdate)
{
    Node *p, *q;
    p=head->pnext;
    q=new Node;
    q->date=newdate;
    head->pnext=q;
    q->pnext=p;
    length++;
}

void List::Addnode_trail(int newdate)
{
    Node *p, *q;
    p=head->pnext;
    while(p->pnext!=NULL)
    {
        p=p->pnext;
    }
    q=new Node;
    q->date=newdate;
    q->pnext=NULL;
    p->pnext=q;
    length++;
}

void List::Deletenode(int deletedate)
{
    if(head->pnext==NULL)
    {
        cout << "It's error!" << endl;
        return;
    }
    Node *p, *q;
    p=head;
    while(p->pnext->date!=deletedate&&p->pnext)
    {
        p=p->pnext;
    }
    if(p->pnext==NULL)
    {
        cout << "No date that you want to delete!" << endl;
        return;
    }
    q=p->pnext->pnext;
    delete p->pnext;
    p->pnext=q;
    length--;
}

void List::Deletelist()
{
    Node *p, *q;
    p=head;
    while(p!=NULL)
    {
        q=p;
        delete q;
        p=p->pnext;
    }
    cout << "This linklist has been deleted!" << endl;
    return;
}

bool Union_list(List & A, List & B){
    Node *pa = A.head->pnext, *pb = B.head->pnext;
    while(pa->pnext!=A.head){
        pa = pa->pnext;
    }
    while(pb->pnext!=B.head){
        pb = pb->pnext;
    }
    pa->pnext = B.head->pnext;
    delete B.head;
    pb->pnext = A.head;
    return true;
}

int main(void)
{
    List list1;
    list1.Createlist();
    list1.Travellist();
    cout << "The linklist after sorting is:" << endl;
    list1.Sortlist();
    list1.Travellist();
    cout << "The linklist after adding a new node is:(addnode)" << endl;
    list1.Addnode(3,5,4);
    list1.Travellist();
    cout << "The linklist after adding a new node is:(addnode_head)" << endl;
    list1.Addnode_head(1);
    list1.Travellist();
    cout << "The linklist after adding a new node is:(addnode_trail)" << endl;
    list1.Addnode_trail(7);
    list1.Travellist();
    cout << "The linklist after deleting a node is:" << endl;
    list1.Deletenode(6);
    list1.Travellist();
    cout << "Thie linklist's length is:";
    list1.Getlistlength();
    list1.Deletelist();
    return 0;
}