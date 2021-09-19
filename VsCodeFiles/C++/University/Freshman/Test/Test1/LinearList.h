#include <vector>
#define MAXLEN 100    //宏定义线性表储存元素最大个数为MAXLEN(100)
using namespace std;
//定义线性表类
class LinearList{
public:
    LinearList() { length=0; };     //初始化线性表长度为0;
    LinearList(vector<int> & array);
    void Travellist(void);
    int Search_element(int i);
    bool Inseret_node(int i, int x);
    bool Delete_node(int i);
    bool Add_element(int x);
    bool Separate_list(LinearList & A, LinearList & B);
    bool Public_element(LinearList & A, LinearList & B);
    int MidNumber(LinearList & A, LinearList & B);
    bool Delete_same_element(void);
    int date[MAXLEN];
    int length;
};