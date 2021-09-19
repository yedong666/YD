#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void caculateAve(vector<double> array){
    double sum = 0.0;
    double x = 0.0;
    double g = 0.0;
    for(int i = 0; i < array.size(); i++){
        sum += array[i];
        x += array[i]*array[i];
        g += array[i]*i*2.0;
    }
    double ave = sum / array.size();
    cout << "y平均数：" << ave << endl;
    cout << "y^2平均数：" << x/array.size() << endl;
    cout << "xy平均数：" << g/array.size() << endl;
    double s = 0;
    return;
}

int main(){
    vector<double> array1 = {4.113, 4.198, 4.152, 4.147, 4.166, 4.154, 4.132, 4.170};
    vector<double> array2 = {4.496, 4.504, 4.538, 4.504, 4.498, 4.490};
    vector<double> array3 = {14.34, 16.35, 18.36, 20.34, 22.39, 24.38, 26.33};
    // caculateAve(array1);
    caculateAve(array3);
    return 0;
}