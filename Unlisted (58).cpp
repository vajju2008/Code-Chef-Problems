#include<stdio.h>
int game(int);
int main()
{
int n;
scanf("%d",&n);
game(n);
return 0;
}
int game(int n)
{
if
(n==0)
return 0;
if(n>=1)
printf("%d ",n);
return game(n-1);
}
