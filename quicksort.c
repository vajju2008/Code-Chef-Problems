#include<stdio.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a =*b;
	*b =t;
}
int partition(int arr[],int low,int high)
{
	int pivot =high;
	int i=(low);
	int c=low;
	while(c<=high)
	{
	  if(arr[c]==arr[pivot])
	{
		swap(&arr[i],&arr[pivot]);
	 break;
	}
	
	{
		if(arr[c]<arr[pivot])
		{
			swap(&arr[i],&arr[c]);
			i++;
			c++;
		}
		
		c++;
	}
	}
	return(i);
}
  void quicksort(int arr[ ],int low,int high)
  {
  	if(low<high)
  	{
  		int pi=partition(arr,low,high);
  		quicksort(arr,low,pi-1);
  		quicksort(arr,pi+1,high);
  	}
  }
  void printArray (int arr[],int size)
  {
  	int i;
  for(i=0;i<size;i++)
  printf("%d",arr[i]);
  printf("\n");
}
int main ( )
{
	int arr[]={3,2,4,5,7,6};                   
	int n=sizeof(arr)/sizeof(arr[0]);
	quicksort(arr,0,n-1);
	printf("Sorted array:\n");
	return 0;
	
}
	  