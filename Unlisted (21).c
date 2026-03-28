#include <stdio.h>
int main()
{
	int empid;
	char name[50];
	float salary;
	char gender[50];
	printf("enter the employee id");
	scanf("%d",&empid);                                                                                                              
	printf("enter the employee name");
	scanf("%s",&name);
	printf("enter the salary");
	scanf("%f",&salary);
	printf("enter the gender ofemployee");
	scanf("%s",&gender);
	printf("\n*********************");
	printf("\n---------------------");
	printf("\n***employeedetails****");
	printf("\nemployee id\t %d",empid);
	printf("\nemployee name\t %s",name);
	printf("\nsalary \t %f",salary);
	printf("\ngender ofemployee\t %s",gender);
	return 0;
}