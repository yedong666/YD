#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE sizeof(struct student)
typedef struct student
{
    char name[10];
    int number;
    float score;
    struct student *pnext;
}STU;
STU* Creatlist(void);
void Travellist(STU *p);
void Listresort(STU *P);

int main(void)
{
    STU *ps;
    ps=Creatlist();
    printf("The list that without resort is :\n");
    Travellist(ps);
    Listresort(ps);
    printf("The list by resorting is :\n");
    Travellist(ps);
    return 0;
}

STU* Creatlist(void)
{
    STU *head, *p1, *p2;
    char xname[10];
    int xnumber;
    float xscore;
    p1=(STU *)malloc(SIZE);
    if(p1==NULL)
    {
        printf("Failed to allocate memory!");
        exit(-1);
    }
    head=p1;
    head->pnext=p1;
    do
    {
        printf("Please enter number:");
        scanf("%d", &xnumber);
        if(xnumber==-1)
        {
            break;
        }
        getchar();
        printf("Please enter name:");
        gets(xname);
        printf("Please enter score:");
        scanf("%f", &xscore);
        getchar();
        p2=(STU *)malloc(SIZE);
        if(p1==NULL)
        {
            printf("Failed to allocate memory!");
            exit(-1);
        }
        p2->number=xnumber;
        strcpy(p2->name, xname);
        p2->score=xscore;
        p2->pnext=NULL;
        p1->pnext=p2;
        p1=p2;

    } while (1);
    
    return head;
}

void Travellist(STU *p)
{
    STU *x;

    x=p->pnext;

    while(x!=NULL)
    {
        printf("name:%s\n", x->name);
        printf("number:%d\n", x->number);
        printf("score:%.2f\n", x->score);

        x=x->pnext;
    }
    return;
}

void Listresort(STU* p)
{
    STU *x,*z, *t;
    x=p->pnext;
    z=p->pnext;
    t=p->pnext;
    while(x->pnext!=NULL)
    {
        x=x->pnext;
    }
    p->pnext=x;
    while(1)
    {
        for(z;z->pnext!=x;z=z->pnext)
        {
            ;
        }
        x->pnext=z;
        x=z;
        if(x==t)
        {
            t->pnext=NULL;
            break;
        }
        z=t;
    }
    return;

}