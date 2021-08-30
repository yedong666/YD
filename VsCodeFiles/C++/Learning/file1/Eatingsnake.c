#include <stdio.h>
#include <stdlib.h>

int a_size = 51;
int b_size = 25;

void Map(void);
void Snakebody(void);

int main(void)
{
    Map();
    system("pause");
    return 0;
}

void Map(void)
{
    int i, j;
    for(j=0;j<b_size;j++)
    {
        for(i=0;i<a_size;i++)
        {   
            if(j!=0&&j!=b_size-1)
        {
            if(i==0||i==a_size-1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }

        else
        {
            if(i%2==0)
            printf("#");
            else
            {
                printf(" ");/* code */
            }
            
        }
            
        }
        printf("\n");
    }
}