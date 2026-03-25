#include<stdio.h>
int main()
{
	char s;
	scanf("%c",&s);
	if(s=='R')
	  printf("R-stop!its red signal");
	else if(s=='Y')
	  printf("Y-get ready to move.its yellow signal");
	else if(s=='G')
	  printf("G-go!its green signal");
	else
	  printf("invalid signal input");
	return 0;    
	      
	  
}