#include <stdio.h>
#include <math.h>
int main(void)
{
    int x;
    int i;
    for(i=1;;i++){
        if(sqrt(i+100)-(long int)sqrt(i+100)<0.000001 && sqrt(i+268)-(long int)sqrt(i+268)<0.000001)
        {
            printf("%d ", i);
        }
    }
    return 0;
}