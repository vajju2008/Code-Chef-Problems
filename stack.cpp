#include<stdio.h>
#define max 10
void push();
void pop();
void peep();
void display();
void push()
{
	int ele,top,stack;
	if(top=max-1)
	{
	printf("stack overflow\n");
}
	else
	{
	printf("enter element\n");
	scanf("%d",&ele);
	top++;
	stack[top]=ele;
}
}
void pop()
{
	int ele;
	if(top==-1)
	{
		printf("stack underflow\n");
	}
	ele
	{
		ele=stack[top];
		printf("%d element is deleted",ele);
		top--;
	}
}
void peep()
{
	if(top==-1)
	{
		printf("stack is underflow\n");
	}
	else
	{
		printf("%d is on top of stack",stack[top]);
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("stack is underflow\n");
	}
	else
	{
		for(i=top;i>0;i--)
		{
			printf("%3d"stack[i]);
		}
	}
}