#include<stdio.h>
int main()
{
	int age;
	printf("enter age");
	scanf("%d",&age);
	if(age>=25||age==18){
		printf("voting age");
	}
	else{
		printf("not voting age");
	}
}