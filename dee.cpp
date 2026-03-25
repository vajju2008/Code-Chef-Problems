#include<stdio.h>
int main()
{

char name[30];
int id;
char gender[10];
char branch[10];
int number;
float cgpa;
scanf("%s %d %s %s %d %f",name,&id,gender,branch,&number,&cgpa);
printf("%s\n",name);
printf("%5d\n",id);
printf("%s\n",gender);
printf("%s\n",branch);
printf("%3d-%3d-%4d\n",number);
printf("%.2f\n",cgpa);
}
