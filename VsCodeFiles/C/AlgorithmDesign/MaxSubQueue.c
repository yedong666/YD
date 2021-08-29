#include <stdio.h>

//求出一串数据序列中和最大的子序列
void MaxSubQueue(int testData[], int length);


int main(void)
{
    int testData[10] = {-1, 4, 8, -7, 9, 1, 3, 5, -4, 2};
    MaxSubQueue(testData, 10);
    return 0;
}

void MaxSubQueue(int testData[], int length)
{
    int thisSum = 0;
    int maxSum = 0;
    int start = 0;
    int tempStart = 0;
    int end = 0;

    int i;
    for(i = 0; i < length; i++)
    {
        thisSum += testData[i];

        if (thisSum > maxSum)
        {
            start = tempStart;
            maxSum = thisSum;
            end = i;
        } 
        else if (thisSum < 0)
        {
            tempStart = i + 1;
            thisSum = 0;
        }
    }

    printf("和最大的子序列为：\n");
    for(i = start; i < end + 1; i++)
    {
        printf("%d ", testData[i]);
    }

    printf("\n最大和为：%d", maxSum);
}