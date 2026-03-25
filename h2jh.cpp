#include<stdio.h>
int main()
{
	int i,j,row=4;
	for(i=1;i<=row;i++){
		for(j=1;j<=i;j++){
			printf("*");
		}
		printf(" \n");
	}
}