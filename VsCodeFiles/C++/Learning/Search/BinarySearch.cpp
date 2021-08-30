#include <iostream>
#include <cstring>
#include <vector>
using std::cout;
using std::endl;

class student{
public:
    int age;
    int grade;
    char name[10];
public: 
    student(int a, int g, const char *n) : age(a), grade(g){
        strcpy(name, n);
    }

    void printData(void){
        cout << "age: " << age <<endl;
        cout << "grade: " << grade << endl;
        cout << "name: " << name << endl;
    }
};

struct cmp{
   int operator()(student A, student B){
       if (A.grade == B.grade){
           return 0;
       }
       else if(A.grade > B.grade){
           return 1;
       }
       else{
           return -1;
       }
   }
};

//二分查找(迭代形式)
template <typename T>bool BinarySearch(std::vector<T> &array, T searchData, cmp c){
    //array中元素按升序排列
    int high = array.size() - 1;
    int low = 0;
    int mid;
    while(high >= low){
        mid = (high + low) / 2;
        if (c(array[mid], searchData) == 0){
            cout << "查找成功！" << endl;
            array[mid].printData();
            return true;
        }
        else if (c(array[mid], searchData) == 1){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout << "查找失败！" << endl;
    return false;
}


//二分查找(递归形式)
template <typename T>
bool BinarySearchR(std::vector<T> &array, T searchData, int high, int low){
    if (high < low){
        return false;
    }
    int mid = (high + low) / 2;
    if (array[mid] == searchData){
        cout << array[mid];
        cout << "查找成功！" << endl;
        return true; 
    }
    else if (array[mid] > searchData){
        BinarySearchR(array, searchData, mid - 1, low);
    }
    else{
        BinarySearchR(array, searchData, high, mid + 1);
    }
    return false;
}

int main(void){
    std::vector<student> array;
    cmp p;
    student stu1(15, 68, "Jack");
    student stu2(14, 76, "Tom");
    student stu3(16, 84, "Amy");
    student stu4(17, 90, "Mike");
    student stu5(15, 99, "Petter");
    array.push_back(stu1);
    array.push_back(stu2);
    array.push_back(stu3);
    array.push_back(stu4);
    array.push_back(stu5);
    BinarySearch<student>(array, stu3, p);
    return 0;
}