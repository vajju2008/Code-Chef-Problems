#include<stdio.h>
int fib(int n){
	if (n==1){
		return 0;
	}
	if(n==2){
		return 1;
	}
}int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",fib(n));
	return 0;
}
