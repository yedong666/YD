#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//顾客类
class Customer
{
private:
    long arrive_time;
    int wait_time;
public:
    Customer()
    {
        arrive_time=0;
        wait_time=0;
    }
    Customer(long when)
    {
        arrive_time=when;
        wait_time=rand()%3+1;
    }
    long Getavtime()
    {
        return arrive_time;
    }
    int Getwitime()
    {
        return wait_time;
    }
   
};

struct Node
{
    Customer custor;
    int number;
    struct Node *pnext;
};

//队列类
class Queue
{
private:
    struct Node *head;
    struct Node *trail;
    int people_number;
    int people_size;
    int deleteflag;
public:
    Queue()
    {
        head=NULL;
        trail=NULL;
        people_number=0;
        deleteflag=0;
    }
    void Addnumber(Customer cstor);
    void Deletenumber();
    void Setsize(const int size);
    void Show_queue();   
};

void Queue::Addnumber(Customer cstor)
{
    if(people_number==people_size)
    {
        cout << "The queue is full!" << endl;
        return;
    }
    struct Node *temp;
    people_number++;
    temp=new struct Node;
    temp->custor=cstor;
    temp->number=people_number;
    temp->pnext=NULL;
    if(head==NULL)
    {
        head=temp;
        trail=temp;
        head->pnext=trail;
    }
    else
    {
        trail->pnext=temp;
        trail=temp;
    }
}

void Queue::Deletenumber()
{
    if(head==NULL)
    {
        cout << "It's error!" << endl;
        return;
    }
    deleteflag++;
    people_number--;
    struct Node *temp;
    temp=head;
    head=head->pnext;
    delete temp;
}

void Queue::Setsize(const int size)
{
    people_size=size;
}

void Queue::Show_queue()
{
    struct Node *p;
    p=head;
    while(p!=NULL)
    {
        cout << "Number:" << p->number << endl;
        cout << "Arrive time is " << p->custor.Getavtime() << endl;
        p=p->pnext;
    }
}

int main(void)
{
    Queue queue1;
    Customer custor1;
    Customer custor2;
    Customer custor3;
    Customer custor4;
    const int min_per_hr=60;
    int starttime, lasttime;
    cout << "Pleae input starting time:" ;
    cin >> starttime;
    cout << "Plaese input lasted time:";
    cin >> lasttime;
    return 0;
}