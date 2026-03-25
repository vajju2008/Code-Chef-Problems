#include<stdio.h>
int main(){
	introws=5,i,j,k;
	for(j=0;i<rows;i++){
		for(j=0;j<2*(rows-i)-1;j++){
			print(" ");
		}
		for(k=0;k<=i;k++){
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
