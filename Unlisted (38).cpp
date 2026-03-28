#include<stdio.h>
int main()
{ 
int code,ava;
char name[10],isava;
float price;
printf("enter code and ava and name and isava and price");
scanf("%d%d%s %c%f",&code,&ava,&name,&isava,&price);
printf("\n details of a product\n");
printf("code=%d\nava=%d\nname=%s\nisava=%c\nprice=%f",code,ava,name,isava,price);
return 0;
}