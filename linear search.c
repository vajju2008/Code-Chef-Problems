#include<stdio.h>
int main()
{
	int i,n,key;
	scanf("%d%d",&n,&key);
	int a[n];
	int low=0,up=n-1;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	int c=binarysearch(a,low,up,key);
	i./=ntf("found");
	else
	printf("not found");
}
int binarysearch(int a[],int low,int up,int key)
{
if(low>up)
return 0;
int mid=(low+up)/2;	
if(a[mid]==key)
return 1;
if(key<a[mid])
return binarysearch(a,low,mid,key);
else
return binarysearch(a,mid+1,up,key);
}