#include <vector>
#define MAXLEN 100    //宏定义线性表储存元素最大个数为MAXLEN(100)
using namespace std;
//定义线性表类
class LinearList{
public:
    LinearList() { length=0; };     //初始化线性表长度为0;
    LinearList(vector<int> & array);
    int date[MAXLEN];
    int length;
};

//作用函数声明
LinearList & DeleteOrdedAE(LinearList & list);                          //删除有序线性表中的重复元素
LinearList & DeleteAE(LinearList & list);
LinearList & IntersectSet(LinearList & A_list, LinearList & B_list);    //交集运算(无序)
LinearList & UnionSet(LinearList & A_list, LinearList & B_list);        //并集运算(无序)
LinearList & MinusSet(LinearList & A_list, LinearList & B_list);        //减集运算(无序)
LinearList & ordered_IntersectSet(LinearList & A_list, LinearList & B_list);    //交集运算(有序)
LinearList & ordered_UnionSet(LinearList & A_list, LinearList & B_list);        //并集运算(有序)
LinearList & ordered_MinusSet(LinearList & A_list, LinearList & B_list);        //减集运算(有序)
void PutList(LinearList & list);                                        //打印线性表的元素