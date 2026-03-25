#include<stdio.h>
int main()
{
	char a[10];
	int i;
	printf("enter string\n");
	for(i=0;i<10;i++)
	{
		scanf("%c",&a[i]);
	}
	printf("the string is\n");
	for(i=0;i<10;i++)
	{
		printf("%c",a[i]);
	}
	return 0;
}