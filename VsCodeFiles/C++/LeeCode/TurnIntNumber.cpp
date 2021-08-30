/*给你一个 32 位的有符号整数 x ，返回 x 中每位上的数字反转后的结果。
如果反转后整数超过 32 位的有符号整数的范围?[?2^31,? 2^31?? 1] ，就返回 0。*/
#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int sum=0;
        while(x!=0){
            sum=sum*10+x%10;
            x/=10;
        }
        if(sum<-2147483648 || sum>2147483647){
            sum=0;
        }
        return sum;
    }
};
int main(void){
    Solution ways1;
    int x;
    x=-123;
    cout << ways1.reverse(x);
    return 0;
}