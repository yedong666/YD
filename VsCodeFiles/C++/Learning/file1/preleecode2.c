/*给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include <stdio.h>
#include <stdlib.h>
void Funsum(int *p, int n, int tar, int *x, int *y);

int main(void)
{
    int n_array[10]={2, 7, 14, 15, 56, 32, 9, 10, 13, 41};
    int n_target=27;
    int i, j;

    Funsum(n_array, 10, n_target, &i, &j);
    printf("n_array[%d]+n_array[%d]=%d", i, j, n_target);
    system("pause");

    return 0;
}

void Funsum(int *p, int n, int tar, int *x, int *y)
{
    int i, j;

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i]+p[j]==tar)
            {
                *x=i;
                *y=j;
                return;
            }
        }
    }
}