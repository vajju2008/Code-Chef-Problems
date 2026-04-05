#include<stdio.h>
int fun(int n)
{
if
(n==0)
return 0;
if(n>=1)
printf("%d ",n);
return fun(n-1);
}
int fun(int);
int main()
{
int n;
scanf("%d",&n);

fun(n);
}
