#include<stdio.h>
void insertionsort(int arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		int key=arr[i];
		int j=i-1;
		while(j>=0&&arr[j]>key)
		{
	        arr[j+1]=arr[j];
	        j=j-1;
		}
		arr[j+1]=key;
	}
}
int main( )
{
	int n;
	printf("enter the numbers of elements\n");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[n]);
	}
	printf("\n before sort \n");
	for(int i=0;i<n;i++)
	{
        printf("%d",arr[i]);
	}
	insertionsort (arr,n);
	printf("\n after sort \n");
	for(int i=0;i<n;i++)
	{
		printf("%d",arr[i]);
	}
}
