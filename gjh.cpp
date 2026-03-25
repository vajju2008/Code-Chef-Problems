#include<stdio.h>
int main()
{
	int num;
	printf("enter numbersfrom 1 to 8: ");
	scanf("%d",&num);
	switch ( num){
	
		case 1:
			printf("YELLOW");
			break;
			
		case 2:
			printf("BLUE");
			break;
			
		case 3:
			printf("GREEN");
			break;
			
		case 4:
			printf("PINK");
			break;
			
		case 5:
			printf("PURPLE");
			break;
			
			case 6:
				printf("BLACK");
				break;
				
				case 7:
					printf("RED");
					break;
					
					case 8:
						printf("WHITE");
						break;
						
						default :
							printf("INVALID");}
							
							return 0;
}