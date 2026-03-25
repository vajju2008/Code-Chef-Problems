#include<stdio.h>
int main()
{
	int size;
	printf("enter array size");
	scanf("%d",&size);
	int a[size],ele,i,flag=0;
	printf("enter array elements");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter search element");
	scanf("%d",&ele);
	for(i=0;i,size;i++)
	{
		if(a[i]==ele)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	printf("%d is found at %d in array",ele);
	else
	printf("%d is not found n array",ele);
	return 0;
}