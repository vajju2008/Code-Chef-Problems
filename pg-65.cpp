#include<stdio.h>
int main()
{
	int numbersN,M;
	printf("enter value of N");
	scanf("%d", &N);
	printf("enter value of M");
	scanf("%d",&M);
	printf("N left shift 5times:%d\n",N<<5);
	printf("M right shift 2times:%d\n",M>>2);
	return 0;
}