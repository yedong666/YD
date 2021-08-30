#include <iostream>
#include "LinearList.h"
#define ERROR -1
//函数实现
LinearList::LinearList(vector<int> & array){
    for(int i = 0; i<array.size(); i++){
        date[i] = array[i];
    }
    length = array.size();
}

int LinearList::Search_element(int i){
    if (i>length || i<1){
        cout << "查找的元素不存在或下标越界" << endl;
        return ERROR;
    }
    cout << date[i-1] << endl;
    return date[i-1];
}

bool LinearList::Inseret_node(int i, int x){
    if (i>length || i<1){
        cout << "无此结点！" << endl;
        return false;
    }
    for(int j = length-1; j>i-2; j--){
        date[j+1] = date[j];    //移动第i个结点及其之后的元素
    }
    date[i-1] = x;
    length++;
    cout << "插入成功！" << endl;
    return true;
}

bool LinearList::Delete_node(int i){
    if (i>length || i<1){
        cout << "无此结点！" << endl;
        return false;
    }
    for(int j=i; j<length; j++){
        date[j-1] = date[j];    //移动第i+1个及其之后的元素将第i个元素覆盖
    }
    length--;
    cout << "删除成功！" << endl;
    return true;
} 

bool LinearList::Add_element(int x){
    int i;
    for(i = 0; i<length; i++){
        if(date[i] < x){
            i++;
        }
        else{
            break;
        }
    }
    for(int j = length-1; j>i-1; j--){
        date[j+1] = date[j];
    }
    date[i] = x;
    length++;
    return true;
}

bool LinearList::Separate_list(LinearList & A, LinearList & B){
    int Aflag=0, Bflag=0;
    for(int i = 0; i<length; i++){
        if(date[i]%2 == 0){     //判断奇偶性
            A.date[Aflag++] = date[i];
        }
        else{
            B.date[Bflag++] = date[i];
        }
    }
    A.length = Aflag;
    B.length = Bflag;    
    return true;
}

bool LinearList::Public_element(LinearList & A, LinearList & B){
    int i=0, j=0, k=0;
    while(i<A.length && j<B.length){
        if(A.date[i] == B.date[j]){
            date[k++] = A.date[i];
            i++;
            j++; 
        }
        else if(A.date[i] > B.date[j]){
            j++;
        }
        else{
            i++;
        }
    }
    length = k;
    return true;
}

bool LinearList::Delete_same_element(void){
    if (length<2){
        cout << "线性表无重复元素！" << endl;
        return false;
    }
    int i = 0, j = 0;
    while(j<length){
        if(date[j] != date[j+1]){   //比较当前元素与其之后元素的关系
            date[i++] = date[j];
        }
        j++;
    }
    length = i;
    return true;
}

void LinearList::Travellist(void){
    for(int i = 0; i<length; i++){
        cout << date[i] << " ";
    }
    cout << endl;
    return;
}

int LinearList::MidNumber(LinearList & A, LinearList & B){
    int MidNumberFlag = 0;
    int temp;
    int i = 0, j = 0;
    while(MidNumberFlag != A.length){
        if(A.date[i] > B.date[j]){
            temp = B.date[j];
            j++;
            MidNumberFlag++;
        }
        else{
            temp = A.date[i];
            MidNumberFlag++;
            i++;
        }
    } 
    return temp;
}
/*算法思想：找两个等长升序序列的中位数，若两个序列的长度均为L, 假设把两个序列组合为一个新的序列
那么中位数必然是新序列的第L个位置的数（不是下标为L）。那么为了节省空间与时间，定义MidNumberFlag为中位数位置标志
temp存储当前组合序列（假想出来）的最后一个数，当MidNumber = L 时则说明temp即为新序列的中位数
例子：A = {1, 3, 5}, B = (2, 4, 6), 那么L=3， MidNumberFlag初始值为0;
比较1与2， 1<2, 将MidNumberFlag+1，所以1为组合序列的第MidNumberFlag个元素，(MidNumberFlag此时为1)
比较3与2， 3>2, 将MidNumberFlag+1，所以2为组合序列的第MidNumberFlag个元素，(MidNumberFlag此时为2)
比较3与4, 3<4, 将MidNumberFlag+1，所以3为组合序列的第MidNumberFlag个元素,(MidNumberFlag此时为3)
到此，发现MidNumberFlag = L, 所以3即为两序列的中位数
*/