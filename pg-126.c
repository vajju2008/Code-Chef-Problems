#include<stdio.h>
int main()
{
	int size;
	scanf("%d",&size);
	int a[size],ele,i,flag=0,mid,left,right;
	printf("enter array elements");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter search element");
	scanf("%d",&ele);
	left=0,right=size-1;
	while(left<=right)
	{
		mid=left+(right-left)/2;
		if(a[mid]=ele)
		{
			flag=1;
			break;
		}
		else if(a[mid]<ele)
		{
			left=mid+1;
		}
		else if(a[mid]>ele)
		{
			right=mid-1;
		}
	}
	if(flag==1)
	printf("%d is found at %d in array",ele);
	else
	printf("%d is not found in array",ele);
	return 0;
}