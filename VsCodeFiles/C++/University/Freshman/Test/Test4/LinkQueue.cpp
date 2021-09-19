#include <iostream>
using namespace std;

typedef struct Node{
    int date;
    Node *pnext;
}Node;

class LinkQueue{
private:
    Node *head;
    Node *trail;
public:
    LinkQueue();
    bool IsEmpty(void);
    bool PushDate(int newdate);
    int PopDate(void);
    int GetTopDate(void);
    int GetDateNum(void);
    bool PutAllDate(void);
};

LinkQueue::LinkQueue(){
    head = new Node;
    head->date = 0;
    trail = head;
    head->pnext = NULL;
}

bool LinkQueue::IsEmpty(void){
    if (head == trail){
        return true;
    }
    return false;
}

bool LinkQueue::PushDate(int newdate){
    Node *newnode = new Node;
    newnode->date = newdate;
    newnode->pnext = NULL;
    trail->pnext = newnode;
    trail = newnode;
    return true;
}

int LinkQueue::PopDate(void){
    if (IsEmpty()){
        cout << "队列为空！！" << endl;
        return -111111;
    }
    else{
        int tempDate;
        Node *tempNode;
        tempDate = head->pnext->date;
        if (trail == head->pnext){
            trail = head;
        }
        tempNode = head->pnext;
        head->pnext = head->pnext->pnext;
        delete tempNode;
        return tempDate;
    }
}

int LinkQueue::GetTopDate(void){
    if (IsEmpty()){
        cout << "队列为空！！" << endl;
        return -111111;
    }
    return head->pnext->date;
}

int LinkQueue::GetDateNum(void){
    int i = 0;
    Node *temp = head->pnext;
    while(temp != NULL){
        i++;
        temp = temp->pnext;
    }
    return i;
}

bool LinkQueue::PutAllDate(void){
    Node *temp = head->pnext;
    cout << "此时队列中的数据有：" << endl;
    while(temp!=NULL){
        cout << temp->date << endl;
        temp = temp->pnext;
    }
    return true;
}

bool TestQueue(void){
    LinkQueue testQueue;
    int testNum;
    while(1){
        cout << "请输入数据：" << endl;
        cin >> testNum;
        if (testNum == 0){
            break;
        }
        else if(testNum%2 == 0){
            testQueue.PopDate();
        }
        else{
            testQueue.PushDate(testNum);
        }
        testQueue.PutAllDate();
    }
    return true;
}                 

int main(void){
    TestQueue();
    return 0;
}