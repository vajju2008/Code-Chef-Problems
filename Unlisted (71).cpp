/*realloc()*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p,n,i,n1;
	n=5;
	p=(int*)calloc(n,sizeof(int));
	printf("\n calloc memory create");
	for(i=0;i<n;i++)
	{
		p[i]=i+1;
	}
	printf("\n calloc memories are");
	for(i=0;i<n;i++)
	{
		printf("\n%d",p[i]);
	}
	n1=8;
	p=(int*)realloc(p,n*sizeof(int));
	printf("\n realloc memory created");
	for(i=n;i<n;i++)
	{
		p[i]=i+1;
	}
	printf("\n realloc memories are");
	for(i=n;i<n1;i++)
	{
		printf("\n%d",p[i]);
	}
	printf("\n overall memories");
	for(i=0;i<n1;i++)
	{
		printf("\n%d",p[i]);	
	}
}
