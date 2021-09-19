#include <cstdio>
#include <algorithm>
#include "StackTest.h"

int main(void){
    // int num = 112;
    // char *str;
    // str = ChangeNumber2(num);
    // for(int i = 0; str[i]!='\0'; i++){
    //     cout << str[i];
    // }
    // **********************************
    // char input[5] = {'(', ')', '[', ']'};
    // Legalbracket1(input);
    //***********************************
    int  input_arrayx[5] = {1,2,3,4,5};
    vector<int> input_array = {1,2,3,4,5};
    vector<int> put_array(5);
    do{
       for(int i = 0; i<5; i++){
            put_array[i] = input_arrayx[i];
        }
        if (legal_put_array(input_array, put_array)){
            for(int j = 0; j<5; j++){
                cout << put_array[j];
            }
            cout << endl;
        }
    }while(next_permutation(input_arrayx, input_arrayx+5));
    /************************************************************/
    // char str[10] = {'(', ')', '[', ']'};
    // if (Legalbracket2(str)){
    //     cout << "ºÏ·¨£¡";
    // }
     return 0;
}