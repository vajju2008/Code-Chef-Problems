#include<stdio.h>
int main()
{
	int sum=refunc(10);
	printf("%d",sum);
	return 0;
}
 int refunc(int n)
 {
 	if(n==0)
 	return 0;
 	else
	return n+refunc(n-1);
 }
