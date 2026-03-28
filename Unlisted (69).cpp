/*free*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p,n,i;
	printf("\n enter n value");
	scanf("%d",&n);
	p=(int*)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	{
		p[i]=i+1;
	}
	printf("\n calloc memories are");
	for(i=0;i<n;i++)
	{
		printf("\n%d",p[i]);
	}
	free(p);
	printf("\n calloc memory delte");
	for(i=0;i<n;i++)
	{
		printf("\n%d",p[i]);
	}
}
