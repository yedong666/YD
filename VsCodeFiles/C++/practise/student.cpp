#include<stdio.h>
#include<malloc.h>

void Input(struct student *p,int*toal);//录入学生信息；
void Output(struct student *p,int*toal);//输出录入的学生信息；
void found(struct student *p,int*toal );//按照学号查询学生信息；
void revise(struct student *p,int*toal);//修改某一学号的学生信息；
void sort(struct student *p,int*toal);//按照平均分排序；
void average(struct student *p,int*toal);//计算学生成绩的平均值；
struct student
{
long int ID;
char name[10];
float math_score;
float english_score;
float c_score;
float ave;
}st;//定义结构体；

//******************************************************************************************************************

int main(void)
{
	int total;
	int*toal;
	int i=0,str;
	char ch;
	struct student *p;
	p=&st;
	toal=&total;
	printf("************************************************************************************************\n");
	printf("首先要录入所有的学生信息才能进行进入系统	\n");
	printf("请输入所要录入学生的人数：");
	scanf("%d",&total);
	p=(struct student*)malloc(sizeof(struct student)**toal);
	printf("成功进入系统！\n");

	//**************************************
	printf("现在录入开始\n");
	for(i=0;i<*toal;++i)
	{
		printf("学号：");
			scanf("%d",&p[i].ID);
		printf("姓名：");
			scanf("%s",&(p+i)->name);
		printf("数学成绩：");
			scanf("%f",&(p+i)->math_score);
		printf("英语成绩：");
			scanf("%f",&(p+i)->english_score);
		printf("C语言成绩：");
			scanf("%f",&(p+i)->c_score);
			p[i].ave=(p[i].c_score+p[i].english_score+p[i].math_score)/3;
		printf("第%d名同学录入完成\n",i+1);
		printf("************************************************************************************************\n");
	}
	printf("************************************************************************************************\n");
	ch='a';




	//************************************
		while(ch!='0')
	{
		ch=getchar();

	printf("2.录入学生信息查看\n");
	printf("3.按照学号查询学生信息\n");
	printf("4.修改学生信息\n");
	printf("5.求每个学生的平均成绩\n");
	printf("6.对学生成绩排序\n");
	printf("7.退出\n");
	printf("输入以上数字开启该功能\n");
	printf("************************************************************************************************\n");
	scanf("%d",&str);
	switch(str)
	{
case 2:
		Output(p,toal);
		break;//查看已经录入的所有学生
case 3:
		found(p,toal);
		break;//按照学号查询学生信息
case 4:
		revise(p,toal);
		break;//修改学生信息
case 5:
		average(p,toal);
		break;//求每个学生的平均成绩
case 6:
		sort(p,toal);
		break;//对学生成绩排序
case 7:
		ch='0';
		break;
	}
	printf("按任意键继续。\n");

	}
	printf("谢谢使用！再见！\n");
	getchar();
	getchar();
return 0;
}
void Input(struct student *p,int*toal)//录入学生信息函数
{

	int i;
	printf("现在录入开始\n");
	for(i=0;i<*toal;++i)
	{
		printf("学号：");
		scanf("%d",&p[i].ID);
		printf("姓名：");
			scanf("%s",&(p+i)->name);
		printf("数学成绩：");
			scanf("%f",&(p+i)->math_score);
		printf("英语成绩：");
			scanf("%f",&(p+i)->english_score);
		printf("C语言成绩：");
			scanf("%f",&(p+i)->c_score);
			p[i].ave=(p[i].c_score+p[i].english_score+p[i].math_score)/3;
		printf("第%d名同学录入完成\n",i+1);
		printf("学号：%d	姓名：%s	数学成绩：%.1f	英语成绩: %.1f	c语言成绩:%.1f	平均成绩：%.1f\n",p[i].ID,(p+i)->name,(p+i)->math_score,(p+i)->english_score,(p+i)->c_score,p[i].ave);
	}

}
void Output(struct student *p,int*toal)//输出学生信息函数
{
	int i;
printf("以下是录入%d个同学的个人信息和成绩\n", *toal);
for(i=0;i<*toal;++i)
{
	printf("学号：%d	姓名：%s	数学成绩：%.1f	英语成绩: %.1f	c语言成绩:%.1f	平均成绩：%.1f\n",p[i].ID,(p+i)->name,(p+i)->math_score,(p+i)->english_score,(p+i)->c_score,(((p+i)->math_score+(p+i)->english_score+(p+i)->c_score)/3));
}

}

void found(struct student *p,int*toal )
{
	long int n,h;
	//long int*f;
	int j,count=0;
	//f=&n;

	printf("请输入您所要查询的学号：\n");
		scanf("%d",&n);
		for(j=0;j<*toal;++j)
		{	h=p[j].ID;
			if(n==h)
			{
				printf("学号：%d	姓名：%s	数学成绩：%.1f	英语成绩: %.1f	c语言成绩 %.1f\n",p[j].ID,p[j].name,p[j].math_score,p[j].english_score,p[j].c_score);
				count++;

			}

		}
		if(count==0)
				printf("没有该学生!\n");
}

//************************************************************************************
void revise(struct student *p,int*toal)
{
	long int n,h;

	int j,count=0;
	printf("请输入您所要修改的学号：\n");
		scanf("%d",&n);
		for(j=0;j<*toal;++j)
		{
			if(n==p[j].ID)
			{
				printf("学号：%d	姓名：%s	数学成绩：%.1f	英语成绩: %.1f	c语言成绩:%.1f\n",p[j].ID,p[j].name,p[j].math_score,p[j].english_score,p[j].c_score);
				count++;
				printf("请输入修改后的学生信息：\n");
					printf("学号：");
						scanf("%d",&(p+j)->ID);
					printf("姓名：");
						scanf("%s",&(p+j)->name);
					printf("数学成绩：");
						scanf("%f",&(p+j)->math_score);
					printf("英语成绩：");
						scanf("%f",&(p+j)->english_score);
					printf("C语言成绩：");
						scanf("%f",&(p+j)->c_score);
			printf("修改数据成功！\n");
			printf("修改后的成绩如下：\n");
			printf("学号：%d	姓名：%s	数学成绩：%.1f	英语成绩: %.1f	c语言成绩:%.1f\n",p[j].ID,(p+j)->name,(p+j)->math_score,(p+j)->english_score,(p+j)->c_score);

			}
			if(count==0)
				printf("没有该学生!\n");
		}

}
//***********************************************************************************
void sort(struct student *p,int*toal)//按照平均分排序；
{
	int i,j,k;
	//Output(&st,toal);
	printf("%d位同学的平均分如下（已排序）\n");

	for(i=0;i<*toal;++i)
	{
		for(j=0;j<*toal-i-1;++j)
		{
			if(p[j].ave<=p[j+1].ave)
			{
				st=p[j+1];
				p[j+1]=p[j];
				p[j]=st;
			}
		}

	}

	for(i=0;i<*toal;++i)
{
	printf("第%d名:\n",i+1);
	printf("学号：%d	姓名：%s	数学成绩：%.1f	英语成绩: %.1f	c语言成绩:%.1f	平均成绩：%.1f\n",p[i].ID,(p+i)->name,(p+i)->math_score,(p+i)->english_score,(p+i)->c_score,p[i].ave);

}

}
	void average(struct student *p,int*toal)
	{
	int i;
	for(i=0;i<*toal;++i)
	{
		printf("学号：%d	姓名：%s	平均值：%.3f\n",p[i].ID,p[i].name,p[i].ave);
	}

	}
