#include<stdio.h>
int main(){
	int i=0;
	int number[5];
	int sum[0];
	printf("enter 5 number %s\n");
	for(i=0;i<5;i++){
		printf("number%d",i+1);
		scanf("%d",&number[i]);
		sum+=number[i];
	}
	printf("sum of numbers%d\n",sum);
}