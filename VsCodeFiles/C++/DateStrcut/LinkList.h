typedef struct Date{
    char Nodedate;
    int number;
}Date;
//结点数据
typedef struct Nodex{
    Date NodeDate;
    struct Nodex *pnext;
}OneWayNode;
//单向链表结点
typedef struct Nodey{
    Date NodeDate;
    struct Nodey *pnext;
    struct Nodey *pbefore;
}BothWayNode;
//双向链表结点
class LinkList{
private:
    OneWayNode *HeadNode1;  //单向链表头结点
    BothWayNode *HeadNode2; //双向链表头结点
    int NumNode;            //结点数
    int iflag;              //单向链表与双向链表的标志
public:
    LinkList();                         //初始化链表
    void Create_OneWay_LinkList();      //建立单向链表
    void Create_BothWay_Linklist();     //建立双向链表
    bool Add_Node(char date, int Beforenumber, int Nextnumber);           //插入新结点
    bool Delete_Node(int number);       //删除结点
    bool Sort_Link_List();              //对链表进行排序
    Date Search_Node(int number);       //查找结点
    bool TravelLinkList();              //遍历链表
    bool Delete_LinkList();             //删除链表
};