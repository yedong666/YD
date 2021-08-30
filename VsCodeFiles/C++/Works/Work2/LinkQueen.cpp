#include <iostream>
using namespace std;
typedef int Date;
typedef struct Node{
    Date node_date;
    Node *pnext;
}Node;

//创建单循环链表类
class OCLinklist{
public:
    Node *head, *trail;
    OCLinklist();
    bool AddNode(Date newdate);
    bool DeleteNode(void);
    bool TravelList(void);
};


//创建队列类
class Queue{
private:
    OCLinklist queen_list;
public:
    Queue() {}

    bool IsEmpty(void){
        if (queen_list.head->pnext == queen_list.trail){
            cout << "队列为空！" << endl;
            return true;
        }
        return false;
    }

    bool AddNumber(int new_number){
        if (queen_list.AddNode(new_number)) {
            return true;
        }
        return false;
    }

    bool DeleteNumber(void){
        if (queen_list.DeleteNode()){
            return true;
        }
        return false;
    }

    void TravelQueue(void){
        queen_list.TravelList();
        return;
    }
};

OCLinklist::OCLinklist(){
    head = new Node;
    head->pnext = NULL;
    trail = head;
    trail->pnext = head;
}

bool OCLinklist::AddNode(Date newdate){
    Node *newnode = new Node;
    newnode->node_date = newdate;
    trail->pnext = newnode;
    trail = newnode;
    trail->pnext = head;
    cout << "添加成功！" << endl;
    return true;
}

bool OCLinklist::DeleteNode(void){
    if(head->pnext == head){
        cout << "队列已空！" << endl;
        return false;
    }
    Node *p;
    p = head->pnext;
    head->pnext = p->pnext;
    if (p->pnext == head){
        trail = head;
    }
    delete p;
    cout << "删除成功！" << endl;
    return true;
}

bool OCLinklist::TravelList(void){
    Node *p = head->pnext;
    while(p != head){
        cout <<p->node_date << endl;
        p = p->pnext;
    }
    cout << "遍历结束！" << endl;
    return false;
}

int main(void){
    Queue my_queue;
    my_queue.AddNumber(1);
    my_queue.AddNumber(2);
    my_queue.AddNumber(3);
    my_queue.AddNumber(4);
    my_queue.AddNumber(5);
    my_queue.AddNumber(6);
    my_queue.TravelQueue();
    my_queue.DeleteNumber();
    my_queue.TravelQueue();
    return 0;
}