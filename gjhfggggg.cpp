#include<stdio.h>
int main()
{
	int i;
	int number[5];
	int sum=0;
	float avg;
	printf("enter 5 numbers %s\n");
	for(i=0;i<5;i++)
	{
			printf("number%d",i+1);
		scanf("%d",&number[i]);
		sum+=number[i];
	}
	avg=sum/5.0;
	printf("sum of numbers%d\n",sum);
	printf("average of numbers%.2f\n",avg);
}