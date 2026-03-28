#include <stdio.h>
int main()
{
	int code;
	char name[50];
	float price;
	unsigned int quantity;
	char perishable;
	printf("enter the product code");
	scanf("%d",&code);
	printf("enter the product name");
	scanf("%s",&name);
	printf ("enter the product price");
	scanf("%f",&price);
	printf("enter thequantity available");
	scanf("%u",&quantity);
	printf("enter the product is perishable ");
	scanf(" %c",&perishable);
	printf("--------------------");
	printf("\n*****product details****");
	printf("\n-----------------");
	printf("\nproduct code\t %d",code);
	printf("\nproduct name\t %s",name);
	printf("\nproduct price\t %f",price);
	printf("\nquantity available\t%u",quantity);
	printf("\nperishable\t %c",perishable);
	return 0;
}