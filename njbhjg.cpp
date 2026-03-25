#include<stdio.h>
int main()
{
	int a=3,b=5;
	float c=3.2,d=2.3;
	printf("++a%d\n",++a);
	printf("a++%d\n",a++);
	printf("b++ + ++b%d\n",b++ + ++b);
	printf("c++ + ++c+ ++d%f\n",c++ + ++c + ++d);
	return 0;
}