#include<stdio.h>
#include<math.h>
int main()
{
int n,i=3;
float sum =1;
scanf("%d",&n);
for(int i=1;i<n;i++)
{
sum+=pow(i,2)/pow(i,3);
i+=2;
}
printf("%f",sum);
}
