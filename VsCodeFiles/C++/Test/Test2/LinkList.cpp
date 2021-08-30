#include "LinkList.h"
using namespace std;

LinkList::LinkList() {Head = NULL;}

LinkList::LinkList(Node *phead){
    Head = phead;
    Head->pnext = NULL;
}

void LinkList::Createlist_Head(void){
    if(Head!=NULL){
        cout <<"链表已创建！" << endl;
        return;
    }
    Node *p1, *p2;
    p1 = new Node;
    p1->pnext = NULL;
    Head = p1;
    do{
        Date newdate;
        cout << "Please input your date:" << endl;
        cin >> newdate;
        if (newdate==-1){
            break;
        }
        p2 = new Node;
        p2->Nodedate = newdate;
        if (Head->pnext == NULL){
            p2->pnext = NULL;
        }
        else{
            p2->pnext = p1;
        }
        Head->pnext = p2;
        p1 = p2;
    }while(1);
    return;
}

void LinkList::Createlist_Tail(void){
    if(Head!=NULL){
        cout <<"链表已创建！" << endl;
        return;
    }
    Node *p1, *p2;
    p1 = new Node;
    p1->pnext = NULL;
    Head = p1;
    do{
        Date newdate;
        cout << "Please input your date:" << endl;
        cin >> newdate;
        if (newdate==-1){
            break;
        }
        p2 = new Node;
        p2->Nodedate = newdate;
        p2->pnext = NULL;
        p1->pnext = p2;
        p1 = p2;
    }while(1);
    return;
}

bool LinkList::DeleteList(void){
    Node *p;
    p = Head->pnext;
    while(p!=NULL){
        Node *ptemp = p;
        p = p->pnext;
        delete ptemp;
    }
    cout << "链表已删除！" << endl;
    return true;
}

int LinkList::Getlength(void){
    Node *p = Head->pnext;
    int length = 0;
    while(p!=NULL){
        p = p->pnext;
        length++;
    }
    return length;
}

bool LinkList::SearchNode_Number(int number){
   if(number<0){
        cout << "编号不合法！"  << endl;
        return false;
    }
    if(number==0){
        cout << "头结点不存储数据！" << endl;
        return false;
    }
    int i = 1;
    Node *p;
    p = Head->pnext;
    while(p!=NULL){
        if(number == i){
            cout << "此链表第" << i << "个节点数据为" << p->Nodedate << endl;
            return true;
        }
        else{
            p = p->pnext;
            i++;
        }
    }
    cout << "编号超出范围!" << endl;
    return false;
}

bool LinkList::Front_InsertNode(int number, Date interset_date){
   if(number<0){
        cout << "编号不合法！"  << endl;
        return false;
    }
    if(number==0){
        cout << "无法在头结点之前插入数据！" << endl;
        return false;
    }
    int i = 0;
    Node *p, *ptemp;
    p = Head->pnext;
    ptemp = Head;
    while(p!=NULL){
        if(number == i+1){
            Node *pnew = new Node;
            pnew->Nodedate = interset_date;
            ptemp->pnext = pnew;
            pnew->pnext = p;
            return true;
        }
        else{
            ptemp = p;
            p = p->pnext;
            i++;
        }
    }
    cout << "此链表无第" << number << "个结点！" << endl;
    return false;
}

bool LinkList::SearchNode_Date(Date search_date){
    Node *p;
    int i = 1;
    p = Head->pnext;
    while(p!=NULL){
        if(p->Nodedate == search_date){
            cout << "查找数据在此链表第" << i << "个结点" << endl;
            return true;
        }
        else{
            p = p->pnext;
            i++;
        }
    }
    cout << "未查找到相关数据！" << endl;
    return false;
}

bool LinkList::DeleteNode_Number(int number){
    if(number<0){
        cout << "编号不合法！"  << endl;
        return false;
    }
    if(number==0){
        cout << "此结点为头结点，不能删除！" << endl;
        return false;
    }
    int i = 0;
    Node *p;
    p = Head->pnext;
    while(p!=NULL){
        if(number == i+1){
            Node *ptemp;
            ptemp = p->pnext;
            p->pnext = p->pnext->pnext;
            delete ptemp;
            cout << "已删除此链表第" << number << "个结点" << endl;
            return true;
        }
        else{
            p = p->pnext;
            i++;
        }
    }
    cout << "编号超出范围, 删除失败！" << endl;
    return false;
}

