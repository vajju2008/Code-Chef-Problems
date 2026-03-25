#include<stdio.h>
void shellsort (int arr[],int n)
{	
       for(int g=n/2;g>0;g-g/2)
       {
  
  	for(int i=g;i<n;i++)
  {
  	int key=arr[i];
  	int j=i-g;
  	while(j>=0&&arr[j]>key)
  	{
  		arr[j+g]=arr[j];
  		j=j-g;
	  }
	  arr[j+g]=key;
}
}
}
int main( ){
int arr[]={5,2,9,1,5,6};
int n = sizeof(arr) / sizeof(arr[0]);

shellsort(arr,n);
 printf("sorted array: ");
 for (int i=0;i < n ;i++){
 	printf("%d",arr[i]);
 }
   return 0;
}


