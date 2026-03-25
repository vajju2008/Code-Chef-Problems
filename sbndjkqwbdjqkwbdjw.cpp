#include<stdio.h>
int main()
{
	int n,tot;
	printf("enter n value");
	scanf("%d",&n);
	tot=n/12;
	(n<12)?printf("enter 0 value"):printf("%d",tot);
}