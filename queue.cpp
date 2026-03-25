#include<stdio.h>
int peek()
{
	if(top>=0){
		int ele =a[top];
		printf("peeked:%d\n",ele);
		return ele;
	}
}
int is empty(){
	return top ==-1;
}
int is full(){
	if (top>=max_size-1){
		return1;
	}else{
		return 0;
	}
}