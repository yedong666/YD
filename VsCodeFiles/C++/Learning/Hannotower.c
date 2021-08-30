#include <stdio.h>

void Move(int n, int i, char x, char y);
int Hanoi(int n, char a, char b ,char c);

int i=0;

int main(void)
{
    int n;

    printf("Please enter the number of discs:");
    scanf("%d", &n);
    Hanoi(n, 'a', 'c', 'b');
    printf("\tTotal:%d\n", i);
    return 0;
}

void Move(int n, int i, char x, char y)
{
    printf("%2d-(%2d):%c==>%c\n",i,n,x,y);
}

int Hanoi(int n, char a, char b, char c)
{
    if(n==1)
    {
        i++;
        Move(n, i, a, c);    
    }

    else
    {
        Hanoi(n-1,a, c, b);
        i++;
        Move(n, i, a, c);
        Hanoi(n-1, b, a, c);
    }
    
}