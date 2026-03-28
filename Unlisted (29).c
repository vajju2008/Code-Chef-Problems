#include<stdio.h>
main()
{
	int a,b,c; 
	printf("a,b,c\n");
	scanf("%d%d",&a,&b);
	c=a;
	a=b;
	b=c;
	printf("a=%d\nb=%d\n",a,b);
}
