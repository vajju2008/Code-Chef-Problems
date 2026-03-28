/*malloc()*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p;
	int n,i;
	printf("\n enter n value");
	scanf("%d",&n);
	p=(int*)malloc(n*sizeof(int));
	printf("\n malloc memory created");
	for(i=0;i<n;i++);
	{
		p[i]=i+1;
	}
	printf("\n malloc memories are");
	for(i=0;i<n;i++)
	{
		printf("\n%d",p[i]);
	}
}
