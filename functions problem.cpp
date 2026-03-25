#include<stdio.h>
int add(int,int);
int main()
{
	int a,b,res;
	printf("enter a,b");
	scanf("%d%d",&a,&b);
	res=add(a,b);
	printf("the res is %d",res);
	return 0;
}
int add(int a,int b)
{
	int m;
	m=a+b;
	printf("the add is %d",m);
}