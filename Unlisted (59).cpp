#include<stdio.h>
int pow(int,int);
int main()
{
int x,k,res;
scanf("%d%d",&x,&k);
res=pow(x,k);
printf("res=%d",res);
return 0;
}
int pow(int x,int k)
{
if(k==0)
return 1;
else
return x*pow(x,k-1);
}

