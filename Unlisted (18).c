#include<stdio.h>
int main()
{
	float l_cm,l_m,w,h;
	float v,sa;
	printf("\n enter length in meter");
	scanf("%f",&l_m);
	l_cm=l_m*100;
	printf("\n enter width,height");
	scanf("%f%f",&w,&h);
	v=l_cm*w*h;
	sa=2*(l_cm*w+l_cm*h+w*h);
	printf("volume:%f",v);
	printf("surface area:%f",sa);
	return 0;
}
	
	