#include <stdio.h>

//获取一个数的逆序数
void reverseNumber(int N);

int main(void){
    reverseNumber(123);
    return 0;
}

void reverseNumber(int N)
{
    if (N < 0)
    {
        printf("输入数据不符合要求！");
        return;
    }

    int tempNum = 0;
    int n = N;
    while(N > 0)
    {
        tempNum = tempNum*10 + N % 10;
        N /= 10;
    }

    if (n == tempNum){
        printf("这是一个回文数。\n");

    }
    else{
        printf("这不是一个回文数。\n");
    }
}