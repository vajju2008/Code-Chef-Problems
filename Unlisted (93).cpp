#include<stdio.h>
int main() {
	register int n;
	n = 20;
	int*ptr;
	ptr = &n;
	printf("address of n : %u",ptr);
	return 0;
}
