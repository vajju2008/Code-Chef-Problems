#include<stdio.h>
int main()
{
	int a,b,x;
	double c,d,y;
	printf("enter a,b,c,d");
	scanf("%d%d%lf%lf",&a,&b,&c,&d);
	x=a+b;
	y=c+d;
	printf("x=%d\ny=%lf",x,y);
return 0;
}