
void bubblsort (int a[50],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	for(j=0;j<n-1;j++)
	{
		if (a[j]>a[j+1])
		{
			temp= a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
	
}
#include<stdio.h>
int main()
{
	int a[50],n,i,j;
	printf("entr the size of an array\n");
	scanf("%d",&n);
	printf("enter array values");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("before socting\n");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
	bubblsort(a,n);
	printf("after sorting\n");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
	return 0;
}