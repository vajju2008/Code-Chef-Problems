#include<stdio.h>
int main()
{
	char name[50];
	char id[10];
	char gender;
	char branch[10];
	char phoneno[20];
	float cgpa;
	printf("enter name");
	scanf("%s",name);
	printf("enter id");
	scanf("%s",id);
	printf("enter gender");
	scanf("%c",&gender);
	printf("enter branch");
	scanf("%s",branch);
	printf("enter phoneno");
	scanf("%s",phoneno);
	printf("enter cgpa");
	scanf("%f",&cgpa);
	printf("name%s\n",name);
	printf("id%s\n",id);
	printf("gender%c\n",gender);
	printf("branch%s\n",branch);
	printf("phoneno%s\n",phoneno);
	printf("cgpa%2f\n",cgpa);
}