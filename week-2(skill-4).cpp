#include<stdio.h>
int main()
{
	char a[]="vijju";
	char *p,*q;
	p=&a[0];
	printf("%c",*p);
	p++;
	printf("%c",*p);
	p++;
	printf("%c",*p);
	p++;
	printf("%c",*p);
	p++;
	printf("%c",*p);
	p++;
	printf("%c",*p);
	q=&a[0]+5;
	printf("%c",*q);
	q--;
	printf("%c",*q);
	q--;
	printf("%c",*q);
	q--;
	printf("%c",*q);
	q--;
	printf("%c",*q);
	q--;
	printf("%c",*q);
	return 0;
}