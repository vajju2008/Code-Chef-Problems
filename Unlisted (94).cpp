#include<stdio.h>
void sum() {
	static int a = 10;
	static int b = 24;
	printf("%d %d\n",a,b);
	a=a+1;
	b=b+1;
}
int main() {
	int i;
	sum();
	sum();
	sum();
}
