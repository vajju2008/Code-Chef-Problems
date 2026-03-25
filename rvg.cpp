#include<stdio.h>
void insertion(int a[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i;j>0&&a[j-1]>temp;j--)
		{
			a[j]=a[j-1];
		}
		a[j]=temp;
	}
}
int main()
{
	int i,n,a;
	scanf("%d",&a[i]);
	int a[n];
	printf("enter");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
insertion(a,n);
printf("after");
for(i=0;i<n;i++)
{
	print("%d",a[i]);
}
