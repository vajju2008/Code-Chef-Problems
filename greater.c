#include<stdio.h>
main()
{
	int a,b,c,d,e;
	printf("a,b,c,d,e\n");
	scanf("%d\n%d\n%d\n%d\n%d\n",&a,&b,&c,&d,&e);
	(a>b && a>c && a>d && a>e)?printf("a is greater"):
	(b>a && b>c && b>d && b>e)?printf("b is greater"):
	(c>a && c>b && c>d && c>e)?printf("c is greater"):
	(d>a && d>b && d>c && d>e)?printf("d is greater"):("e is greater");
}
