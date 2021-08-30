#include "LinkList.h"
using namespace std;

int main(void){
    // Node *A = new Node, *B = new Node;
    // LinkList listA(A), listB(B);
    // LinkList list;
    // list.Createlist_Tail();
    // list.Travellist();
    // list.Separate_list(listA, listB);
    // list.Travellist();
    // cout << "A:" << endl;
    // listA.Travellist();
    // cout << "B:" << endl;
    // listB.Travellist();
    /*****************************************/
    // Node *p = new Node;
    // LinkList list1, list2, list(p);
    // list1.Createlist_Tail();
    // list2.Createlist_Tail();
    // list1.Travellist();
    // list2.Travellist();
    // list.Public_element(list1,list2);
    // list.Travellist();
    /*****************************************/
    // LinkList list;
    // list.Createlist_Tail();
    // list.Delete_same_element();
    // list.Travellist();
    /*****************************************/
    // LinkList list1, list2;
    // list1.Createlist_Tail();
    // list2.Createlist_Tail();
    // list1.Union_list(list2);
    // list1.Travellist();
    /****************************************/
    LinkList list;
    list.Createlist_Tail();
    list.Search_k_date2(3);
    return 0;
}