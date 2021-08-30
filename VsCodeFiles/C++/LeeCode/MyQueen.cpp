//使用栈来模拟队列
#include <iostream>
#include <stack>
using namespace std;
class MyQueen{
private:
    stack<int> inStack, outStack;   //建立两个栈

    void inTwoOut(){
        while(!inStack.empty()){
            outStack.push(inStack.top());
            inStack.pop();
        }
        //当inStack不为空时，inStack弹出栈顶元素，压入outStack
    }
    //此函数作用为将inStack中的全部元素转移到outSatck
public:
    MyQueen(){}

    void push(int x){
        inStack.push(x);
    }

    int pop(){
        if(outStack.empty()){
            inTwoOut();
        }
        int x=outStack.top();
        outStack.pop();
        return x;
    }

    int peek(){
        if(outStack.empty()){
            inTwoOut();
        }
        return outStack.top();
    }

    bool empty(){
        return inStack.empty() && outStack.empty();
    }

};
int main(void){
    return 0;
}