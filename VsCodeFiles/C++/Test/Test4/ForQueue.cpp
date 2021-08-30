#include <iostream>
#define MAXLEN 5
using namespace std;

class Queue{
private:
    int date[MAXLEN];
    int front;
    int rear;
public:
    Queue();    //初始化队列
    bool IsEmpty(void);     //判断队列是否为空
    bool IsFull(void);      //判断队列是否已满
    bool PushDate(int newdate);     //入队
    int PopDate(void);              //出队
    int GetTopDate(void);           //取队头元素
    int GetDateNum(void);           //求队列中元素个数
    bool PutAllDate(void);          //输出队列中所有元素
};

Queue::Queue(){
    front = 0;
    rear =  1;
    cout << "队列初始化完成！" << endl;
}

bool Queue::IsEmpty(void){
    if ((front+1)%MAXLEN == rear){
        return true;
    }
    return false;
}

bool Queue::IsFull(void){
    if (rear%MAXLEN == front){
        return true;
    }
    return false;
}

bool Queue::PushDate(int newdate){
    if(IsFull()){
        cout << "队列已满！" << endl;
        return false;
    }
    date[rear] = newdate;
    rear = (rear+1)%MAXLEN;
    return true;
}

int Queue::PopDate(void){
    if (IsEmpty()){
        cout << "队列为空！" << endl;
        return false;
    }
    front = (front+1)%MAXLEN;
    return date[front];
}

int Queue::GetTopDate(void){
    return date[front+1];
}

int Queue::GetDateNum(void){
    if (IsEmpty()){
        return 0;
    }
    else return (MAXLEN+(rear-front))%MAXLEN;
}

bool Queue::PutAllDate(void){
    if(IsEmpty()){
        cout << "队列为空！" << endl;
        return false;
    }
    int i = front+1;
    cout << "此时队列中的数据有：" << endl;
    while((i != rear)){
        cout << date[i] <<endl;
        i = (i+1)%MAXLEN;
    }
    return true;
}

bool TestQueue(void){
    Queue testQueue;
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