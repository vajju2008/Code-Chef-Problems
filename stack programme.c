#include<stdio.h>
#include<process.h>
void push();
void pop();
void peep();
void display();
int main()
{
	int choice;
	do
	{
		printf("\n");
		printf("1.push()\n");
		printf("2.pop()\n");
		printf("3.peep()\n");
		printf("4.display()\n");
		printf("5.exit\n");
		printf("nter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case1:
				push();
				break;
				case2:
					pop();
					break;
					case3:
						peep();
						break;
						case4:
							display();
							break;
							case5:
								exit(0);
								default:
									printf("wrong choice");
		}
	}while(choice>=1&&choice<=5);
}