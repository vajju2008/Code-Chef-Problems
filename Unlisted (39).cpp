#include<stdio.h>
int main()
{ 
float amount,tax;
printf("enter transaction amount");
scanf("%f",&amount);
tax=amount*0.18;
printf("amount=%f\n,tax=%.f\n",amount,tax);
return 0;
}