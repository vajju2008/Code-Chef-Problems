#include<stdio.h>
int main()
{
	int a,b;
	printf("enter a,b");
	scanf("%d%d",&a,&b);
	printf("the values before swaping %d\n %d\n",a,b);
	a=a^b;
	b=a^b;
	a=a^b;
	printf("the values after swaping %d\n %d\n",a,b);
	return 0;
}