#include<stdio.h>
#include<math.h>
main()
{
	int a,b,c;
	float x1,x2;
	printf("a,b,c\n");
	scanf("%d%d%d",&a,&b,&c);
	x1=-b+sqrt(b*b-4*a*c)/2*a;
	x2=-b-sqrt(b*b-4*a*c)/2*a;
	printf("%f\n%f\n",x1,x2);
	return 0;
}
