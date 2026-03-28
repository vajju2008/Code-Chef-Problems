//reading the input values
#include<stdio.h>
int main()
{
int id;
float sal;
char gen,name[10];
printf("enter id and sal and gen and name");
scanf("%d%f %c%s",&id,&sal,&gen,&name);
printf("\n***********\n");
printf("id=%d\nsal=%f\ngen=%c\nname=%s",id,sal,gen,name);
return 0;
}