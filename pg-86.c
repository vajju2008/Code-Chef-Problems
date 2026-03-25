#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,j,num=1;
		scanf("%d",&n);
		for(i=1;i<n;i++)
		{
			for(j=1;j<=2*i-1;j++)
			{
				if(j%2==0)
				printf("*");
				else{
					printf("%d",num);
					num++;
				}
			}
			printf("\n");
		}
	}
	return 0;
}