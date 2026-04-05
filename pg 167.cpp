#include<stdio.h>
int sum(int);
int main()
{
int n,res;
scanf("%d",&n);
res=sum(n);
printf("sum is %d",res);
return 0;
}
int sum(int n)
{
if(n==0)
return 0;
else
return n*(n+1)/2;
}
