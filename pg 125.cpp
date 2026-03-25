#include<stdio.h>
int main()
{
	int a[50],n,i,key;
	printf("enter the size of an array");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("enter key to be found\n");
	scanf("%d",key);
	for (i=0;i<n;i++)
	{
		if (a[i]=key)
		{
			printf("%d fount at %d",key,i++);
			return 0;
		}
	}

   printf("%d NOT found",key);
   return 0;
}