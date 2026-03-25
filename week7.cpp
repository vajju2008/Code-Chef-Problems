#include<stdio.h>
int main()
{
	int numbers[]={2,5,8,10,13};
	int size=sizeof(numbers)/sizeof(numbers[0]);
	for (int i=0;i<size;i++)
	{
		numbers[i]=1;
	}
	printf("Modified: ");
	for (int i=0;i<size;i++)
	{
		printf("%d",numbers[i]);
	}
	return 0;
}
