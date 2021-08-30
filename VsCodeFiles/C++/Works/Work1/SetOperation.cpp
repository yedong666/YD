//用线性表模拟集合
//并实现一些相关运算
//集合特点：一个集合内无重复元素, 且元素无序
#include "LinearList.h"

//交集
LinearList & IntersectSet(LinearList & A_list, LinearList & B_list){
    static LinearList C_list;//将局部线性表对象设置为静态， 以便函数结束时该对象占内存不会被回收，下同
    for(int i =0; i<A_list.length; i++){
        for(int j=0; j<B_list.length; j++){
            if(A_list.date[i]==B_list.date[j]){
                C_list.date[C_list.length] = A_list.date[i];
                C_list.length++;
                break;
            }
        }
    }
    return C_list;
}
//分析：时间复杂度为O(n^2)

//并集
LinearList & UnionSet(LinearList & A_list, LinearList & B_list){
    static LinearList C_list;
    int newElementNum = 0;
    bool Searchflag;
    for(int i=0; i<A_list.length; i++){
        C_list.date[i] = A_list.date[i];
    }
    C_list.length = A_list.length;
    for(int j=0; j<B_list.length; j++){             //双循环遍历比较两线性表中的元素
        Searchflag = false;
        for(int i =0; i<C_list.length; i++){
            if(B_list.date[j] == C_list.date[i]){                          
                Searchflag = true;                  //找到，即把搜索标志赋值为true
                break;                              //然后退出此重循环
            }
        }
        if (!Searchflag){
            C_list.date[C_list.length+newElementNum] = B_list.date[j];  //根据搜索标志给新表赋值
            newElementNum++;
        }
    }
    C_list.length += newElementNum;
    return C_list;
}

//分析：时间复杂度为O(n^2)

//减集，A-B，即减去A中与B重复的元素
LinearList & MinusSet(LinearList & A_list, LinearList & B_list){
    static LinearList C_list;
    bool searchFlag;
    int k = 0;
    for(int i = 0; i<A_list.length; i++){
        searchFlag = false;
        for(int j = 0; j<B_list.length; j++){
            if (A_list.date[i] == B_list.date[j]){
                searchFlag = true;
                break;
            }
        }
        if (!searchFlag){
            C_list.date[k] = A_list.date[i];
            k++;
        }
    }
     return C_list;
}
//分析：时间复杂度为O(n^2)
/*******************************************************************************
 *思考：通过对比三个无序集合的相关算法不难发现，总是得不可避免的进行二重循环
 * 或许编写的算法有许多细节可以优化，但思想上总是逃脱不了进行二重循环对比两集合中的元素，
 * 并且每个元素都不得不与另一集合中的所有元素比较一遍
 * 大大浪费了时间
********************************************************************************/

//以下为有序集合的相关算法实现：
//默认有序集合按从小到大排列

//交集
LinearList & ordered_IntersectSet(LinearList & A_list, LinearList & B_list){
    int i = 0, j = 0;
    static LinearList C_list;
    while(i<A_list.length && j<B_list.length){
        if (A_list.date[i] == B_list.date[j]){
            C_list.date[C_list.length++] = A_list.date[i++];
            j++;
        }
        else if(A_list.date[i] > B_list.date[j]){
            j++;
        }
        else{
            i++;
        }
        //因为集合有序，一重循环即可比较完两集合元素
    }
    return C_list;
}

//并集
LinearList & ordered_UnionSet(LinearList & A_list, LinearList & B_list){
      int i = 0, j = 0;
    static LinearList C_list;
    while(i<A_list.length && j<B_list.length){
        if (A_list.date[i] == B_list.date[j]){
            i++;
        }
        else if(A_list.date[i] > B_list.date[j]){
            C_list.date[C_list.length++] = B_list.date[j++];
        }
        else{
            C_list.date[C_list.length++] = A_list.date[i++];
        }
        //因为集合有序，一重循环即可比较完两集合元素
    }
    if (i==A_list.length){
        for(j; j<B_list.length; j++){
            C_list.date[C_list.length++] = B_list.date[j];
        }
    }
    else if(j == B_list.length){
        for(i; i<A_list.length; i++){
            C_list.date[C_list.length++] = A_list.date[i];
        }
    }
    else {}
    return C_list;
}

//减集
LinearList & ordered_MinusSet(LinearList & A_list, LinearList & B_list){
     int i = 0, j = 0;
    static LinearList C_list;
    while(i<A_list.length && j<B_list.length){
        if (A_list.date[i] == B_list.date[j]){
            i++;
            j++;
            continue;
        }
        else if(A_list.date[i] > B_list.date[j]){
           j++;
        }
        else{
            C_list.date[C_list.length++] = A_list.date[i++];
        }
        //因为集合有序，一重循环即可比较完两集合元素
    }
    if (i == A_list.length){
        ;
    }
    else{
        for (i; i<A_list.length; i++){
             C_list.date[C_list.length++] = A_list.date[i];
        }
    }
    return C_list;
}

//分析：时间复杂度皆为O(n^2)

/**************************************************************
*思考： 通过对比有序与无序的集合的相关算法可发现，两者时间复杂度差距极大
*       原因是有序集合不需要遍历整个集合即可得知该元素是否存在于此集合中，
*       因为当遍历到某个位置发现当前元素已经比寻找元素大了，由于线性表中元素是按升序排列
*       所以显然之后的序列中也不存在该元素，即可做出判断
*       而无序集合判断一个元素是否存在，往往得需遍历整个线性表，因为我们永远都不知道
*       该元素是否是存在于线性表的最后一个位置
***************************************************************/
