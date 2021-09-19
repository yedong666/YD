#include <stdio.h>
void Quicklysort(int *p, int left, int right);
int main(void)
{
    int array[10]={2,1,6,3,12,10,7,5,4,8};
    int i;
    Quicklysort(array,0,9);
    for(i=0;i<10;i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
void Quicklysort(int *p,int left, int right)
{
    int i=left, j=right;
    int mid=p[i];
    if(left>=right)
    {
        return;
    }
    while(i<j)
    {
        while(p[j]>=mid&&i<j)
        {
            j--;
        }
        p[i]=p[j];
        while(p[i]<=mid&&i<j)
        {
            i++;
        }
        p[j]=p[i];
    }
    p[i]=mid;
    Quicklysort(p,left,i-1);
    Quicklysort(p,i+1,right);
    return;
}