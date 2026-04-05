#include<stdio.h>
int super(int);
int main()
{
int x,res;
scanf("%d",&x);
res=super(x);
printf("super=%d",res);
return 0;
}
int super(int x)
{
int rem,sum=0;
if(x==0)
return 0;
else
rem=x%10;
sum=rem+(x/10);
if(sum>9)
{
x=sum;
sum=super(x);
return sum;
}
}
