#include<stdio.h>
int main()
{
	int num;
	scanf("%d",&num);
	if(num%2==0&&num%7==0){
		printf("alice likes");
	}
	else if(num%2==1&&num%9==0){
		printf("bob likes");
	}
	else{
		printf("charlie likes");
	}
}