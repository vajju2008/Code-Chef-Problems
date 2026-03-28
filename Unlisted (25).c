#include<stdio.h>
int main()
{
	float p,r,s_i;
	int t;
	printf("enter principle amount:");
	scanf("%f",&p);
	printf("enter rate of interest:");
	scanf("%f",&r);
	printf("enter time:");
	scanf("%d",&t);
	s_i=p*r*t/100;
	printf("enter simple interest:%f",s_i);
	return 0;
}