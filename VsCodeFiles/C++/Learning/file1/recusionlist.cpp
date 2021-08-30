//基于栈的单向链表逆置
#include <iostream>
#include <string>
#include <cstdlib>
#define MAX 20
using namespace std;
//结点数据
struct person
{
    int number;
    string name;
    struct person *pnext;
};
//栈类
class stack
{
private:
    struct person *stackdate[MAX];
    int stacktop;
public:
    stack();
    bool pushstack(struct person *p);
    bool popstack(struct person *x);
    struct person* getstacktop();
    bool emptystack();
    bool fullstack();
};
stack::stack()
{
    stacktop=-1;
}
bool stack::pushstack(struct person *p)
{
    stackdate[stacktop+1]=p;
    stacktop++;
    return true;
}
bool stack::popstack(struct person *x)
{
    x=stackdate[stacktop];
    stacktop--;
    return true;
}
struct person * stack::getstacktop()
{
    if(stacktop==-1)
    {
        return NULL;
    }
    return stackdate[stacktop];
}
bool stack::emptystack()
{
    if(stacktop==-1)
    {
        return true;
    }
    return false;
}
bool stack::fullstack()
{
    if(stacktop==MAX)
    {
        return true;
    }
    return false;
}
struct person *Creatlist(void);
void Travelist(struct person *sp);
void Recusionlist(struct person *sp);

int main(void)
{
    struct person *students;
    students=Creatlist();
    Travelist(students);
    Recusionlist(students);
    Travelist(students);
    delete students;
    return 0;
}

struct person * Creatlist(void)//建立链表
{
    struct person *head, *p1, *p2;
    int num;
    string nam;
    p1= new struct person;
    if(p1==NULL)
    {
        cout << "ERROR!";
        exit(-1);
    }
    head=p1;
    head->pnext=p1;
    do
    {
        cin >> num;
        if(num==-1)
        {
            break;
        }
        cin >> nam;
        p2= new struct person;
        p2->name=nam;
        p2->number=num;
        p2->pnext=NULL;
        p1->pnext=p2;
        p1=p2;
    } while (1);
    return head;
}
void Travelist(struct person *sp)//遍历链表
{
    struct person *x;
    x=sp->pnext;
    while(x!=NULL)
    {
        cout << x->name << endl;
        cout << x->number << endl;
        x=x->pnext;
    }
    return;
}
void Recusionlist(struct person *sp)//链表逆置
{
    struct person *p, *x, *ptemp;
    stack stackx;
    p=sp->pnext;
    while(p!=NULL)
    {
        stackx.pushstack(p);    //将每个结点的指针存入栈
        p=p->pnext;
    }
    sp->pnext=stackx.getstacktop();//让头指针指向原链表最后一个结点的
    while(!stackx.emptystack())
    {
        ptemp = stackx.getstacktop();//取出结点指针
        stackx.popstack(x);
        ptemp->pnext=stackx.getstacktop();//让其指向前一个结点
    }
}
//缺陷：由于栈是基于数组建立的，可能会浪费大量内存
//改进：可采用基于动态内存的栈实现该需求



