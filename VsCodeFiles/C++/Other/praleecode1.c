#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Number(int N, int *p, int *q);
/***************************
 * N代表输入数据
 * p储存数据各个位上的数
 * q储存数据位数
***************************/

int main(void)
{
    int n, a[12], Num;

    int i, Sum=0;

    printf("Please input a positive integer:");

    scanf("%d", &n);

    Number(n, a, &Num);

    i=Num-1;

    while(a[i]<=a[i-1]&&i>0)//判断从最高位到最低位是否严格递增
    {
        i--;
    }

    if(i==0)//说明输入数据本身即为一个递增数
    {
        printf("The biggest increasal integer that less than or equal to %d is %d", n, n);

        exit(0);
    }

    while(a[i]>a[i-1])//找到第一个大于低位的一个位上的数
    {
        a[i]-=1;//将其减去1；

        if(i<Num-1)//判断其减去1后是否仍旧大于其前一位，若改变后小与其前一位，则继续执行该循环
        {
            i++;
        }
    }

    i--;//找到减去1的最高位

    for(i--;i>=0;i--)//该最位后的所有位上的数均赋值位9
    {
        a[i]=9;
    }

    for(i=0;i<Num;i++)
    {
        Sum += a[i]*pow(10, i);//将经计算后的各个位上的数重新组合位所求数
    }

    printf("The biggest increasal integer that less than or equal to %d is %d", n, Sum);

    return 0;
}
//函数原型
void Number(int N, int *p, int *q)
{
    int i=0;

    while(N>0)
    {
        p[i]= N % 10;

        N/=10;

        i++;
    }

    *q = i;
}
//本程序功能：输入一个非负数N，输出一个小于等于该非负数，且从最高位到最低为数字在递增的数Sum
//如输入1000，输出999；输入1554，输出1499；输入1234， 输出1234.