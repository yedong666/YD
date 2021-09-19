#include <windows.h>
#include <random>
#include <ctime>
#include "Sort.h"
using namespace std;

void PrintArray(vector<int> array){
    for(int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

vector<int> getArray(){
    vector<int> array;
    vector<int> &t = array;
    srand(time(NULL));
    for(long i = 0; i < 100000000; i++){
        array.push_back(rand());
    }
    return t;
}

int main(void){
    vector<int> testArray1 = getArray();
    vector<int> testArray2 = getArray();
    vector<int> testArray3 = getArray();
    vector<int> testArray4 = getArray();
    vector<int> testArray5 = getArray();
    vector<int> testArray6 = getArray();
    vector<int> array = {-1,2,3, 5, 6,4,9,15,10,11,14,13};
    vector<int> array1 = {2, 3, 1, 8, 4, 7, 5, 6, 9};
    vector<int> array3 = {239, 351, 178, 804, 472, 713, 525, 683, 974};
    long finish, start; 

    start = GetTickCount();
    HeapSort(testArray1);
    finish = GetTickCount();
    cout << "堆排序用时：" << finish - start << "ms"<< endl;

    start = GetTickCount();
    QuicklySort(testArray2, 0, testArray2.size() - 1);
    finish = GetTickCount();
    cout << "快速排序用时：" << finish - start << "ms"<< endl;

    start = GetTickCount();
    ShellSort(testArray3);
    finish = GetTickCount();
    cout << "希尔排序用时：" << finish - start << "ms"<< endl;

    start = GetTickCount();
    MergeSort(testArray4, 0, testArray4.size() - 1);
    finish = GetTickCount();
    cout << "归并排序用时：" << finish - start << "ms"<< endl;

    return 0;
}