bool LinkList::Insert_date(Date inseret_date){
    Node *p = Head->pnext;
    Node *ptemp = Head;
    while(p!=NULL){
        if(inseret_date <= p->Nodedate){
          break;
        }
        else{
            ptemp = p;
            p = p->pnext;
        }
    }
    Node *pnew = new Node;
    pnew->Nodedate = inseret_date;
    ptemp->pnext = pnew;
    if (p == NULL){
        pnew->pnext = NULL;
    }
    else{
        pnew->pnext = p;
    }
    cout << "插入成功！" << endl;
    return true;
}

bool LinkList::Separate_list(LinkList & A, LinkList & B){
    Node *p = Head->pnext;
    while(p!=NULL){
        if (p->Nodedate %2 == 0){
            A.Add_node(p->Nodedate);
        }
        else{
            B.Add_node(p->Nodedate);
        }
        p = p->pnext;
    }
    cout << "链表元素分离成功！" << endl;
    return true;
}

bool LinkList::Public_element(LinkList & A, LinkList & B){
    Node *pa = A.Head->pnext, *pb = B.Head->pnext;
    while(pa!=NULL && pb!=NULL){
        if (pa->Nodedate == pb->Nodedate){
            this->Add_node(pa->Nodedate);
            pb = pb->pnext;
            pa = pa->pnext;
        }
        else if(pa->Nodedate > pb->Nodedate){
            pb = pb->pnext;
        }
        else{
            pa = pa->pnext;
        }
    }
    return true;
}

bool LinkList::Delete_same_element(void){
    if (Head->pnext == NULL || Head == NULL){
        cout << "此链表为空或未创建!" << endl;
        return false;
    }
    Node *p = Head->pnext;
    Node *ptemp = p->pnext;
    while(ptemp!=NULL){
        if (p->Nodedate == ptemp->Nodedate){
            this->DeleteNode_Date(p->Nodedate);
        }
        p = ptemp;
        ptemp = p->pnext;
    }
    cout << "已删除重复元素！" << endl;
    return true;
}

bool LinkList::Union_list(LinkList & newList){
    Node *p = Head->pnext, *pnew = newList.Head->pnext;
    Node *ptemp1 = p->pnext, *ptemp2 = pnew->pnext;
    while(ptemp1!=NULL&&ptemp2!=NULL){
        if(p->Nodedate == pnew->Nodedate){
            this->DeleteNode_Date(p->Nodedate);
            p = ptemp1;
            ptemp1 = p->pnext;
        }
        else if(p->Nodedate>pnew->Nodedate){
            pnew = ptemp2;
            ptemp2 = p->pnext;
        }
        else{
            p = ptemp1;
            ptemp1 = p->pnext;
        }       
    }
    while(p->pnext!=NULL){
        p = p->pnext;
    }
    p->pnext = newList.Head->pnext;
    delete newList.Head;
    return true;
}

bool LinkList::Search_k_date2(int k){
    Node *p1, *p2;
    int iflag = 0;
    p1 = Head->pnext;
    p2 = p1;
    while(p1->pnext!=NULL){
        p1 = p1->pnext;
        iflag++;
        if(iflag > k-1){        //当p1与p2位置相差k-1个结点时，p2开始移动
            p2 = p2->pnext;     //则当p1到达最后一个结点时，p2所处位置即倒数第k个结点
        }
    }
    if (iflag < k){
        cout << "链表长度小于k" << endl;
        return false;
    }
    else{
        cout << p2->Nodedate << endl;
        return true;
    }
}

bool LinkList::Add_node(Date add_date){
    Node *pnew;
    pnew = new Node;
    pnew->Nodedate = add_date;
    pnew->pnext = NULL;
    Node *p = Head;
    while(p->pnext!=NULL){
        p = p->pnext;
    }
    p->pnext = pnew;
    return true;
}

bool LinkList::DeleteNode_Date(Date search_date){
    Node *p;
    p = Head;
    while(p!=NULL){
        if(p->pnext->Nodedate == search_date){
            Node *ptemp;
            ptemp = p->pnext;
            p->pnext = ptemp->pnext;
            delete ptemp;
            return true;
        }
        else{
            p = p->pnext;
        }
    }
    cout << "未查找到相关数据, 删除失败！" << endl;
    return false;
}

bool LinkList::Travellist(void){
    if (Head==NULL || Head->pnext==NULL){
        cout << "此链表为空或未创建！" << endl;
        return false;
    }
    Node *p;
    p = Head->pnext;
    while(p!=NULL){
        cout << p->Nodedate << endl;
        p = p->pnext;
    }
    return true;
}