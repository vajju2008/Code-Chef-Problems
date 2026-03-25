#include<stdio.h>
intmain()
{
	char name[50];
	char id[65];
	char gender;
	char branch[45];
	char phoneno[67];
	float cgpa;
	printf("enter name");
    scanf("%S",&name);
    printf("enterid");
    scanf("%s",&id);
    printf("enter branch");
    scanf("%s",&branch);
    printf("enter gender");
    scanf("%S",&gender);
    printf("phoneno");
    scanf("%s",&phoneno);
    printf("cgpa");
    scanf("%f",&cgpa);
    printf("name %S\n",name);
    printf("id %s\n",id);
    printf("branch %s\n",branch);
    printf("gender %s\n",gender);
    printf("phoneno %s\n",phoneno);
    printf("cgpa %2f\n",cgpa);
    return 0;
}
