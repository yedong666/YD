#include <iostream>
#include "LinkList.h"
using std::cout;
using std::endl;
using std::cin;
LinkList::LinkList(){
    HeadNode1 = NULL;
    HeadNode2 = NULL;
    NumNode = 0;
}
void LinkList::Create_OneWay_LinkList(){
    if(HeadNode1||HeadNode2){
        cout << "The linklist has been created!" << endl;
        return;
    }
    iflag = 1;
    OneWayNode *ptemp, *p;
    HeadNode1 = new OneWayNode;
    ptemp = HeadNode1;
    cout << "Please input your linklist date:" << endl;
    do{
        char ch_date;
        cin >> ch_date;
        if(ch_date == '#'){
            //输入‘#’时结束
            break;
        }
        NumNode++;
        p = new OneWayNode;
        p->NodeDate.Nodedate = ch_date;
        p->NodeDate.number = NumNode;
        p->pnext = NULL;
        ptemp -> pnext = p;
        ptemp = p;
        //保存p
    } while(1);
    return;
}
void LinkList::Create_BothWay_Linklist(){
    if(HeadNode1||HeadNode2){
        cout << "The linklist has been created!" << endl;
        return;
    }
    iflag = 2;
    BothWayNode *ptemp, *p;
    HeadNode2 = new BothWayNode;
    ptemp = HeadNode2;
    HeadNode2->pnext = ptemp;
    ptemp->pbefore = NULL;
    cout << "Please input your linklist date:" << endl;
    do{
        char ch_date;
        cin >> ch_date;
        if(ch_date == '#'){
            //输入‘#’时结束
            break;
        }
        NumNode++;
        p = new BothWayNode;
        p->NodeDate.Nodedate = ch_date;
        p->NodeDate.number = NumNode;
        p->pnext = NULL;
        p->pbefore = ptemp;
        ptemp -> pnext = p;
        ptemp = p;
    }while(1);
    return;
}
bool LinkList::Add_Node(char date, int Beforenumber, int Nextnumber ){
    if(!HeadNode1->pnext){
        cout << "Error!" << endl;
        return false;
    }
    if(NumNode<2){
        cout << "Error" << endl;
        return false;
    }
    OneWayNode *ptemp1, *ptemp2, *ptemp3;
    ptemp1 = HeadNode1;
    ptemp2 = ptemp1->pnext;
    ptemp3 = ptemp2->pnext;
    while((ptemp2->NodeDate.number!=Beforenumber||ptemp3->NodeDate.number!=Nextnumber) && ptemp3){
        ptemp2 = ptemp2->pnext;
        ptemp3 = ptemp3->pnext;
    }
    if(!ptemp3){
        cout << "Error!" << endl;
        return false;
    }
    OneWayNode *pnew;
    pnew = new OneWayNode;
    NumNode++;
    pnew->NodeDate.Nodedate = date;
    pnew->NodeDate.number = NumNode;
    ptemp2->pnext = pnew;
    pnew->pnext = ptemp3;
    cout << "Add successfull!" << endl;
    return true;
}
bool LinkList::Delete_Node(int number){
    if(!HeadNode1){
        cout << "Error!" << endl;
        return false;
    }
    OneWayNode *p;
    p= HeadNode1;
    while(p->pnext->NodeDate.number != number && p->pnext){
        p = p->pnext;
    }
    if(!p->pnext){
        cout << "Error!" << endl;
        return false;
    }
    OneWayNode *p1;
    p1= p->pnext->pnext;
    delete p->pnext;
    p->pnext = p1;
}