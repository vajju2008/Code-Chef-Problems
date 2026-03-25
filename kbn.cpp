#include<stdio.h>
int main()
{
	int n,temp,j;
	int a[n];
	printf("enter the element");
	scanf("%d",&n);
	printf("Enter the array");
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
       for(int i=1;i<n;i++)
{
	temp=a[i];
	for(int j=i;j>0&&a[j-1]>temp;j--)
	{
		a[j]=a[j-1];
	}
	a[j]=temp;	
}
}