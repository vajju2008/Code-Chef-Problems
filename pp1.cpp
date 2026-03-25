#include<stdio.h>
int main() {
int n,prod=1,rem;
  printf("Enter a number");
  scanf("%d",&n);
  while(n>0)//n!=0
		{
 	rem=n%10;
 	prod=prod*rem;
 	n=n/10;
	}
 printf("prod=%d"\