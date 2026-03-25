#include<stdio.h>
int main()
{
char	ch;
	scanf(" %c",&ch);
	if(ch=='R'){
		printf("stop!its red signal");
		}
		else if(ch=='Y'){
			printf("get ready to move.its yellow signal.");
		}
	else if(ch=='G'){
		printf("GO!its green signal");
	}
	else{
		printf("invalid signal input");
	}	
}