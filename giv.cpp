#include<stdio.h>
void fact(int);
int main()
{
	int n;
	scanf("%d",&n);
	fact(n);
}
void fact(int n)
{
	int fact=1;
	int i;
	for(i=1;i<=n;i++)
	{
		fact*=i;
}
printf("%d",fact);
}