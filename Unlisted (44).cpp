#include<stdio.h>
int main()
{
int a=4,b=5,c=6,res;
res=(a==b)&&(c>b);
printf("res=%d\n",res);
res=(a==b)&&(c<b);
printf("res=%d\n",res);
res=(a==b)||(c<b);		
printf("res=%d\n",res);
res=!(a==b);
res=!(a!=b);
}
