#include<stdio.h>
int fun();
int num = 5;
int main() {
	fun();
	printf("\nglobalnum value =%d\n",num);fun();
	printf("\nglobanum value =%d\n",num);fun();
	printf("\nglobanum value =%d\n",num);return 0;
}
int fun() {
	static int num = 2;
	printf("\nstaticnum value = %d\n",num);num=num+1;
	return 0;
}
