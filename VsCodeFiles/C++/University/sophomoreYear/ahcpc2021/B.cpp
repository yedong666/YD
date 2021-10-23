#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<vector<int>> array(N);
    for(int i = 0; i < N; i++){
        vector<int> tempArray(N);
        for(int j = 0; j < N; j++){
            int temp;
            cin >> temp;
            tempArray[j] = temp;
        }
        array[i] = tempArray;
    }

    vector<int> queue(N);

    for(int i = 0; i < N; i++){
        int k = 0;
        for(int j = 0; j < N; j++){
            if (array[i][j] == 1){
                k++;
            }
        }
        queue[i] = k + 1;
    }

    for(int i = 0; i < N; i++){
       cout << queue[i] << " ";
    }


    return 0;
}