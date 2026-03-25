#include<stdio.h>
int main()
{
	int A,B,C,D;
	scanf("%d %d %d",&A,&B,&C);
	D=(B*B-4*A*C);
	if(D<0)
	printf("imaginary");
	else if(D>0)
	printf("real");
	else
	printf("equal");
	return 0;
}