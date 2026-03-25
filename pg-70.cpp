#include<stdio.h>
int main()
{
	int  t,x,y,dist;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&y);
		dist=x*15;
		if(y*2<=dist)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}