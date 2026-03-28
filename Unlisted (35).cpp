#include <stdio.h>
int main ()
{
	int a,b,c,high;
	printf("enter a,b,c values");
	scanf("%d%d%d",&a,&b,&c);
	high=(a>b&&c>a);
	printf("mark will win");
	(b>a&&c>b);
	printf("bob will win");
	printf("jack will win");
	printf("high=%d",high);
	return 0;
}
