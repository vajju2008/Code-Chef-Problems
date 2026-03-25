#include<stdio.h>
int main()
{
	unsigned int num=0;
	printf("enter number");
	scanf("%d",&num);
	if((num&(num-1))==0)
	printf("its an even number\n");
	else
	printf("its an odd number\n");
	return 0;
}