//合并两个有序链表
//未完成
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
typedef struct Node{
    int date;
    struct Node *pnext;
}ListNode;

class LinkList{
private:
    Node *HeadNode;
public:
    LinkList();
    LinkList(int date);
    void CreateList(void);
    void Travellist(void);
};
LinkList::LinkList() {
    HeadNode = NULL;
}
LinkList::LinkList(int date){
    HeadNode = new ListNode;
    HeadNode->date = date;
    HeadNode->pnext = NULL;
}
void LinkList::CreateList(void){
    if(!HeadNode){
        ListNode *pnew = new ListNode;
        HeadNode = pnew;
        while(true){
            int date;
            cout << "Please input your date:" << endl;
            cin >> date;
            if(!date){
                break;
            }
            ListNode *ptemp = new ListNode;
            ptemp->date = date;
            ptemp->pnext = NULL;
            pnew->pnext = ptemp;
            pnew = ptemp;
        }
    }
}
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    }
};