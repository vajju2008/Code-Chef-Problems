#include <stdio.h>

int main() {
   int a,b=1;
   scanf("%d",&a);
    int i=1;
    while(a>=1){
    	b=a*b;
    	--a;
	}
	printf("%d",b);
return 0;
}
