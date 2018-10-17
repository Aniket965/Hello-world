#include <stdio.h>

int main() 
{
	int arr[]={2,9,7,5,3};
	int i,j;
	for(i=0;i<5;i++)
	{
	    for(j=i+1;j<5;j++)
	    {
	        if(arr[j]<arr[i])
	        {
	            int swap=arr[j];
	            arr[j]=arr[i];
	            arr[i]=swap;
	        }
	    }
	}
	for(i=0;i<5;i++)
	{
	    printf("%d ",arr[i]);
	}
	return 0;
}