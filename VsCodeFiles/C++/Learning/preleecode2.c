/*给定一种规律 pattern?和一个字符串?str?，判断 str 是否遵循相同的规律。
这里的?遵循?指完全匹配，例如，?pattern?里的每个字母和字符串?str?中的每个非空单词之间存在着双向连接的对应规律。*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char pattern[20], str[20][10], s[200];

    int i, j, k, length, n=0;

    printf("Please enter your pattern:");

    gets(pattern);

    printf("Please input your setence:");

    gets(s);

    length=strlen(pattern);

    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]==' ')
        {
            n++;
        }
    }

    if(length!=(n+1))//若规律字符串字符个数不等于输入字符串单词个数，则不满足
    {
        printf("false");

        exit(0);
    }

    for(i=0;pattern[i]!='\0';i++)
    {
        str[i][0]=pattern[i];
    }

    j=0;

    k=0;

    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]!=' ')
        {
             str[j][1+k]=s[i];

             k++;
        }

        else
        {
            str[j][1+k]='\0';

            j++;

            k=0;
        }
        
    }
//将规律字符串的每个字符与输入字符串对应位置上的单词重新组合为新的字符串
    str[j][k+1]='\0';

    for(i=0;i<length;i++)
    {
        for(j=i+1;j<length;j++)
        {
            if(str[i][0]==str[j][0])
            {

                if(strcmp(str[i], str[j])!=0)
                {
                printf("false");

                exit(0);
                }
            }
        }
    }
//遍历组合而成的所有字符串，若首字符相同而字符串不相等则说明输入字符串不符合规律
    printf("ture");

    return 0;
}