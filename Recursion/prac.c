#include<stdio.h>

struct student 
{
int rn;
char name[20];
};

void input(struct student* s)
	{
	printf("\nEnter Roll Number:");
	scanf("%d",&s->rn);
	printf("\nEnter Name:");
	scanf("%s",s->name);
	}


void display(struct student* s)
	{
	printf("\nRoll Number: %d",s->rn);
	printf("\nEnter Name: %s",s->name);
	}


int main()
{
struct student s[3];
struct student *p;


for(int i=0;i<3;i++)
	{
	p=&s[i];
	input(p);
	}

for(int i=0;i<3;i++)
	{
	p=&s[i];
	display(p);
	}
	
}
