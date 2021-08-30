/*给你两个?非空 的链表，表示两个非负的整数。它们每位数字都是按照?逆序?的方式存储的，并且每个节点只能存储?一位?数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0?开头。*/
#include <iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
 };
class Solution {
public:
    struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
        struct ListNode *LTemp, *LSum, *p;
        struct ListNode *p1, *p2;
        p1=l1->next;
        p2=l2->next;
        int x=0;
        LSum = new struct ListNode;
        LTemp = LSum;
        while (p1&&p2) {
            p = new struct ListNode;
            p->val = (p1->val + p2->val + x)%10;
            x = (p1->val+p2->val + x)/10;
            p1 = p1->next;
            p2 = p2->next;
            p->next = NULL;
            LTemp->next = p;
            LTemp = p;
        }
        if (!p1) {
            while (p2) {
            p = new struct ListNode;
            p->val = (p2->val + x)%10;
            x = (p2->val + x)/10;
            p2 = p2->next;
            p->next = NULL;
            LTemp->next=p;
            LTemp = p;
        }
        }
        else if(!p2){
           while (p1) {
            p = new struct ListNode;
            p->val = (p1->val + x)%10;
            x = (p1->val + x)/10;
            p1 = p1->next;
            p->next = NULL;
            LTemp->next=p;
            LTemp = p;
        }
        }
        else{
            ;
        }
        if(x){
            p = new struct ListNode;
            p->val = x;
            p->next=NULL;
            LTemp->next=p;
            LTemp=p;
        }
        return LSum;
    }
};
ListNode *Createlist(void);
void Travelist(ListNode *p);
int main(void)
{
    Solution way1;
    ListNode *p1, *p2, *p3;
    p1 = Createlist();
    p2 = Createlist();
    p3 = way1.addTwoNumbers(p1,p2);
    Travelist(p3);
    return 0;
}
ListNode *Createlist(void){
    ListNode *p1, *p2, *p3;
    int date;
    p1 = new ListNode;
    p2=p1;
    while(1){
        cout << "Please input your list date:" << endl;
        cin >> date;
        if(date == -1){
            break;
        }
        p3 = new ListNode;
        p3->val = date;
        p3->next = NULL;
        p2->next=p3;
        p2=p3;
    }
    return p1;
}
void Travelist(ListNode *p){
    ListNode *px;
    px=p->next;
    while(px){
        cout << px->val;
        px=px->next;
    }
    cout << endl;
}
