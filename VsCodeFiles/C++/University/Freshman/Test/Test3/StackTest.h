#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define MAXLEN 100

typedef char Date;
typedef struct Node{
    Date node_date;
    Node *pnext;
}Node;

//创建单链表类
class Linklist{
public:
    Node *head, *trail;
    Linklist();
    bool AddNode(Date newdate);
    bool DeleteNode(void);
};
//顺序栈
class ArrayStack{
private:
    int date[MAXLEN];
    int top;
public:
    ArrayStack();
    bool push_stack(int newdate);
    int pop_stack(void);
    int get_top_date(void);
    bool is_empty(void);
    bool is_full(void);
    int get_top(void);
};
//链栈
class LinkStack{
private:
    Linklist list;
public:
    LinkStack();
    bool push_stack(char newdate);
    int pop_stack(void);
    int get_top_date(void);
    bool is_empty(void);
};


char * ChangeNumber1(int number);
char * ChangeNumber2(int number);    
bool Legalbracket1(char *input);
bool Legalbracket2(char *input);
bool legal_put_array(vector<int> & input_array, vector<int> & put_array);
