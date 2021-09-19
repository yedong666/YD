#include "StackTest.h"
using namespace std;

//顺序栈初始化
ArrayStack::ArrayStack(){
    top = 0;
}
//顺序栈入栈
bool ArrayStack::push_stack(int newdate){
    if(top == MAXLEN){
        cout << "栈已满！" << endl;
        return false;
    }
    date[top++] = newdate;
    return true;
}
//顺序栈出栈
int ArrayStack::pop_stack(void){
    if (top == 0){
        cout << "栈为空！" << endl;
        return -1;
    }
    top--;
    return date[top];
}
//顺序栈获取栈顶数据
int ArrayStack::get_top_date(void){
    return date[top-1];
}
//判断顺序栈是否为空
bool ArrayStack::is_empty(void){
    if (top == 0){
        return true;
    }
    return false;
}
//判断顺序栈是否已满
bool ArrayStack::is_full(void){
    if (top == MAXLEN){
        return true;
    }
    return false;
}
//获取栈高度
int ArrayStack::get_top(void){
    return top;
}
//单链表构造
Linklist::Linklist(){
    head = new Node;
    head->pnext = NULL;
}
//单链表头插新结点
bool Linklist::AddNode(Date newdate){
    Node *newnode = new Node;
    newnode->node_date = newdate;
    newnode->pnext = head->pnext;
    head->pnext = newnode;
    cout << "添加成功！" << endl;
    return true;
}
//单链表删除第一个结点
bool Linklist::DeleteNode(void){
    if(head->pnext == NULL){
        cout << "栈已空！" << endl;
        return false;
    }
    Node *p;
    p = head->pnext;
    head->pnext = p->pnext;
    delete p;
    cout << "删除成功！" << endl;
    return true;
}
//链栈初始化
LinkStack::LinkStack() {}
//链栈入栈
bool LinkStack::push_stack(char newdate){
    list.AddNode(newdate);
    return true;
}
//链栈出栈
int LinkStack::pop_stack(void){
    int temp = list.head->pnext->node_date;
    list.DeleteNode();
    return temp;
}
//判断链栈是否为空
bool LinkStack::is_empty(void){
    if (list.head->pnext == NULL){
        return true;
    }
    else{
        return false;
    }
}
//获取链栈栈顶数据
int LinkStack::get_top_date(void){
    return list.head->pnext->node_date;
}
//将十进制数转化为十六进制数（字符串形式）
char * ChangeNumber1(int number){
    ArrayStack stack;
    char *str = new char[20];
    int temp;
    int i = 0;
    while(number!=0){
        stack.push_stack(number % 16);
        number /= 16;
    }
    while(!stack.is_empty()){
        temp = stack.pop_stack();
        if (temp < 9){
            str[i] = '0' + temp;
        }
        else{
            str[i] = 'A'+(temp-10);
        }
        i++;
    }
    str[i] = '\0';
    return str;
}

char * ChangeNumber2(int number){
    LinkStack stack;
    char *str = new char[20];
    int temp;
    int i = 0;
    while(number!=0){
        stack.push_stack(number % 16);
        number /= 16;
    }
    while(!stack.is_empty()){
        temp = stack.pop_stack();
        if (temp < 9){
            str[i] = '0' + temp;
        }
        else{
            str[i] = 'A'+(temp-10);
        }
        i++;
    }
    str[i] = '\0';
    return str;
}
//判断一个数学表达式中括号是否合法
bool Legalbracket1(char *input){
    vector<char> str(100);
    char ch;
    int i = 0, j = 0;
    while(input[i] != '\0'){
        ch = input[i++];
        if (ch == '{' || ch == '[' ||ch == '('){
            str[j] = ch;
            j++;
        }
        else if(ch == '}' || ch == ']' ||ch == ')'){
            if (ch-str[j-1] < 3 && ch - str[j-1] > -3){
                j--;
            }
            else {
                str[j++] = ch;
            }
        }
        else {}
    }
    if (j==0){
        cout << "输入表达式中括号合法！" << endl;
        return true;
    }
    else{
        cout << "输入表达式中括号不合法！" << endl;
        return false;
    }
}

bool Legalbracket2(char *input){
    LinkStack listStack;
    char ch;
    int i = 0;
    while(input[i] != '\0'){
        ch = input[i++];
        if (ch == '{' || ch == '[' ||ch == '('){
           listStack.push_stack(ch);
        }
        else if(ch == '}' || ch == ']' ||ch == ')'){
            if (ch-listStack.get_top_date() < 3 && ch - listStack.get_top_date() > -3){
               listStack.pop_stack();
            }
            else {
                listStack.push_stack(ch);
            }
        }
        else {}
    }
    if (listStack.is_empty()){
        cout << "输入表达式中括号合法！" << endl;
        return true;
    }
    else{
        cout << "输入表达式中括号不合法！" << endl;
        return false;
    }
}
//判断序列是否为栈的合法输出序列
bool legal_put_array(vector<int> & input_array, vector<int> & put_array){
    ArrayStack stack;
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
        cout << "合法！" << endl;
        return true;
    }
    cout << "不合法！" << endl;
    return false;
}

