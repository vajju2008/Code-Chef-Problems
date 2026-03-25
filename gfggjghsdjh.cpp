#include<stdio.h>
int main()
{
	int x;
	printf("enter x value");
	scanf("%d",&x);
	(x%2!=0)?printf("%d",x+1/2):printf("%d",x/2);
}