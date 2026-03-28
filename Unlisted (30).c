#include<stdio.h>
int main()
{
float m,mm,v,mol,mols;
printf("enter m,mm,v=");
scanf("%f %f %f",&m,&mm,&v);
printf("m=%f\nmm=%f\nv=%f\n",m,mm,v);
mols=m/mm;
mol=mols/v;
printf("mol=%f",mol);
return 0;
}