#include<stdio.h>
int main()
{
	unsigned int num=0;
	printf("Enter number");
	scanf("%d",&num);
	if((num&(num-1))==0)
	printf("its an even no\n");
	else
	printf("its an oddmno\n");
	return 0;
}