#include<stdio.h>
int main()
{
	int empty=0,full=0,i;
	int seats[7]={0,0,0,1,1,1};
	for(int i=0;i<7;i++);
{
	if(seats[i]==0)
	 {
	 empty++;
	 }
	 else
	 {
	 full++;
      }
	printf("empty=%d,full=%d",empty,full);
	return 0;
}
   
