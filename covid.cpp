#include <stdio.h>
int main()
{
	long int idnumber;
	char gender;
	char branch[5];
	char mobileno[11];
	float cgpa;
printf("enter the id number");
scanf("%ld",&idnumber);
printf("enter the deparment branch");
scanf("%s",branch);
printf("enter the gender");
scanf("%c",&gender);
printf("enter the phone number");
scanf ("%s",mobileno);
printf("enter the intermediate cgpa");
scanf("%f",&cgpa);
 printf("id number:%ld\n",idnumber);
 printf("gender%c\n",gender);
 printf("branch%s\n",branch);
 printf("mobileno:%s\n",mobileno);
 printf("cgpa:%f\n",cgpa);
 return 0;
} 