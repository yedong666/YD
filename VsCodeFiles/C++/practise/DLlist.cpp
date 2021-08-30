//双向链表的部分功能实现，细节有待完善
#include <iostream>
using namespace std;
typedef int Nodedate;
struct Node
{
    Nodedate date;
    struct Node *plast;
    struct Node *pnext;
};

class DLlist
{
private:
    struct Node *Head;
    int Listlength;
public:
    DLlist();
    void CreateDLlist();
    void TravelDLlist();
    void InsertDLlsit(Nodedate lastdate, Nodedate nextdate, Nodedate localdate);
};
DLlist::DLlist()
{
    Listlength=0;
}
void DLlist::CreateDLlist()
{
    struct Node *ptemp,*p;
    ptemp=new struct Node;
    Head=ptemp;
    Head->pnext=ptemp;
    while(1)
    {
        cout << "Please input your date!" << endl;
        int datex;
        cin >> datex;
        if(datex==0)
        {
            break;
        }
        p=new struct Node;
        p->date=datex;
        p->plast=ptemp;
        p->pnext=NULL;
        ptemp->pnext=p;
        ptemp=p;
        Listlength++;
    }
}
void DLlist::TravelDLlist()
{
    struct Node *x;
    x=Head->pnext;
    while(x!=NULL)
    {
        cout << x->date << endl;
        x=x->pnext;
    }
    return;
}
void DLlist::InsertDLlsit(Nodedate lastdate, Nodedate nextdate, Nodedate localdate)
{
    struct Node *x, *p;
    x=Head->pnext;
    while(x->date!=lastdate||(x->pnext)->date!=nextdate)
    {
        x=x->pnext;
    }
    p=new struct Node;
    p->date=localdate;
    p->pnext=x->pnext;
    x->pnext=p;
    p->plast=x;
}

int main(void)
{
    DLlist listx;
    listx.CreateDLlist();
    listx.TravelDLlist();
    listx.InsertDLlsit(2,4,3);
    listx.TravelDLlist();
    return 0;
}
