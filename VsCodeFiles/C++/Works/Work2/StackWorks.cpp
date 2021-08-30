#include <iostream>
#include <algorithm>
#include <vector>
#define MAXLEN 100
using namespace std;
class Stack{
private:
    int date[MAXLEN];
    int top;
public:
    Stack();
    bool push_stack(int newdate);
    int pop_stack(void);
    int get_top_date(void);
    bool is_empty(void);
    bool is_full(void);
    int get_top(void);
};

Stack::Stack() {
    top = 0;
}

bool Stack::push_stack(int newdate){
    if(top == MAXLEN){
        cout << "栈已满！" << endl;
        return false;
    }
    date[top++] = newdate;
    return true;
}

int Stack::pop_stack(void){
    if (top == 0){
        cout << "栈为空！" << endl;
        return -1;
    }
    top--;
    return date[top];
}

int Stack::get_top_date(void){
    return date[top-1];
}

bool Stack::is_empty(void){
    if (top == 0){
        return true;
    }
    return false;
}

bool Stack::is_full(void){
    if (top == MAXLEN){
        return true;
    }
    return false;
}

int Stack::get_top(void){
    return top;
}

bool legal_put_array(vector<int> & input_array, vector<int> & put_array);

int main(void){
    int  input_arrayx[5] = {1,2,3,4,5};
    vector<int> input_array = {1,2,3,4,5};
    vector<int> put_array(5);
    do{
       for(int i = 0; i<5; i++){
            put_array[i] = input_arrayx[i];
        }
        if (legal_put_array(input_array, put_array)){
            for(int j = 0; j<5; j++){
                cout << put_array[j];
            }
            cout << endl;
        }
    }while(next_permutation(input_arrayx, input_arrayx+5));
    return 0;
}

//模拟序列入栈与出栈的过程即可判断输出序列是否合法
bool legal_put_array(vector<int> & input_array, vector<int> & put_array){
    Stack stack;
    int i = 0, j = 0;
    while(i<input_array.size()){
        stack.push_stack(input_array[i++]);           
        while(!stack.is_empty()){
            if (stack.get_top_date() == put_array[j]){
            j++;
            stack.pop_stack();
            }
            else{
                break;
            }
        }
        //判断栈顶元素与待测输出序列当前元素是否相等
        //相等则将将栈顶元素弹出，j指向待测输出序列的下一个元素
        //不相等则继续入栈
        //当输入数据全部入栈，若此次判断过程过后栈不为空，则说明输出序列不合法
        //若为空，则合法
    }
    if (stack.is_empty()){
        //cout << "合法！" << endl;
        return true;
    }
    //cout << "不合法！" << endl;
    return false;
}

