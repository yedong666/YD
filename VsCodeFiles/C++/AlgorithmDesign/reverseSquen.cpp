#include <iostream>
#include <algorithm>
#include <vector>

/**
 * @brief 判断一个字符串是否为回文字符串
 * */
bool isReverStr(std::string s){
    std::string temps = s;
    std::reverse(s.begin(), s.end());
    return temps == s; 
}

/**
 * @brief 将一个十进制正整数转化为任意进制数的逆序字符串
 * @param k 进制
 **/
std::string turnString(int N, int k){
    std::string str;
    while(N > 0){
        str.push_back(N%k + '0');
        N /= k;
    }
    return str;
}

/**
 * @brief 找出大于10的且十进制八进制二进制数皆为回文数的最小正整数
 * */

int getMinReveNum(void){
    std::string number, binaryNumber, octalNumber;
    std::string temps1, temps2, temps3;
    //二进制为回文数，则其一定为奇数
    for(int i = 11;  ;i += 2){
        number = turnString(i, 10);
        binaryNumber = turnString(i, 2);
        octalNumber = turnString(i, 8);
        temps1 = number;
        temps2 = binaryNumber;
        temps3 = octalNumber;
        std::reverse(number.begin(), number.end());
        std::reverse(binaryNumber.begin(), binaryNumber.end());
        std::reverse(octalNumber.begin(), octalNumber.end());
        if(number == temps1 && binaryNumber == temps2 && temps3 == octalNumber){
            std::cout << number << "    " << binaryNumber << "  " << octalNumber << std::endl;
            return i;
        }
    }
    return -1;
}

int main(void){
    //std::cout << getMinReveNum();
    std::string testStr1 = "abcba";
    std::string testStr2 = "abbad";
    std::cout << isReverStr(testStr1) << std::endl;
    std::cout << isReverStr(testStr2) << std::endl;
    return 0;
}

