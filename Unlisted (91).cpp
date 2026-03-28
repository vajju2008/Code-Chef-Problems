#include<stdio.h>
int main ()
{
unsigned int n,i=1;
printf("enter a number");
scanf ("%u",&n);
printf("natural number from to %d\n\n",n);
while(i<=n)
{
printf("\t %u",i);
i++;
}
}

