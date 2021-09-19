//希尔排序
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
void ShellSort1(vector<int> & array);   //希尔-插入排序
void ShellSort2(vector<int> & array);   //希尔-冒泡排序
void PutArray(vector<int> & array);     //输出数据数据
int main(void){
    vector<int> myarray1 = {-1, 7, 5, 9, 2, 8, 3, 4, 13, 6};
    vector<int> myarray2 = {3, 7, 2, 9, -9, 10, 29, 18, 1, 0};
    cout << myarray1.size() << endl;;
    ShellSort1(myarray1);
    PutArray(myarray1);
    ShellSort2(myarray2);
    PutArray(myarray2);
    return 0;
}
void ShellSort1(vector<int> & array){
    int length = array.size();
    int gap = length / 2;
    int i, j, temp, k;
    k = 0;
   for(gap; gap > 0 ; gap /= 2){                            //改变增量
       for(i = gap; i<length; i++){                         
           j = i;       
           temp = array[j];                                 //保存待插入量
           if(array[j] < array[j-gap]){
               while(j-gap>=0 && temp < array[j-gap]){      //在子序列中寻找合适位置插入待插入量
                   array[j] = array[j-gap];                 //采用子序列后移，找出空位
                   j -= gap;                              
               }
           }
           array[j] = temp;
       }
   }
}

void ShellSort2(vector<int> & array){
    for(int gap = array.size()/2; gap > 0; gap /= 2){
        for(int i = gap; i < array.size(); i++){
            for(int j = i; j - gap >= 0 && array[j] < array[j-gap]; j -= gap){
                int temp = array[j];            //采用交换位置
                array[j] = array[j-gap];       
                array[j-gap] = temp;
            }
        }
    }
}

void PutArray(vector<int> &array){
    for(int i=0; i<array.size(); i++){
        cout << array[i] << " ";
    }
    cout << "\n";
    return;
}
//希尔排序是把记录按下标的一定增量分组，对每组使用直接插入排序算法排序；
//随着增量逐渐减少，每组包含的关键词越来越多，当增量减至 1 时，整个文件恰被分成一组，算法便终止。