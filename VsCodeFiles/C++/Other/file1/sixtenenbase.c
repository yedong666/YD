#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fun(char *p, unsigned n);

int main(void)
{
    unsigned x;

    char str[8];

    printf("Please input a number:");

    scanf("%x", &x);

    fun(str, x);

    printf("%s", str);

    system("pause");

    return 0;
}

void fun(char *p, unsigned n)
{
    unsigned i=0, k=1;
    char strx[32];

    while(i<32)
    {
        strx[i]=((k&n)>>i) + '0';
        i++;
        k=k<<1;    
    }

    for(i=15;i>7;i--)
    {
        p[15-i]=strx[i];
    }

    p[8]='\0';

    return;
}