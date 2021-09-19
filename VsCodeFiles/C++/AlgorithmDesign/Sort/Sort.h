#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

int Pow(int a, int n){
    if (n <= 0){
        return 1;
    }
    else{
        return a * pow(a, n-1);
    }
}

void PrintSpace(int n){
    for(int i = 0; i < Pow(2, n); i++){
        cout << "   ";
    }
}

void PrintHeap(vector<int> array){
    int length = array.size()-1;
    int i = 1;
    int height;
    while(length > pow(2, i) - 1){
        i++;
    }
    height = i;
    int n = i;

    vector<int> temparray;
    queue<int> intQueue;
    intQueue.push(1);
    while(!intQueue.empty()){
        PrintSpace(n-1);
        while(!intQueue.empty()){
            cout << array[intQueue.front()];
            if (array[intQueue.front()] <= 9){
                cout << "**";
            } else if(array[intQueue.front()] <= 99){
                cout << "*";
            }
            for(int i = 0; i < Pow(2, n)-1; i++){
                cout << "   ";
            }

            if (Pow(2, n)-1 == 0){
                cout << "  ";
            }
            int lc = intQueue.front() * 2;
            int rc = lc + 1;
            if (lc <= length)
            temparray.push_back(lc);
            if (rc <= length)
            temparray.push_back(rc);
            intQueue.pop();
        }

        cout << endl;

        for(int i = 0; i < temparray.size(); i++){
            intQueue.push(temparray[i]);
        }

        while(!temparray.empty()){
            temparray.pop_back();
        }
        n--;
    }
}

void QuicklySort(vector<int> &array, int left, int right){
    if (left > right){
        return;
    }
    int l = left;
    int r = right;
    int mid = array[l];

    while(l < r){
        while(l < r && array[r] >= mid){
            r--;
        }
        array[l] = array[r];
        while(l < r && array[l] <= mid){
            l++;
        }
        array[r] = array[l];
    }
    array[l] = mid;
    QuicklySort(array, left, l-1);
    QuicklySort(array, l+1, right);
}

void SpecialQuicklySort(vector<int> &array, int left, int right){
    if (left > right){
        return;
    }
    int l = left;
    int r = right;
    int mid = array[l];

    while(l < r){
        while(l < r && array[r]%3 >= mid%3){
            r--;
        }
        array[l] = array[r];
        while(l < r && array[l]%3 <= mid%3){
            l++;
        }
        array[r] = array[l];
    }
    array[l] = mid;
    QuicklySort(array, left, l-1);
    QuicklySort(array, l+1, right);
}

void ShellSort(vector<int> array){
    int arrayLength = array.size();
    int d = arrayLength / 2;
    while(d > 0){
        for(int i = d; i < arrayLength; i++){
            //对于按步长所分的每一组序列，默认每组序列第一个元素为有序,从第二个元素开始向有序序列中插入
            for(int j = i; j-d > -1 && array[j] < array[j-d]; j -= d){
                //发现待插入元素的前一个元素大于它，就与之交换位置，直到找到合适插入位置
                int temp = array[j];
                array[j] = array[j-d];
                array[j-d] = temp;
            }

        }
        d /= 2;
    }
}

void sift(vector<int> &array, int m, int n){
    int temp = array[m];
    int i = m;
    int j = i * 2;
    while(1){
        //j指向子结点中较大的一个
        if (j < n && array[j] < array[j+1]){
            j += 1;
        }

        //若temp大于两个子节点，则i所指位置即temp应存入位置
        if (j > n || temp >= array[j]){
            array[i] = temp;
            break;
        } 
        else{
            array[i] = array[j];
            i = j;
            j *= 2;
        }

    }

}

void HeapSort(vector<int> &array){
    //cout << "原数据：" << endl;
    //PrintHeap(array);
    for(int i = (array.size()-1)/2; i > 0; i--){
        sift(array, i, array.size()-1);
    }

    //cout << "初始堆：" << endl;
   // PrintHeap(array);

   // cout << "排序过程如下:" << endl;
    for(int j = array.size()-1; j > 1; j--){
        //输出根
        int temp = array[1];
        array[1] = array[j];
        array[j] = temp;
        //cout << "输出根" << temp << "以后的堆：" << endl;
        //PrintHeap(array);
        //输出根后可能数据已不满足堆的特性，需重构
        sift(array, 1, j-1);
        //cout << "重构后的堆：" << endl;
        //PrintHeap(array);
    }
}

const int null = 999;
void TreeSelectSort(vector<int> &array){
   vector<int> tree;
   int length = array.size();
   int height = 0;

    //计算以待排序数据为最后一层的满二叉树的高度
   while(length > Pow(2, height) - 1){
       height++;
   }

   height += 1;

   //构造此满二叉树(空位以null补足)
   int i = 0;
   //补足上层
   while(i < Pow(2, height-1)){
       tree.push_back(null);
       i++;
   }
   //以待排序数据填充最后一层
   while(!array.empty()){
       tree.push_back(array[array.size()-1]);
       array.pop_back();
   }
    //补足最后一层缺少的元素
   while(tree.size() < Pow(2, height)){
       tree.push_back(null);
   }

    cout << "排序过程如下：" << endl;
    while(array.size() != length){
        int n = height;
        while(n != 1){
            for(int i = Pow(2, n-1); i < Pow(2, n); i += 2){
                tree[i/2] = tree[i] < tree[i+1] ? tree[i] :tree[i+1];
            }
            n--;
        }
        PrintHeap(tree);
        cout << endl;
        for(int i = Pow(2, height-1); i < Pow(2, height); i++){
            if (tree[i] == tree[1]){
                array.push_back(tree[i]);
                tree[i] = null;
            }
        }
    }   
}

void RadixSort(vector<int> &array){
    vector<vector<int>> panel;
    int length = array.size();

    while(panel.size() < 10){
        vector<int> temp;
        panel.push_back(temp);
    }

    int n = 1;
    while(n < 1000){
        for(int i = 0; i < length; i++){
            panel[array[i]/n%10].push_back(array[i]);
        }

        int k = 0;

        for(int j = 0; j < 10; j++){
            while(!panel[j].empty()){
                array[k++] = panel[j][panel[j].size()-1];
                panel[j].pop_back();
            }
        }
        n *= 10;       
    }
}

/**
 * @brief 将数组中first到end之间的序列分为两部分，再通过归并形成一段有序序列
 * @param array 操作数组
 * @param first 起点
 * @param end 终点
 **/
void Merge(vector<int> &array, int first, int end){
    int mid = (first + end) / 2;
    //序列A:array[first]到array[mid]
    int a = first;
    //序列B:array[mid+1]到array[end];
    int b = mid + 1;
    //临时数组
    int *tempArray = new int[end - first + 1];

    int i = 0;
    while(a < mid + 1 && b < end + 1){
        if (array[a] < array[b]) {
            tempArray[i++] = array[a++];
        }
        else{
            tempArray[i++] = array[b++];
        }
    }

    while(a < mid + 1) tempArray[i++] = array[a++];
    while(b < end + 1) tempArray[i++] = array[b++];

    for(int j = first; j < end + 1; j++){
        array[j] = tempArray[j-first];
    }

    delete tempArray;
}

void MergeSort(vector<int> &array, int first, int end){
    if (first < end){
        int mid = (first + end) / 2;
        // sort(array.begin(), array.end());
        //对左端序列排序
        MergeSort(array, first, mid);
        //对右边序列排序
        MergeSort(array, mid + 1, end);
        //归并两端序列
        Merge(array, first, end);
    }
}