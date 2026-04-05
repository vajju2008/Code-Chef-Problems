#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
int t,i;
{
for(i=1;i<t;i++)
{
int n;
scanf("d",&n);
int height=1;
for(int j=0;j<n;j++)
{
if(j%2==0)
height=2;
else
height++;
}
printf("%d\n",height);
}
}
return 0;
}
