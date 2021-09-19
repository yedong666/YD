#include <iostream>
#include "LinearList.h"

//利用vector给线性表赋值
LinearList::LinearList(vector<int> & array){
    for(int i = 0; i<array.size(); i++){
        date[i] = array[i];
    }
    length = array.size();
}

//函数实现
LinearList & DeleteOrdedAE(LinearList & list){
    int num_flag = 0;           //记录新表元素个数
    for(int i=0; i<list.length; i++){
        if(list.date[i] == list.date[i+1]){
            continue;
        }
        else{
            list.date[num_flag++] = list.date[i];
        }
        //若当前元素与下一个元素相等，则说明该元素重复，跳过该元素
        //当list.date[i]对应的元素不等于下一个元素时说明当前元素已是此”其所属重复线性表的最后一个元素“
        //将其复制到此线性表的下标为num_flag的位置
    }
    list.length = num_flag;
    //将线性表的长度以新表元素个数赋值
    //删除远线性表中重复元素后的新表创建成功
    return list;
}

LinearList & DeleteAE(LinearList & list){
    static LinearList newlist;
    bool Searchflag;
    newlist.date[newlist.length++] = list.date[0];
    for(int i = 1; i<list.length; i++){
        Searchflag = false;
        for(int j=0; j<newlist.length; j++){
            if(list.date[i] == newlist.date[j]){
                Searchflag = true;
                break;
            }
        }
        if(!Searchflag){
            newlist.date[newlist.length++] = list.date[i];
        }
    }
    return newlist;
}

void PutList(LinearList & list){
    for(int i = 0; i<list.length; i++){
        cout << list.date[i] << " ";
    }
    //遍历线性表中元素并将之打印
    cout << endl;
    return;
}

//总结：此算法时间复杂度为O(n);
//其优点为并没有通过移动大量元素来删除元素
//而是对元素中所有值各取一个从线性表头开始覆盖过来，再修改线性表长度；

