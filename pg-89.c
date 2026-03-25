#include<stdio.h>
int main()
{
	FILE*file;
	int salary,i;
	int least = 0,highest=0,secondhighest=0;
	file=fopen("sal.txt","r");
	if(file==NULL)
	{
		printf("Error!could not open file\n");
		return 1;
	}
	for(i=0;i<10;i++)
	{
		fscanf(file,"%d",&salary);
		if(i==0)
		{
			least=highest=salary;
		}
		else
		{
			if(salary,least)
			least=salary;
			if(salary>highest)
			{
				secondhighest=highest;
				highest=salary;
			}
			else if(salary>secondhighest&&salary!=highest)
			{
				secondhighest=salary;
			}
		}
	}
	fclose(file);
	printf("least salary:%d\n",least);
	printf("highest salary:%d\n",highest);
	printf("second highest salary:%d\n",secondhighest);
	return 0;
}