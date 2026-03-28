#include<stdio.h>

int main()
{
	//?? Primitive Data Types
	int age=21;
	char grade='A';
	float percentage=85.6;
	double pi=3.141592653589;
	
	
	//??Modified Data Types
	short int s=3200;
	unsigned int U=4000000000U;
	long int l=1234567890;
	long double ld=3.1415926358973238L;
	
	//??Output
	printf("===Primitive Data Types===\n");
	printf("int age=%d\n",pi);
	printf("char grade=%c\n",pi);
	printf("float percentage=%.2f\n",percentage);
	printf("double pi=%121f\n",pi);
	//printf("void pointer=%p\n",ptr);
	
	printf("\n===Modified Data Types===\n");
	printf("short int s=%d\n",s);
	printf("unsigned int U=%du\n",l);
	printf("long double ld=%15Lf\n",ld);
	return 0;
}
