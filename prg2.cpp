// CProgram to Print Surface Area of Cuboid
#include<stdio.h>
int main()
{
	int L;
	int B;
	int H;
	printf("enter the length\n");
	scanf("%d",&L);
	printf("enter the breadth\n");
	scanf("%d", &B) ;
	printf("enter the height\n");
	scanf("%d",&H);
	int sa=2*(L*B+B*H+H*L);
	printf("Sa  is %d",sa);
	
	return 0;
	
}