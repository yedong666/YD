#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE sizeof(Stu)

struct student
{
    int number;

    char name[10];

    float score;

    struct student *pnext;
};

typedef struct student Stu;

Stu * Createlist(void);//生成链表
void Sortlist(Stu *p);//对链表结点按关键数据排序
void Travellist(Stu *p);//遍历链表

int main(void)
{
    Stu *ps;//接受头指针

    ps=Createlist();

    Sortlist(ps);

    Travellist(ps);

    system("pause");

    return 0;
}

Stu* Createlist(void)
{
     Stu *head, *p1, *p2;

     int a;

     char str[10];

     float scr;

     p1=(Stu *)malloc(SIZE);
     if(p1==NULL)
     {
         printf("Failed to allocate memory!");

         exit(-1);
     }

     head=p1;

     head->pnext=p1;

     do
     {
         printf("Please input number:");

         scanf("%d", &a);

         if(a==0)
         {
             break;
         }

         getchar();//空读（读取回车字符，以防程序运行时跳过下一个输出，下同）

         printf("Please input name:");

         scanf("%s", str);

         getchar();//空读

         printf("please input score:");

         scanf("%f", &scr);

         getchar();//空读

         p2=(Stu *)malloc(SIZE);
         if(p2==NULL)
         {
             printf("Failed to allocate memory!");

             exit(-1);
         }

         p2->number=a;

         strcpy(p2->name, str);

         p2->score=scr;

         p2->pnext=NULL;

         p1->pnext=p2;

         p1=p2;
        
     }while(1);

     printf("Create list succesfully!\n");

     return head;
         
}

void Sortlist(Stu *p)
{
    Stu *px, *py, *pt, ps;
    Stu temp, *pa, *pb;

    px=p->pnext;

    if(px==NULL)
    {
        printf("It need' t sort!");

        return;
    }

    for(px;px->pnext!=NULL;px=px->pnext)
    {
        pt=px;
        for(py=px->pnext;py!=NULL;py=py->pnext)
        {
            if(px->score<py->score)
            {
                pt=py;
            }
        }

        if(pt!=px)//在px指向的结点后的结点发现有大于px结点处score的结点
        {
             ps=*pt;//中间量，用于交换两结点数据

             pa=px->pnext;
             pb=pt->pnext;
             //存放两结点指针变量

             *pt=*px;

             pt->pnext=pb;//恢复pt的原指针变量

             *px=ps;

             px->pnext=pa;//恢复px的原指针变量
        }
    }
}
//采用选择排序法对单向链表进行关键数据排序
//核心思想：比较两结点存放的关键数据，满足条件即交换两结点除指针类型数据外的所有数据

void Travellist(Stu *p)
{
    Stu *x;

    x=p->pnext;

    while(x!=NULL)
    {
        printf("Number:%d\t", x->number);
        printf("Name:%s\t", x->name);
        printf("Score:%.2f\n\n", x->score);
        x=x->pnext;
    }
}
//发现问题：vscode不允许C语言标识符中带有下划线