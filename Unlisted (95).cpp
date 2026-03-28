#include<stdio.h>
static int p = 0;
void fun() {
	auto int I = 1;
	register char a = 'o';
	p = p+1;
	printf("%d %d %d\n",I,a,p);
	p=3;
	printf("%d %d %d\n",I,a,p);
}
int main() {
	auto int I = 1;
	register char a = 'D';
	p = p+1;
	printf("%d %d %d\n",I,a,p);
	fun();
	printf("%d %d %d\n",I,a,p);
	return 0;
}
