#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 10

//求出一组无序数据中的第k大的值
int getMaxFirst(int dataArray[], int k);

int getMaxSecond(int dataArray[], int k);

int main(void)
{
    int testData[MAXLEN] = {3, 1, 5, 2, 6, 9, 7, 4, 8, 0};

    // int kData = getMaxFirst(testData, 1);
    // int i;

    // for(i = 0; i < MAXLEN; i++)
    // {
    //     printf("%d ", testData[i]);
    // }
    // printf("\n%d", kData);

    printf("%d", getMaxSecond(testData, 1));

    return 0;
}

//第一种：对数据进行k次冒泡排序后，根据下标获取
int getMaxFirst(int dataArray[], int k)
{
    int i = 0;
    int j;

    for(i; i < k; i++)
    {
        for(j = 0; j < MAXLEN - 1; j++)
        {
            if (dataArray[j] > dataArray[j+1])
            {
                int tempData = dataArray[j];
                dataArray[j] = dataArray[j+1];
                dataArray[j+1] = tempData;
            }
        }
    }

    return dataArray[MAXLEN - k];
}

//第二种：将数据中的前k个元素转移到数组中，并对之进行排序，此后将所剩数据与该数组中元素比较
//保证该数组中只有k个元素，最后该数组中的最后一个元素即第k大的数
int getMaxSecond(int dataArray[], int k)
{
    int *tempArray = (int *)malloc(k);

    if (!tempArray)
    {
        printf("分配内存失败！");
        system("exit");
    }

    //将dataArray中的前k个数据传入tempArray
    int i = 0;
    for(i; i < k; i++)
    {
        tempArray[i] = dataArray[i];
    }
    int j;
    //并对之进行排序
    for(i = 0; i < k; i++)
    {
        for(j = 0; j < k - 1; j++)
        {
            if (tempArray[j] < tempArray[j+1]){
                int temp = tempArray[j];
                tempArray[j] = tempArray[j+1];
                tempArray[j+1] = temp;
            }
        }
    }

    for(j = k; j < MAXLEN; j++){
        i = k - 1;
        while(i > -1 && tempArray[i] < dataArray[j]){
            if (i > 0 && tempArray[i-1] > dataArray[j])
            {
                tempArray[i] = dataArray[j];
                break;
            }
            else{
                if (i == 0){
                    tempArray[i] = dataArray[j];
                }
                else{
                    tempArray[i] = tempArray[i-1];
                }
            }
        }
    }

    return tempArray[k-1];
}