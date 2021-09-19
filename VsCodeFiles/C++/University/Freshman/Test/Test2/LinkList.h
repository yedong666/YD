#include <iostream>
#include <vector>

//封装链表相关数据类型
typedef int Date;
typedef struct Node{
    Date Nodedate;
    struct Node *pnext;
}Node;

class LinkList{
public:
    Node *Head;
    LinkList();                               //未创建状态
    LinkList(Node *phead);                    //初始化头结点
    void Createlist_Head(void);               //1.头插法创建单链表
    void Createlist_Tail(void);               //2.尾插法创建单链表
    bool DeleteList(void);                    //3.删除链表
    int Getlength(void);                      //4.获取单链表长度
    bool SearchNode_Number(int number);       //5.按编号查找结点(头结点为第0个结点，以此类推)
    bool Front_InsertNode(int number, Date interset_date);  //6.在任意结点之前插入新结点(根据数据域值)
    bool SearchNode_Date(Date search_date);   //7.按值查找
    bool DeleteNode_Number(int number);       //8.按编号删除结点
    bool Insert_date (Date inseret_date);     //9.在递增有序链表中插入新数据，并保持其递增性
    bool Separate_list(LinkList & A, LinkList & B);  //10.将单链表中的奇数数据与偶数数据分别放入新表
    bool Public_element(LinkList & A, LinkList & B); //11.将两递增单链表中的相同数据放入新表
    bool Delete_same_element(void);                  //12.删除递增有序单链表中的相同元素
    bool Union_list(LinkList & newList);             //13.将两链表合并为一个链表，删除其中一个的头结点，且新链表具有集合的性质
    bool Search_k_date2(int k);                      //扩展：查找单链表倒数第k个结点数据
    bool Travellist(void);                    //遍历链表结点数据
    bool Add_node(Date newdate);              //添加新结点(尾插)
    bool DeleteNode_Date(Date search_date);    //删除结点
};