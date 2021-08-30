#include <stdio.h>
#include <stdlib.h>

int Searching(int *p, int k, int left, int right);

int main(void)
{
    int array[10]={7, 11, 5, 2, 1, 10, 3, 8, 4, 6};

    printf("%d",Searching(array,2,0,9));

    system("pause");

    return 0;
}

int Searching(int *p, int k, int left, int right)
{
    int i=left, j=right;
    int mid=p[left];

    while(i<j)
    {
        while(p[j]>=mid&&j>i)
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

   if(i-left+1==k)
   {
       return mid;
   }

   if(i-left+1>k)
   {
       return Searching(p, k, left, i-1);
   }

   if(i-left+1<k)
   {
       return Searching(p, k-i-1+left,i+1,right);
   }

}