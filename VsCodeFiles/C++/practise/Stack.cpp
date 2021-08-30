#include <iostream>
using namespace std;

typedef unsigned long Item;

//无符号长整型栈
class Stack
{
    private:
    enum {Max=10};
    Item items[Max];
    int top;

    public:
    Stack()
    {
        top=0;
    }
    bool isempty();                 //判断栈是否为空
    bool isfull();                  //判断栈是否已满
    bool push(const Item & item);   //进栈
    bool pop(Item & item);          //出栈
    void show();
};

bool Stack::isempty()
{
    if(top==0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool Stack::isfull()
{
    if(top==10)
    {
        return true;
    }
    else
    {
       return false;
    }
    
}

bool Stack::push(const Item & item)
{
    if(top<10)
    {
        items[top++]=item;
        return true;
    }
    else
    {
        return false;
    }
    
}

bool Stack::pop(Item & item)
{
    if(top>0)
    {
        item = items[top--];
        return true;
    }
    else
    {
        return false;
    }
    
}

void Stack::show()
{
    for(int i=0;i<top;i++)
    {
        cout << items[i] << " " << endl;
    }
}



int main(void)
{
    Stack stack;
    
    if(stack.isempty())
    {
        Item x;
        cin >> x;
        stack.push(x);
        cout << "Pop successfully" << endl;
    }
    else
    {
        cout << "Stack is full!" << endl;
    }

    stack.show();

    return 0;
}