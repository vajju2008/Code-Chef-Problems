#include<stdio.h>
int main()

{
	int x,y,z;
	long amt ;
	long choco;
	printf("enter number of 5 rupees coins does chef has:");
	scanf("%d,&x");
	printf("enter number of 10 rupees coins does chef has:");
	scanf("%d,&y");
	printf("prize of chocolate:");
	scanf("%d,&z"); 
	amt=5*x+10*y;
	choco=amt/z;
	printf("maximum number of chocolates that chef can buy for chefina is %l",choco);
	return 0;
	
}
