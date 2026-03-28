#include<stdio.h>
int main()
{
	int a,b,c,*p,*q,*r;
	printf("enter the value of a:");
	scanf("%d",&a);
	printf("enter the value of b:");
	scanf("%d",&b);
	p=&a;
	q=&b;
	r=&c;
	*r=*p;
	*p=*q;
	*q=*r;
	printf("Final value of a:%d\n",*p);
	printf("Final value of b:%d",*q);
	return 0;
}
