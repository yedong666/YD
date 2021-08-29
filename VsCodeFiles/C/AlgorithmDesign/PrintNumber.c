#include <stdio.h>

//此函数可以输出0~9的任意数字
void printNumber(int N);

//此函数仅使用上述printNumber函数输出任意大小的整数包括负数
void printOut(int N);

int main(void)
{
    printOut(456);
    return 0;
}

void printNumber(int N)
{
    if (N > 9 || N < 0)
    {
        printf("此数字无法输出！");
        return;
    }
    else
    {
        printf("%d", N);
    }
}

void printOut(int N){
    if (N < 0)
    {
        printf("-");
        N *= -1;
    }

    if (N > -1 && N < 10)
    {
        printNumber(N);
    }
    else
    {
        printOut(N/10);
        printNumber(N%10);
    }
}

