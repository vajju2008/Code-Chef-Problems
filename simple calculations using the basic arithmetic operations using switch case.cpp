#include<stdio.h>
int main(){
	char operator;
	double num1,num2,result;
	
	printf("Enter two numbers:");
	scanf("%lf %lf",&num1,&num2);
	
	switch(operator){
		case='+':
			result=num1+num2;
		printf("%.2lf+%.2lf=%.2lf\n",num1,num2,result);
		break;
		case='-':
			result=num1-num2;
		printf("%.2lf-%.2lf=%.2lf\n",num1,num2,result);
		break;
		case='*':
			result=num1*num2;
		printf("%.2lf*.2lf=%.2lf\n",num1,num2,result);
		break;
		case='/':
			if(num2!=0){
				result=num1/num2;
			printf("%.2lf/%.2lf=%.2lf\n",num1,num2,result);
		printf("Error:Division by zero is not allowed\n");
			}
			break;
	default:
		printf("error:Invalid operation\n");
	}
	return 0;     
}
