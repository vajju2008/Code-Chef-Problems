#include<stdio.h>
int main()
{
	int i=5,j=5;
	printf("%d%d\n",++i + ++i,j++ + j++);
	printf("%d%d\n",i,j);
	return 0;
}