// c program for employee details
#include<stdio.h>
int main()
{


	int id;
	char name[18];
	float sal;
	char gen;
	printf("enter emp id\n");
	scanf("%d,&id);
	printf("enter emp name\n");
	scanf("%s,&name");
	printf("enter emp sal\n");
	scanf("%f,&sal");
	printf("enter emp gen\n");
	scanf("%c,&gen");
	
	printf("\n id no:%d,id");
	printf("\n name:%c,name");
	printf("\n sal:%f,sal");
	printf("\n gen:%c,gen");
	
return0;
}