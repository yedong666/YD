//设计算法计算栈的合法输出序列
#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

//简单栈模拟(基于线性表)
class Stack{
private:
    int date[MAX];      
    int top;
public:
    Stack();
    bool isEmpty(void);             //判断栈是否为空
    bool isFull(void);              //判断栈是否已满
    bool pushStack(int newdate);    //入栈
    bool popStack(void);            //出栈
    int getTopDate(void);           //获取栈顶元素
};

//函数实现
Stack::Stack() {
    top = 0;
}

bool Stack::isEmpty(void) {
    return top == 0 ? true : false;
}

bool Stack::isFull(void){
    return top == MAX ? true : false;
}

bool Stack::pushStack(int newdate){
    if (isFull()) {
        cout << "栈已满！" << endl;
        return false;
    }
    date[top++] = newdate;
    return true;
}

bool Stack::popStack(void) {
    if (isEmpty()) {
        cout << "此栈为空！" << endl;
        return false;
    }
    top--;
    return true;
}

int Stack::getTopDate(void) {
    if (isEmpty()) {
        cout << "此栈为空！" << endl;
        return false;
    }
    return date[top-1];
}
/*******************************************************************************************************************/


//判断输出序列是否合法(满足栈的特性)
bool isLegalList(vector<int> enterarray, vector<int> putarray);

int main(void){
    vector<int> array1 = {1, 2, 3, 4, 5};
    vector<int> array2 = {1, 2, 3, 4, 5};
    if (isLegalList(array1, array2)) {
        cout << "输出序列合法！" << endl;
    }
    else {
        cout << "输出序列不合法" << endl;
    }
    return 0;
}

//函数实现
bool isLegalList(vector<int> enterarray, vector<int> putarray){
    Stack testStack;
    int i = 0, j = 0;
    while (i<enterarray.size() && j<putarray.size()){
        testStack.pushStack(enterarray[i++]);
        while(!testStack.isEmpty()){
            if (testStack.getTopDate() == putarray[j]){
                j++;
                testStack.popStack();
            }
            else {
                break;
            }
        }
    }
    if (testStack.isEmpty()){
        return true;
    }
    else {
        return false;
    }
}