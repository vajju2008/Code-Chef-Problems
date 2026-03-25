 #include<stdio.h>
int a[10],top=-1,max=10;
main(){
	int ch;
	while(1)
	{
printf("enter 1 for push\n");
printf("enter 2 for pop\n");
printf("enter 3 for display\n");
printf("enter 4 for peek\n");
printf("enter other than other 1,2,3,4 for exit\n");
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
	case 1:push();
	break;
	case 2:pop()
	break;
	case 3:display()
	break;
	case 4:peek()
	break;
	default:exit(1);
}
}
} 
push()
{
	int n;
	printf("enter n");
	scanf("%d,&n");
	if(top==max-1){
		printf("stack is full");
	}
	else{
		top++;
		a[top]=n;
	}
}
pop()
{
	if(top==-1){
	printf(" stack is empty");
}
else
{
	printf("deleted items is %d",a[10]);
	top--;
}
}
display()
{
	int i;
	if(top==-1)
	{
		printf("cannot display");
	}
	else{
		for(i=top;i>=0;i--)
		{
			printf("%d\t",a[i]);
		}
		
	}
		}
		peek()
		{
			printf("%d\n",a[top]);
		}
}
	


 