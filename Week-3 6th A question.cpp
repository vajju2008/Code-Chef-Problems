#include<stdio.h>
int main()
{
	int a=6356736,*intPtr;
	float b=6356732,*floatPtr;
	double c=6353720,*doublePtr;
	intPtr=a;
	floatPtr=b;
	doublePtr=c;
	intPtr=intPtr+3;
	floatPtr=floatPtr+2;
	doublePtr=doublePtr+5;
	printf("intPtr value:%u\n",intPtr);
	printf("floatPtr value:%u\n",floatPtr);
	printf("doublePtr value:%u",doublePtr);
	
	return 0;
}
