#include <iostream>
using namespace std;

typedef int Date;
typedef struct Node{
    struct Node *pioneer;
    Date Nodedate;
    struct Node *pnext;
}Node;
class Circularlinkedlist{
private:
    Node *Head, *Trail;
public:
    Circularlinkedlist();
    bool CreateList(void);
    bool ReverseTravel(void);
    bool TravelList(void);
    bool is_symmetrylist(void);
    bool ReverseList(void);
};
Circularlinkedlist::Circularlinkedlist(){
    Head = new Node;
    Head->pioneer = Head;
    Head->pnext = Head;
    Head->Nodedate = -1;
    Trail = Head;
}
bool Circularlinkedlist::CreateList(void){
    Node *p, *pnew;
    int newdate;
    p = Head;
    while(1){
        cout << "请输入数据：" << endl;
        cin >> newdate;
        if (newdate == -1){
            break;
        }
        pnew = new Node;
        pnew->Nodedate = newdate;
        pnew->pioneer = p;
        pnew->pnext = Head;
        p->pnext = pnew;
        Head->pioneer = pnew;
        p = pnew;
    }
    Trail = p;
    cout << "创建循环双链表结构成功！" << endl;
    return true;
}
bool Circularlinkedlist::TravelList(void){
    Node *p;
    p = Head->pnext;
    while(p!=Head){
        cout << p->Nodedate << endl;
        p = p->pnext;
    }
    cout << "遍历结束！" << endl;
    return true;
}
bool Circularlinkedlist::ReverseTravel(void){
    Node *p;
    p = Trail;
    do{
        cout << p->Nodedate << endl;
        p = p->pioneer;
    }while(p->pioneer!=Trail);
    return true;
}
bool Circularlinkedlist::is_symmetrylist(void){
    if(Head == Trail){
        cout << "这是一个空表！" << endl;
        return false;
    }
    Node *p1, *p2;
    p1 = Head->pnext;
    p2 = Trail;
    while(p1!=p2){
        if(p1->Nodedate != p2->Nodedate){
            cout << "这是一个非对称表！" << endl;
            return false;
        }
        p1 = p1->pnext;
        p2 = p2->pioneer;
    }
    cout << "这是一个对称表！" << endl;
    return true;  
}

bool Circularlinkedlist::ReverseList(void){
    Node *p, *ptemp;
    p = Head;
    do{
        ptemp = p->pnext;
        p->pnext = p->pioneer;
        p->pioneer = ptemp;
        p = p->pioneer;
    }while(p!=Head);
    return true;
}
//显然，逆置双循环链表，交换链表每个结点的前驱指针与后继指针即可

int main(void){
    Circularlinkedlist list1;
    list1.CreateList();
    list1.TravelList();
//    list1.ReverseTravel();
//    list1.is_symmetrylist();
    list1.ReverseList();
    list1.TravelList();
    return 0;
}