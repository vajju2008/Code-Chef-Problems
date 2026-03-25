#include<stdio.h>
int main()
{
	int i,j,row=5,num=1;
	for(i=1;i<=row;i++){
		for(j=1;j<=i;j++){
			printf("%c",'A'+j+0);
			//++num;
	}
	printf(" \n");
	}
}