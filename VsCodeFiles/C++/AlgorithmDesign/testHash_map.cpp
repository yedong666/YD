#include <iostream>
#include <algorithm>
#include <hash_map>
#include <stack>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> returnArray;
        map<int, int> tempMap;
        char *str = "abcd";
        string s;
        s.copy(str, 3, 0);
        cout << s;
        s[0] = '!';
        cout << s;
        stack<int> stackNode;
        
        for(int i = 0; i < nums.size(); i++){
            cout << nums[i] << " " << i << endl;
            tempMap[nums[i]] = i;
        }
        cout << tempMap.find(2)->second;
        
        for(int i = 0; i < nums.size(); i++){
            if (tempMap.find(target - nums[i]) != tempMap.end()){
                if (tempMap.find(target - nums[i])->second != i){
                    cout << tempMap.find(nums[i])->second;
                    cout << tempMap.find(target - nums[i])->second;
                    returnArray.push_back(tempMap.find(nums[i])->second);
                    returnArray.push_back(tempMap.find(target - nums[i])->second); 
                    break;
                }
            }
        }

        cout << returnArray[0] << " " << returnArray[1];
        
        return returnArray;
}

int main(void){
    // map<int, int> tempMap;
    // vector<int> testArray = {3, 2, 4};
    // twoSum(testArray, 6);
    // char str[3] = {'a', 'b', 'c'};
    string s = "012345";

    
    // s.copy(str, 3, 0);
    // for(int i = 0; i < 3; i++){
    //     cout << str[i];
    // }
    // cout << "\n";
    // string s1 = "abc", s2 = "ac";
    // if (s1 == s2){
    //     cout << "s1 == s2";
    // }else{
    //     cout << "s1 != s2";
    // }
    return 0;
}